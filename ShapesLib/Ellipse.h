#pragma once
#include "Shape.h"

class SHAPES_DLL_API Ellipse : public Shape {
private:
	double xRadius_ = 0;
	double yRadius_ = 0;
public:
	double getXRadius() const;
	void setXRadius(double radius);

	double getYRadius() const;
	void setYRadius(double radius);

	Vec3 calculatePoint(double angle) override;
	Vec3 calculateDerivative(double angle) override;

	Ellipse(double xRadius, double yRadius);
};

