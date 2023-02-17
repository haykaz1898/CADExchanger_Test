#include "Vec3.h"

std::string Vec3::to_string() const {
	return "{ x = " + std::to_string(x) + "; y = " + std::to_string(y) + "; z = " + std::to_string(z) + " }";
}

Vec3& Vec3::operator=(const Vec3& other) {
	if (this == &other)
		return *this;
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}
Vec3& Vec3::operator=(Vec3&& other) noexcept {
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}

Vec3::Vec3() : x(0), y(0), z(0) { }
Vec3::Vec3(const Vec3& other) {
	*this = other;
	if (this == &other)
		return;
	x = other.x;
	y = other.y;
	z = other.z;
}
Vec3::Vec3(Vec3&& other) noexcept {
	x = other.x;
	y = other.y;
	z = other.z;
}
Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z) { }