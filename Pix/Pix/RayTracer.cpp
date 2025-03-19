#include "RayTracer.h"
#include "Camera.h"
#include <math.h>

extern float gResolutionX;
extern float gResolutionY;

namespace
{
	void Fresnel(const Vector3& i, const Vector3& n, float ri, float& kr, float& kt)
	{
		float cosi = X::Math::Clamp(MathHelper::Dot(i, n), -1.0f, 1.0f);
		float etai = 1.0f;
		float etat = ri;
		if (cosi > 0.0f)
		{
			std::swap(etai, etat);
		}
		float sint = etai / etat * sqrtf(std::max(0.0f, 1.0f - cosi * cosi));

		kr = 1.0f;
		if (sint < 1.0f)
		{
			float cost = sqrtf(std::max(0.0f, 1.0f - sint * sint));
			cosi = fabs(cosi);
			float Rs = ((etat * cosi) - (etai * cost)) / ((etat * cosi) + (etai * cost));
			float Rp = ((etai * cosi) - (etat * cost)) / ((etai * cosi) + (etat * cost));
			kr = (Rs * Rs + Rp * Rp) / 2.0f;
		}
		kt = 1.0f - kr;
	}
}

RayTracer* RayTracer::Get()
{
	static RayTracer sInstance;
	return &sInstance;
}
void RayTracer::OnNewFrame()
{
	mObjects.clear();
	mLights.clear();
}
bool RayTracer::BeginDraw()
{
	return true;
}
void RayTracer::AddObject(const Sphere& sphere, const X::Color& color, float ri)
{
	mObjects.push_back({ sphere, color, ri });
}
void RayTracer::AddLight(const Vector3& position, const X::Color& color)
{
	mLights.push_back({ position, color });
}
bool RayTracer::EndDraw()
{
	Camera* camera = Camera::Get(); 
	int columns = static_cast<int>(gResolutionX);
	int rows = static_cast<int>(gResolutionY);

	Matrix4 matViwe = camera->GetViewMatrix();
	Vector3 cameraPos = camera->GetPosition();
	float aspect = gResolutionX / gResolutionY;

	Vector3 screenCenter = cameraPos + camera->GetDirection();
	Vector3 xAxis = { matViwe._11, matViwe._21, matViwe._31 };
	Vector3 yAxis = { matViwe._12, matViwe._22, matViwe._32 };
	Vector3 p0 = screenCenter - (xAxis * aspect) + yAxis;
	Vector3 p1 = screenCenter + (xAxis * aspect) + yAxis;
	Vector3 p2 = screenCenter - (xAxis * aspect) - yAxis;

	for (int y = 0; y < rows; ++y)
	{
		for (int x = 0; x < columns; ++x)
		{
			float u = (float)x / columns; 
			float v = (float)y / rows;
			Vector3 pointOnScreen = p0 + (p1 - p0) * u + (p2 - p0) * v;

			Ray primaryRay;
			primaryRay.origin = cameraPos;
			primaryRay.direction = MathHelper::Normalize(pointOnScreen - cameraPos);
			X::DrawPixel(x, y, Trace(primaryRay, 3));
		}
	}

	return true;
}
X::Color RayTracer::Trace(const Ray& ray, int depth)
{
	if (depth <= 0)
	{
		return X::Colors::Black;
	}

	Object* objHit = nullptr;
	float closestDistance = FLT_MAX;
	X::Color closestColor;
	Vector3 closestPoint;
	Vector3 closestNormal;

	for (Object& obj : mObjects)
	{
		float distanceToSphere = 0.0f;
		if (MathHelper::Intersects(ray, obj.sphere, distanceToSphere))
		{
			if (distanceToSphere >= 0.0f && distanceToSphere < closestDistance)
			{
				objHit = &obj;
				closestDistance = distanceToSphere;
				closestColor = obj.color;
				closestPoint = ray.origin + ray.direction * distanceToSphere;
				closestNormal = MathHelper::Normalize(closestPoint - obj.sphere.origin);


			}
		}
	}

	if (objHit == nullptr)
	{
		return X::Colors::Black;
	}

	X::Color color;
	if (objHit->IsOpaque())
	{
		for (Light& light : mLights)
		{
			float distanceToLight = MathHelper::Magnitude(light.position - closestPoint);
			Vector3 dirToLight = (light.position - closestPoint) / distanceToLight;

			bool occluded = false;
			for (Object& obj : mObjects)
			{
				Ray shadowRay;
				shadowRay.origin = closestPoint + (closestNormal * 0.001f);
				shadowRay.direction = dirToLight;
				float distanceToObj = 0.0f;
				if (MathHelper::Intersects(shadowRay, obj.sphere, distanceToObj))
				{
					if (distanceToObj > 0.0f && distanceToObj + 0.1f < distanceToLight)
					{
						occluded = true;
						break;
					}
				}
			}
			//calcule the final color 
			float intensity = mAmbient;
			if (!occluded)
			{
				float diffuse = MathHelper::Dot(dirToLight, closestNormal);
				if (diffuse > 0.0f)
				{
					float atten = 1.0f / (light.attenC + (light.attenL * distanceToLight)
						+ (light.attenQ * distanceToLight * distanceToLight));
					intensity += X::Math::Clamp(intensity + (diffuse * atten), 0.0f, 1.0f);
				}
			}
			color += light.color * closestColor * intensity;
		}
	}
	else
	{
		bool inside = false;
		if (MathHelper::Dot(ray.direction, closestNormal) > 0.0f)
		{
			inside = true;
			closestNormal = -closestNormal;
		}
		Ray reflectRay;
		reflectRay.origin = closestPoint + (closestNormal * 0.001f);
		reflectRay.direction = ray.direction - (closestNormal * 2.0f * MathHelper::Dot(ray.direction, closestNormal));
		reflectRay.direction = MathHelper::Normalize(reflectRay.direction);
		X::Color reflectColor = Trace(reflectRay, depth - 1);
		
		float eta = inside ? objHit->refractionIndex : 1.0f / objHit->refractionIndex;
		float cosi = -MathHelper::Dot(ray.direction, closestNormal);
		float k = 1.0f - eta * eta * (1.0f - cosi * cosi);

		Ray refractRay;
		refractRay.origin = closestPoint - (closestNormal * 0.001f);
		refractRay.direction = ray.direction * eta + closestNormal * (eta * cosi - sqrt(k));
		refractRay.direction = MathHelper::Normalize(refractRay.direction);
		X::Color refractColor = Trace(refractRay, depth - 1);


		//fresnel calculation
		float kr, kt; 
		Fresnel(ray.direction, closestNormal, objHit->refractionIndex, kr, kt);
		color = closestColor * (reflectColor * kr + refractColor * kt);

	
	}
	color.r = X::Math::Clamp(color.r, 0.0f, 1.0f);
	color.g = X::Math::Clamp(color.g, 0.0f, 1.0f);
	color.b = X::Math::Clamp(color.b, 0.0f, 1.0f);
	color.a = 1.0f;
	return color;
}
