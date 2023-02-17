#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <memory>
#include <cmath>
#include <numeric>
#include <algorithm>

#include "Shape.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Spiral.h"

class ShapeTester {
private:
    std::vector<std::unique_ptr<Shape>> shapes;
    std::vector<Circle*> circles;

    std::mt19937_64 engine;
    double getRadius() {
        static std::uniform_real_distribution<> radiusGen(0, 10);
        return radiusGen(engine);
    }
    int getType() {
        static std::uniform_int_distribution<> typeGen(0, 2);
        return typeGen(engine);
    }
    int getCount() {
        static std::uniform_int_distribution<> countGen(10, 30);
        return countGen(engine);
    }
    double getStep() {
        static std::uniform_real_distribution<> stepGen(-5, 5);
        return stepGen(engine);
    }
    std::string getTypeString(ShapeType type) {
        return type == CIRCLE ? "Circle" : type == ELLIPSE ? "Ellipse" : "Spiral";
    }
public:
    void populateShapes() {
        const size_t count = getCount();
        shapes.resize(count);
        for (size_t i = 0; i < count; i++) {
            const auto type = (ShapeType)getType();
            if (type == CIRCLE)
                shapes[i] = std::make_unique<Circle>(getRadius());
            else if (type == ELLIPSE)
                shapes[i] = std::make_unique<Ellipse>(getRadius(), getRadius());
            else if (type == SPIRAL)
                shapes[i] = std::make_unique<Spiral>(getStep(), getRadius());
        }
    }
    void populateCirclesFromShapes() {
        if (shapes.empty())
            return;
        circles.reserve(shapes.size());
        for (const auto& shape : shapes)
            if (shape->getType() == CIRCLE)
                circles.push_back(static_cast<Circle*>(shape.get()));
    }

    void printShapesData() {
        const double angle = M_PI_4;
        for (const auto& shape : shapes) {
            std::cout << getTypeString(shape->getType()) << std::endl;
            std::cout << "Point: " << shape->calculatePoint(angle).to_string() << std::endl;
            std::cout << "Derivative Point: " << shape->calculateDerivative(angle).to_string() << std::endl;
        }
    }
    void sortCircles() {
        std::sort(circles.begin(), circles.end(), [](auto& l, auto& r) {
            return l->getRadius() < r->getRadius();
        });
    }
    double computeSumOfRadii() {
        double sum = 0;
#pragma omp for
        for (int i = 0; i < circles.size(); i++) {
            #pragma omp atomic
            sum += circles[i]->getRadius();
        }
        return sum;
    }
    ShapeTester() {
        std::random_device rd;
        engine = std::mt19937_64(rd());
    }
};

int main()
{
    ShapeTester tester;
    tester.populateShapes();
    tester.printShapesData();
    tester.populateCirclesFromShapes();
    tester.sortCircles();
    double sum = tester.computeSumOfRadii();
    std::cout << std::endl << "Sum of circles radii: " << sum << std::endl;
    std::cin.get();
}
