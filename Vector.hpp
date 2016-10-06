#include <ostream>

struct Vector {
	float x, y, z;
	Vector(float x, float y, float z);
	Vector& operator*=(float s);
	Vector& operator/=(float s);
	Vector& operator+=(const Vector& rhs);
	Vector& operator-=(const Vector& rhs);
};

Vector operator-(const Vector& v);
Vector operator*(float s, const Vector& v);
Vector operator*(const Vector& v, float s);
Vector operator/(const Vector& lhs, float rhs);
Vector operator+(const Vector& lhs, const Vector& rhs);
Vector operator-(const Vector& lhs, const Vector& rhs);
Vector operator-(const Vector& v);
std::ostream& operator<<(std::ostream& out, const Vector& vec);
