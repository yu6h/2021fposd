#pragma once
#include<string>
#include <cmath>
#include<iomanip>
#include<sstream>
class TwoDimensionalVector {
private:
    const double m_x;
    const double m_y;
public:
    TwoDimensionalVector(double x, double y) : m_x(x),m_y(y){
        if(x==0 && y==0)throw ZeroVectorError();
    }

    double x() const { return m_x; }

    double y() const { return m_y; }

    double length() const { return sqrt(m_x*m_x + m_y*m_y); }

    double dot(TwoDimensionalVector vec) const { return m_x*vec.x() + m_y*vec.y(); }
//dot product
    double cross(TwoDimensionalVector vec) const { return m_x*vec.y() - m_y*vec.x(); }
//cross product
    TwoDimensionalVector subtract(TwoDimensionalVector vec) const { 
        return TwoDimensionalVector(m_x - vec.x(), m_y-vec.y());
        }

    std::string info() const {
        return std::string("[")
        .append(format_ftoa(m_x,2)
        .append(",")
        .append(format_ftoa(m_y,2))
        .append("]"));
    }
private:
    std::string format_ftoa ( double x, int p ) const
    {
        std::stringstream strout ;
        strout << std::fixed << std::setprecision(p) << x ;
        return strout.str() ;
    }
public:
    class ZeroVectorError{

    };
};