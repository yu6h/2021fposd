#pragma once
#include <iomanip>
#include <cmath>
#include <iostream>

class TwoDimensionalVector
{
private:
    double _x, _y;

public:
    TwoDimensionalVector(double x, double y) : _x(x), _y(y)
    {
        //if (x == 0 && y == 0)throw std::invalid_argument("Cannot use Zero Vector");
    }

    double x() const { return _x; }

    double y() const { return _y; }

    double length() const { return sqrt(_x * _x + _y * _y); }

    double dot(TwoDimensionalVector vec) const { return _x * vec.x() + _y * vec.y(); }

    double cross(TwoDimensionalVector vec) const { return _x*vec.y() - _y*vec.x(); }

    TwoDimensionalVector subtract(TwoDimensionalVector vec) const
    {
        return TwoDimensionalVector(_x - vec.x(), _y - vec.y());
    }

    std::string info() const
    {
        return std::string("[")
            .append(format_ftoa(_x, 2)
                        .append(",")
                        .append(format_ftoa(_y, 2))
                        .append("]"));
    }

private:
    std::string format_ftoa(double x, int p) const
    {
        std::stringstream strout;
        strout << std::fixed << std::setprecision(p) << x;
        return strout.str();
    }
};
