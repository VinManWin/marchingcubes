#include <iostream>
#include <vector>
#include <functional>
#include <fstream>
#include "marchingcubes.hpp"

int main() {
	Function circle = [](float x, float y, float z) -> float {
		return x*x + y*y + z*z - 1;
	};

	Function cylinder = [](float x, float y, float z) -> float {
		return (x*x + y*y - 1);
	};

	Function f = [&](float x, float y, float z) -> float {
		return circle(x-3, y-3, z-3)*circle(x-2, y-2, z-1)*circle(x-4, y-4, z-3)*cylinder(x-1.5, y-3.5, z-2) - z;
	};

	std::vector<Triangle> tris = generateTriangles(f, 0.05f, 100, 100, 100);
	std::cout << tris.size() << " triangles" << std::endl;
	std::ofstream fout("mesh.off", std::ios_base::trunc);
	fout << "OFF" << "\n";
	fout << tris.size() * 3 << " " << tris.size() << " 0\n";
	for(const Triangle& tri : tris){
		fout << tri;
	}
	for(size_t i = 0; i < tris.size(); ++i){
		fout << 3 << " " << i*3 << " " << i*3+1 << " " << i*3+2 << "\n";
	}
}

