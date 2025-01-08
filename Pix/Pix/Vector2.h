//#pragma once
//
//struct Vector2
//{
//	float x, y;
//
//	Vector2() : x(0), y(0) {}
//	Vector2(float s) : x(s), y(s) {}
//	Vector2(float x, float y) : x(x), y(y) {}
//	Vector2(const Vector2& v) : x(v.x), y(v.y) {}
//
//	//operators oveload 
//	//The simbols those this functions are overloading are the operators using the simbols of maths 
//	Vector2 operator-() {return Vector2 (-x, -y); }
//	//                only whant the data for that using const 
//	Vector2 operator+(const Vector2& rhs) const { return Vector2(x + rhs.x, y + rhs.y); }
//	Vector2 operator-(const Vector2& rhs) const { return Vector2(x - rhs.x, y - rhs.y); }
//	Vector2 operator*(float s) const { return Vector2(x * s, y * s); }
//	Vector2 operator/(float s) const{ return Vector2(x / s, y / s); }
//
//	Vector2& operator+=(const Vector2& rhs) { x += rhs.x; y += rhs.y; return *this; }
//	Vector2& operator-=(const Vector2& rhs) { x -= rhs.x; y -= rhs.y; return *this; }
//	Vector2& operator*=(float s) { x *= s; y *= s; return *this; }
//	Vector2& operator/=(float s) { x /= s; y /= s; return *this; }
//
//}; 
//
