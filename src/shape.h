#pragma once
#include"../src/iterator/iterator.h"
#include<string>

class Shape {
public:
    virtual ~Shape() {};

    virtual double area() const = 0;

    virtual double perimeter() const = 0;

    virtual std::string info() const = 0;

    virtual Iterator* createIterator() = 0;

    virtual void addShape(Shape* shape) { throw std::string("method not allowed");}

    virtual void deleteShape(Shape* shape) { throw std::string("method not allowed");}
};
