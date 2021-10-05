#pragma once
#include"shape.h"
#include<string>
#include<sstream>
#include<iomanip>
class Rectangle : public Shape {
private:
    const double m_length;
    const double m_width;
public: 
    Rectangle(double length, double width)
    : m_length(length), m_width(width)
    {
        if(length<0||width<0)throw SideLengthLessThanZeroError();
    }

    double area() const { return m_length*m_width;}

    double perimeter() const { return m_length*2 + m_width*2;}
    
    std::string info() const {
        return std::string("Rectangle (")
        .append(format_ftoa(m_length,2))
        .append(" ")
        .append(format_ftoa(m_width,2)
        .append(")"));
    }
private:
    std::string format_ftoa ( double x, int p ) const
    {
        std::stringstream strout ;
        strout << std::fixed << std::setprecision(p) << x ;
        return strout.str() ;
    }
public:
    class SideLengthLessThanZeroError{

    };
};
