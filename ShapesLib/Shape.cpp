#include "Shape.h"

ShapeType Shape::getType() {
	return type_;
}

Vec3 Shape::getPosition() const {
	return position_;
}
void Shape::setPosition(Vec3 position) {
	position_ = position;
}

Shape::Shape(ShapeType type) {
	type_ = type;
}
