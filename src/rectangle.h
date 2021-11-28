#pragma once

#include <iostream>
#include<iomanip>
#include "./iterator/null_iterator.h"
#include "./shape.h"

class Rectangle : public Shape {
   public:
    Rectangle(double length, double width) : _length(length), _width(width) 
    {
        if(length<=0||width<=0)throw std::invalid_argument("length and width both cannot less or eqal than zero.");
    }

    double area() const override {return _length*_width;}

    double perimeter() const { return _length*2 + _width*2;}

    std::string info() const {
        return std::string("Rectangle (")
        .append(format_ftoa(_length,2))
        .append(" ")
        .append(format_ftoa(_width,2)
        .append(")"));
    }


    void accept(ShapeVisitor* visitor) override
    {
        visitor->visitRectangle(this);
    }

    Iterator* createIterator() override { return new NullIterator();}

   private:
    double _length, _width;
    std::string format_ftoa ( double x, int p ) const
    {
        std::stringstream strout ;
        strout << std::fixed << std::setprecision(p) << x ;
        return strout.str() ;
    }

};
