#pragma once
#include "Shape.h"

class SHAPES_DLL_API Spiral : public Shape {
private:
	double step_ = 0;
	double radius_ = 0;
public:
	double getStep() const;
	void setStep(double step);

	double getRadius() const;
	void setRadius(double _radius);

	Vec3 calculatePoint(double angle) override;
	Vec3 calculateDerivative(double angle) override;

	Spiral(double step, double radius);
};

