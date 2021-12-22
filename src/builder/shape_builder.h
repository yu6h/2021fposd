#pragma once

#include <list>
#include <stack>

#include "../circle.h"
#include "../compound_shape.h"
#include "../iterator/iterator.h"
#include "../rectangle.h"
#include "../triangle.h"
#include "../two_dimensional_vector.h"

class ShapeBuilder 
{
    private:

    std::list<Shape*> _shapes;

    ShapeBuilder(){}
    // static int xx;
     
    public:
    
    static ShapeBuilder* getInstance() 
    {
        static ShapeBuilder _instance;
        return &_instance;
    }

    void buildCircle(double radius)
    {
        _shapes.push_back(new Circle(radius));
    }

    void buildRectangle(double length, double width)
    {
        _shapes.push_back(new Rectangle(length,width));
    }

    void buildTriangle(double x1, double y1, double x2, double y2)
    {
        _shapes.push_back(new Triangle(TwoDimensionalVector(x1,y1),TwoDimensionalVector(x2,y2) ) );
    }

    void buildCompoundBegin()
    {
        _shapes.push_back(new CompoundShape());
    }

    void buildCompoundEnd()
    {
        std::list<Shape*> components;
        while(typeid(*_shapes.back()) != typeid(CompoundShape) || !_shapes.back()->createIterator()->isDone())
        {
            components.push_front(_shapes.back());
            _shapes.pop_back();
        }
        Shape* compound = _shapes.back();
        for(auto it = components.begin() ; it != components.end() ; it++)
        {
            compound->addShape(*it);
        }
    }

    Shape* getShape() 
    {
        Shape * lastShape = _shapes.back();
        _shapes.pop_back();
        return lastShape;
    }

    void reset() 
    {
        // _instance = ShapeBuilder();
    }

};


