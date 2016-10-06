#pragma once
#include <ostream>
#include <functional>
#include <vector>
#include "Vector.hpp"

struct Triangle {
	Vector v1, v2, v3;
	Triangle(Vector v1, Vector v2, Vector v3);
};

std::ostream& operator<<(std::ostream& out, const Triangle& tri);

typedef std::function<float(float, float, float)> Function;

std::vector<Triangle> generateTriangles(Function f, float gridSize, size_t width, size_t height, size_t depth);
