#pragma once
#include <string>
#include "./iterator.h"

template <class ForwardIterator>
class CompoundIterator : public Iterator
{
public:
    CompoundIterator(ForwardIterator begin, ForwardIterator end) : _begin(begin), _end(end)
    {
        first();
    }
    void first() override { _current = _begin; }
    Shape *currentItem() const override
    {
        if (isDone())
            throw(std::string("This CompoundIterator is in the end"));
        return *_current;
    }
    void next() override
    {
        if (isDone())
            throw(std::string("This CompoundIterator is in the end"));
        _current++;
    }
    bool isDone() const override
    {
        return _current == _end;
    }

private:
    ForwardIterator _current;
    ForwardIterator _begin;
    ForwardIterator _end;
};

// template<class ShapeConstraint>
// class SelectShapeVisitor: public ShapeVisitor {
// public:
//     SelectShapeVisitor(): _result(nullptr), _constraint(nullptr) {}
//     SelectShapeVisitor(ShapeConstraint constraint): _result(nullptr), _constraint(constraint) {}
//     void visitCircle(Circle* c);
//     void visitSquare(Square* s);
//     void visitCompoundShape(CompoundShape* cs);
//     Shape* getShape();

// private:
//     Shape* _result;
//     ShapeConstraint _constraint;
// };

// template<typename ShapeConstraint>
// void SelectShapeVisitor<ShapeConstraint>::visitCircle(Circle* c) {
//     if (_constraint(c)) {
//         _result = c; 
//     }
// }

// template<typename ShapeConstraint>
// void SelectShapeVisitor<ShapeConstraint>::visitSquare(Square* s) {
//     if (_constraint(s)) {
//         _result = s; 
//     }
// }

// template<typename ShapeConstraint>
// void SelectShapeVisitor<ShapeConstraint>::visitCompoundShape(CompoundShape* cs) {
//     // TODO: check if the sought after shape is a compound shape
//     Iterator* it = cs->createIterator();
//     for (it->first(); !it->isDone(); it->next()) {
//         it->currentItem()->accept(this);
//     }
// }

// template<typename ShapeConstraint>
// Shape* SelectShapeVisitor<ShapeConstraint>::getShape() {
//     return _result;
// }




// template<class ShapeConstraint>
// class SelectShapeVisitor: public ShapeVisitor {
// public:
//     SelectShapeVisitor(): _result(nullptr), _constraint(nullptr) {}
//     SelectShapeVisitor(ShapeConstraint constraint): _result(nullptr), _constraint(constraint) {}
//     void visitCircle(Circle* c);
//     void visitSquare(Square* s);
//     void visitCompoundShape(CompoundShape* cs);
//     Shape* getShape();

// private:
//     Shape* _result;
//     ShapeConstraint _constraint;
// };


// typedef bool (*ShapeConstraint)(Shape*); // pointer to function

// TEST(CaseVisitor, SelectShape) {
//     Shape* c1 = new Circle(1.0);
//     Shape* c2 = new Circle(1.0);
//     Shape* s = new Square(5.0);
//     Shape* shapes[3] = {c1, c2, s};
//     CompoundShape cs(shapes, 3);
    
//     SelectShapeVisitor<ShapeConstraint>* visitor = new SelectShapeVisitor<ShapeConstraint>([](Shape* shape) {
//         return shape->area() > 20.0 && shape->area() < 30.0;
//     });
//     cs.accept(visitor);
//     Shape* result = visitor->getShape();

//     ASSERT_EQ(s, result);

//     delete visitor;
// } 
