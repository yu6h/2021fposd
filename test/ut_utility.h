#include "../src/circle.h"
#include "../src/utility.h"
#include "../src/compound_shape.h"
#include"../src/rectangle.h"
#include<gtest/gtest.h>

TEST(CaseUtility, SelectShape) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* s = new Rectangle(5.0,5.0);
    Shape* c3 = new Circle(5.0);

    CompoundShape cs;
    cs.addShape(c1);
    cs.addShape(c2);
    cs.addShape(s);
    cs.addShape(c3);
    
    Shape* result1 = selectShape(&cs, [](Shape* shape){
        return shape->area() > 20.0 && shape->area() < 30.0;
    });

    ASSERT_EQ(s, result1);

    Shape* result2 = selectShape(&cs, [](Shape* shape){
        return shape->area() <5;
    });
    ASSERT_EQ(c1, result2);

    Shape* result3 = selectShape(&cs, [](Shape* shape){
        return shape->area() <80.0 && shape->area()>75.0;
    });
    ASSERT_EQ(c3, result3);

    Shape* result4 = selectShape(&cs, [](Shape* shape){
        return shape->area() == 25.0;
    });
    ASSERT_EQ(s, result4);
    delete c1;
    delete c2;
    delete s;
    delete c3;
}