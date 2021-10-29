#pragma once
#include"shape.h"
#include<iomanip>
#include<cmath>
#include<stdexcept>
#include"iterator/null_iterator.h"
class Circle : public Shape {
    private:
    const double m_radius;

    public:
       Circle(double radius):m_radius(radius)
    {
        if(radius<=0)throw std::invalid_argument("radius cannot less or eqal than zero.");
    }


    double area() const { return m_radius*m_radius*M_PI;}

    double perimeter() const {return 2*m_radius*M_PI; }

    std::string info() const override {
        return std::string("Circle (").append(format_ftoa(m_radius,2).append(")"));
    }

    Iterator* createIterator() override { return new NullIterator();}
    private:
    std::string format_ftoa ( double x, int p ) const
    {
        std::stringstream strout ;
        strout << std::fixed << std::setprecision(p) << x ;
        return strout.str() ;
    }

};