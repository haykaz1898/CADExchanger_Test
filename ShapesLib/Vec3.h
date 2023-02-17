#pragma once
#include "Shapes_API.h"
#include <string>

struct SHAPES_DLL_API Vec3 {
	double x;
	double y;
	double z;
	
	std::string to_string() const;

	Vec3& operator=(const Vec3& other);
	Vec3& operator=(Vec3&& other) noexcept;
	
	Vec3();
	Vec3(const Vec3& other);
	Vec3(Vec3&& other) noexcept;
	Vec3(double x, double y, double z);
};

