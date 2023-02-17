#include "Ellipse.h"
#include <cmath>
#include <stdexcept>

double Ellipse::getXRadius() const {
	return xRadius_;
}
void Ellipse::setXRadius(double radius) {
	if (radius < 0)
		throw std::runtime_error("Negative radius");
	xRadius_ = radius;
}

double Ellipse::getYRadius() const {
	return yRadius_;
}
void Ellipse::setYRadius(double radius) {
	if (radius < 0)
		throw std::runtime_error("Negative radius");
	yRadius_ = radius;
}

Vec3 Ellipse::calculatePoint(double angle) {
	return Vec3(position_.x + xRadius_ * std::cos(angle),
		position_.y + yRadius_ * std::sin(angle),
		position_.z);
}

Vec3 Ellipse::calculateDerivative(double angle) {
	return Vec3(-xRadius_ * std::sin(angle),
		yRadius_ * std::cos(angle),
		0);
}

Ellipse::Ellipse(double xRadius, double yRadius) : Shape(ELLIPSE) {
	setXRadius(xRadius);
	setYRadius(yRadius);
}