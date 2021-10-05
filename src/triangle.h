#pragma once
#include"shape.h"
#include"two_dimensional_vector.h"
#include<string>
#include<cmath>
class Triangle: public Shape {
private:
    const TwoDimensionalVector m_vec1,m_vec2;
public:
    Triangle(TwoDimensionalVector vec1, TwoDimensionalVector vec2) :m_vec1(vec1),m_vec2(vec2) {
        if(vec1.cross(vec2)==0) throw ParallelVectorError();
    }

    double area() const { 
        /***
        TwoDimensionalVector x_vec1 = m_vec1;
        double a = m_vec2.dot(m_vec1);
        double b = m_vec1.dot(m_vec1);
        TwoDimensionalVector temp((a/b)*m_vec1.x(),(a/b)*m_vec1.y());
        TwoDimensionalVector x_vec2 = m_vec2.subtract(temp);
        return x_vec1.length()*x_vec2.length()/2;
        */
       return abs(m_vec1.cross(m_vec2)/2);
    }

    double perimeter() const {
        return m_vec1.length()+m_vec2.length()+m_vec1.subtract(m_vec2).length();
    }

    std::string info() const {
        return std::string("Triangle (").append(m_vec1.info()).append(" ").append(m_vec2.info()).append(")");
     }
public:
    class ParallelVectorError{

    };
};