#include "Spiral.h"
#include <cmath>
#include <stdexcept>

double Spiral::getStep() const {
	return step_;
}
void Spiral::setStep(double step) {
	step_ = step;
}

double Spiral::getRadius() const {
	return radius_;
}
void Spiral::setRadius(double radius) {
	if (radius < 0)
		throw std::runtime_error("Negative radius");
	radius_ = radius;
}

Vec3 Spiral::calculatePoint(double angle) {
	return Vec3(position_.x + radius_ * std::cos(angle), 
		position_.y + radius_ * std::sin(angle), 
		position_.z + step_ * angle);
}

Vec3 Spiral::calculateDerivative(double angle) {
	return Vec3(-radius_ * std::sin(angle),
		radius_ * std::cos(angle),
		step_);
}
Spiral::Spiral(double step, double radius) : Shape(SPIRAL) {
	setStep(step);
	setRadius(radius);
}