#include "../src/circle.h"
#include "../src/utility.h"
#include "../src/compound_shape.h"
#include"../src/rectangle.h"
#include<gtest/gtest.h>

TEST(CaseUtility, SelectShape) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* s = new Rectangle(5.0,5.0);
    CompoundShape cs;
    cs.addShape(c1);
    cs.addShape(c2);
    cs.addShape(s);
    
    Shape* result = selectShape(&cs, [](Shape* shape){
        return shape->area() > 20.0 && shape->area() < 30.0;
    });

    ASSERT_EQ(s, result);
}