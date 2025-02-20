#pragma once

#include "Light.h"

class DirectionalLight : public Light
{
public: 
	X::Color ComputeLightColor(const Vector3& position, const Vector3& normal) const override; 
	void SetDirection(const Vector3& direction); 

private:
	Vector3 mDirection;
};

class PointLight : public Light
{
public:
	X::Color ComputeLightColor(const Vector3& position, const Vector3& normal) override;
	void SetPosition(const Vector3& position);
	void SetAttenuation(float constant, float linear, float quadratic);
private:
	Vector3 mPosition;
	float mConstant = 1.0f;
	float mLinear = 0.09f;
	float mQuadratic = 0.032f;
};