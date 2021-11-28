#pragma once
#include <gtest/gtest.h>
#include "../../src/visitor/shape_info_visitor.h"
#include <iostream>
TEST(CaseVisitor, ShapeInfoVisitor)
{

    CompoundShape *cs1 = new CompoundShape();

    cs1->addShape(new Circle(1.1));
    cs1->addShape(new Rectangle(3.14, 4));

    CompoundShape *cs2 = new CompoundShape();
    cs2->addShape(new Circle(12.34567));
    cs2->addShape(cs1);


    ShapeInfoVisitor *visitor = new ShapeInfoVisitor();
    cs2->accept(visitor);

    EXPECT_EQ("CompoundShape{\n\tCircle (12.35)\n\tCompoundShape{\n\t\tCircle (1.10)\n\t\tRectangle (3.14 4.00)\n\t}\n}\n",visitor->getResult());
}