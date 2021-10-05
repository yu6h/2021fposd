#pragma once
#include"shape.h"
#include<cmath>
#include<string>
#include<sstream>
#include<iomanip>
class Circle : public Shape {

private:
    const double m_radius;
public:

    Circle(double radius):m_radius(radius)
    {
        if(radius<0)throw LessThanZeroError();
    }

    double area() const { return m_radius*m_radius*M_PI;}

    double perimeter() const {return 2*m_radius*M_PI; }

    std::string info() const {
        return std::string("Circle (").append(format_ftoa(m_radius,2).append(")"));
    }
private:
    std::string format_ftoa ( double x, int p ) const
    {
        std::stringstream strout ;
        strout << std::fixed << std::setprecision(p) << x ;
        return strout.str() ;
    }
public:
    class LessThanZeroError{
    };
};
