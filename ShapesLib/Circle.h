#pragma once
#include "Shape.h"

class SHAPES_DLL_API Circle : public Shape {
private:
	double radius_ = 0;
public:
	double getRadius() const;
	void setRadius(double radius);

	Vec3 calculatePoint(double angle) override;
	Vec3 calculateDerivative(double angle) override;

	Circle(double radius);
};
