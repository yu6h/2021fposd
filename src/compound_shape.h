#pragma once
#include <iostream>
#include <list>
#include "./iterator/compound_iterator.h"
#include "./shape.h"
class CompoundShape : public Shape
{
public:
    ~CompoundShape() {}

    double area() const override
    {
        double result = 0;
        for (Shape *s : _shapes)
        {
            result += s->area();
        }
        return result;
    }

    double perimeter() const override
    {
        double result = 0;
        for (Shape *s : _shapes)
        {
            result += s->perimeter();
        }
        return result;
    }

    std::string info() const override
    {
        // std::string result("CompoundShape\n{\n");
        // for (Shape *s : _shapes)
        // {
        //     result.append(s->info()).append("\n");
        // }
        // return result.append("}");
        return "CompoundShape";
    }

    void accept(ShapeVisitor *visitor) override
    {
        visitor->visitCompoundShape(this);
    }

    Iterator *createIterator() override
    {
        return new CompoundIterator<std::list<Shape *>::iterator>(_shapes.begin(), _shapes.end());
    }

    void addShape(Shape *shape) override
    {
        _shapes.push_back(shape);
    }

    bool deleteShape(Shape *shape) override
    {
        // ShapeDeleteVisitor* visitor = new ShapeDeleteVisitor(shape);
        // this->accept(visitor);

        //_shapes.remove(shape);

        for(auto it = _shapes.begin();it!=_shapes.end();it++){
            if(*it == shape){
                it = _shapes.erase(it);
                return true;
            }else if(typeid(**it)==typeid(CompoundShape)){
                if((*it)->deleteShape(shape))return true;
            }
        }
        return false;
    }
private:
    std::list<Shape *> _shapes;
};
