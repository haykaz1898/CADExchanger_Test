#include "Circle.h"
#include <cmath>
#include <stdexcept>
double Circle::getRadius() const {
	return radius_;
}
void Circle::setRadius(double radius) {
	if (radius < 0)
		throw std::runtime_error("Negative radius");
	radius_ = radius;
}

Vec3 Circle::calculatePoint(double angle) {
	return Vec3(position_.x + radius_ * std::cos(angle),
		position_.y + radius_ * std::sin(angle),
		position_.z);
}

Vec3 Circle::calculateDerivative(double angle) {
	return Vec3(-radius_ * std::sin(angle),
		radius_ * std::cos(angle),
		0);
}

Circle::Circle(double radius) : Shape(CIRCLE) { 
	setRadius(radius);
}
