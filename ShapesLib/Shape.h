#pragma once
#include "Vec3.h"
#include "Shapes_API.h"

enum SHAPES_DLL_API ShapeType {
	CIRCLE = 0, 
	ELLIPSE = 1,
	SPIRAL = 2
};

class SHAPES_DLL_API Shape {
protected:
	Vec3 position_;
	ShapeType type_;
public:
	Vec3 getPosition() const;
	void setPosition(Vec3 position);
	
	ShapeType getType();

	virtual Vec3 calculatePoint(double angle) = 0;
	virtual Vec3 calculateDerivative(double angle) = 0;

	Shape(ShapeType type);
	virtual ~Shape() { };
};

