#pragma once
#include "Vector2.h"
#include "Vector3.h"

// share equation

namespace MathHelper
{
	bool IsEqual(float s, float b); 


	float MagnitudeSquared(const Vector2& v);
	float MagnitudeSquared(const Vector3& v);

	float Magnitude(const Vector2& v);
	float Magnitude(const Vector3& v);

	Vector2 Normalize(const Vector2& v);
	Vector3 Normalize(const Vector3& v);

	//take two vector and return the angle 
	float Dot (const Vector2& a, const Vector2& b);
	float Dot(const Vector3& a, const Vector3& b);

	Vector3 Cross(const Vector3& a, const Vector3& b);



}