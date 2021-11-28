#pragma once

#include <cmath>
#include <iostream>

#include "./iterator/null_iterator.h"
#include "./shape.h"
#include "./two_dimensional_vector.h"

class Triangle : public Shape {
   public:
    Triangle(TwoDimensionalVector vec1, TwoDimensionalVector vec2)
        : _vec1(vec1), _vec2(vec2)
        {
            if(vec1.cross(vec2)==0) throw std::invalid_argument("the two vectors are parallel");
        }

    double area() const override {return abs(_vec1.cross(_vec2)/2);}

    double perimeter() const override {return _vec1.length()+_vec2.length()+_vec1.subtract(_vec2).length();}

    std::string info() const override {return std::string("Triangle (").append(_vec1.info()).append(" ").append(_vec2.info()).append(")");}

    void accept(ShapeVisitor* visitor) override
    {
        visitor->visitTriangle(this);
    }

    Iterator* createIterator() override { return new NullIterator();}

   private:
    TwoDimensionalVector _vec1, _vec2;
};
