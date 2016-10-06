#include "Vector.hpp"

Vector::Vector(float x, float y, float z)
	: x(x), y(y), z(z)
{
}

Vector& Vector::operator*=(float s){
	x *= s;
	y *= s;
	z *= s;
	return *this;
}

Vector& Vector::operator/=(float s){
	*this *= 1/s;
	return *this;
}

Vector& Vector::operator+=(const Vector& rhs) {
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

Vector& Vector::operator-=(const Vector& rhs) {
	*this += -rhs;
	return *this;
}

Vector operator*(float s, const Vector& v) {
	Vector result = v;
	return result *= s;
}

Vector operator*(const Vector& v, float s) {
	return s * v;
}

Vector operator/(const Vector& lhs, float rhs) {
	Vector result = lhs;
	return result /= rhs;
}

Vector operator+(const Vector& lhs, const Vector& rhs) {
	Vector result = lhs;
	result += rhs;
	return result;
}

Vector operator-(const Vector& lhs, const Vector& rhs) {
	Vector result = lhs;
	result -= rhs;
	return result;
}

Vector operator-(const Vector& v) {
	return Vector(-v.x, -v.y, -v.z);
}

std::ostream& operator<<(std::ostream& out, const Vector& vec) {
	return out << vec.x << " " << vec.y << " " << vec.z;
}
