#pragma once
#include"shape.h"
#include"iterator/compound_iterator.h"
#include<list>


class CompoundShape : public Shape {
    private:
    std::list<Shape*> _shapes;
public:
    ~CompoundShape() { }

    double area() const override { 
        double result = 0;
        for (Shape* s:_shapes) {
            result += s->area();
        }
        return result;
    }

    int getCount() const {
        return _shapes.size();
    }

    double perimeter() const override {
        double result = 0;
        for (Shape* s:_shapes) {
            result += s->perimeter();
        }
        return result;
    }

    std::string info() const override {
        std::string result("CompoundShape\n{\n");
        for (Shape* s:_shapes) {
            result.append(s->info()).append("\n");
        }
        return result.append("}");
    }

    Iterator* createIterator() override {
        return new CompoundIterator<std::list<Shape*>::iterator>(_shapes.begin(),_shapes.end());
    }

    void addShape(Shape* shape) override { 
        _shapes.push_back(shape);
    }

    void deleteShape(Shape* shape) override {
        for(auto it = _shapes.begin();it!=_shapes.end();){
            if(*it == shape){
                it = _shapes.erase(it);
            }
            it++;
        }
    }
};