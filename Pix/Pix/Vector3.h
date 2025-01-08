//#pragma once
//
//struct Vector3
//{
//	float x, y, z;
//
//	Vector3() : x(0), y(0), z(0.0f) {}
//	Vector3(float s) : x(s), y(s), z(s) {}
//	Vector3(float x, float y) : x(x), y(y), z(z) {}
//	Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
//
//	//operators oveload 
//	//The simbols those this functions are overloading are the operators using the simbols of maths 
//	Vector3 operator-() { return Vector3(-x, -y, -z); }
//	//                only whant the data for that using const 
//	Vector3 operator+(const Vector3& rhs) { return Vector3(x + rhs.x, y + rhs.y, z + rhs.z); }
//	Vector3 operator-(const Vector3& rhs) { return Vector3(x - rhs.x, y - rhs.y, z - rhs.z); }
//	Vector3 operator*(float s) { return Vector3(x * s, y * s, z *s); }
//	//
//	Vector3 operator/(float s) { return Vector3(x / s, y / s, z/ s); }
//
//	Vector3& operator+=(const Vector3& rhs) { x += rhs.x; y += rhs.y; z += rhs.z  return *this; }
//	Vector3& operator-=(const Vector3& rhs) { x -= rhs.x; y -= rhs.y; z -= rhs.z return *this; }
//	Vector3& operator*=(float s) { x *= s; y *= s; z *= s return *this; }
//	Vector3& operator/=(float s) { x /= s; y /= s; z /= s return *this; }
//
//};
