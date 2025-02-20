#include "LightTypes.h"
#include "MaterialManager.h"
#include "Camera.h"

X::Color DirectionalLight::ComputeLightColor(const Vector3& positon, const Vector3& normal) const
{
	Camera* camera = Camera::Get();
	MaterialManager* mm = MaterialManager::Get();

	//Calculate the 
	X::Color colorAmbient = mAmbient * mm->GetMaterialAmbient();

	//calculate diffuse color 
	//directional light iL = 1.0f; (light intensity)
	Vector3 L = -mDirection;
	float dot = X::Math::Max(MathHelper::Dot(L, normal), 0.0f);
	X::Color colorDiffuse = mDiffuse * mm->GetMaterialDiffuse() * dot;

	//Calculate specular color 
	//directionla light iL = 1.0f; (light intensity)
	Vector3 v = MathHelper::Normalize(camera->GetPosition() - positon);
	Vector3 r = MathHelper::Normalize(L + v);
	float fallOff = X::Math::Max((float)pow(MathHelper::Dot(r, normal), mm->GetMaterialShininess()),0.0f);
	X::Color colorSpecular = mSpecular * mm->GetMaterialSpecular() * fallOff;

	return colorAmbient + colorDiffuse + colorSpecular;
}
void DirectionalLight::SetDirection(const Vector3& direction)
{
	mDirection = MathHelper::Normalize(direction);
}


//Point Light
X::Color PointLight::ComputeLightColor(const Vector3& position, const Vector3& normal)
{
	Camera* camera = Camera::Get();
	MaterialManager* mm = MaterialManager::Get();

	// direction to light 
	Vector3 L = mPosition - position;
	float distance = MathHelper::Magnitude(L);
	L /= distance;

	//calculate iL
	float attenuation = 1.0f / (mAttenConst + (mAttenLinear * distance) + (mAttenQuad * distance *distance));
	float iL = X::Math::Clamp(attenuation, 0.0f, 1.0f);
	//Calculate the 
	X::Color colorAmbient = mAmbient * mm->GetMaterialAmbient();

	//calculate diffuse color 
	float dot = X::Math::Max(MathHelper::Dot(L, normal), 0.0f);
	X::Color colorDiffuse = mDiffuse * mm->GetMaterialDiffuse() * dot;

	//Calculate specular color 
	//directionla light iL = 1.0f; (light intensity)
	Vector3 v = MathHelper::Normalize(camera->GetPosition() - positon);
	Vector3 r = MathHelper::Normalize(L + v);
	float fallOff = X::Math::Max((float)pow(MathHelper::Dot(r, normal), mm->GetMaterialShininess()), 0.0f);
	X::Color colorSpecular = mSpecular * mm->GetMaterialSpecular() * fallOff;

	return colorAmbient + colorDiffuse + colorSpecular;
}

void PointLight::SetPosition(const Vector3& position)
{
	mPosition = position;
}
void PointLight::SetAttenuation(float constant, float linear, float queadratic)
{

}
