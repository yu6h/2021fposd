#pragma once

#include <cmath>
#include <stdexcept>
#include "./iterator/null_iterator.h"
#include "./shape.h"
#include "./visitor/shape_visitor.h"
#include <iomanip>
class Circle : public Shape
{
public:
    Circle(double radius) : _radius(radius)
    {
        if (radius <= 0)
            throw std::invalid_argument("radius cannot less or eqal than zero.");
    }

    double area() const { return _radius * _radius * M_PI; }

    double perimeter() const { return 2 * _radius * M_PI; }

    std::string info() const override
    {
        return std::string("Circle (").append(format_ftoa(_radius, 2).append(")"));
    }

    void accept(ShapeVisitor *visitor) override
    {
        visitor->visitCircle(this);
    }

    Iterator *createIterator() override { return new NullIterator(); }

private:
    double _radius;
    std::string format_ftoa(double x, int p) const
    {
        std::stringstream strout;
        strout << std::fixed << std::setprecision(p) << x;
        return strout.str();
    }
};
