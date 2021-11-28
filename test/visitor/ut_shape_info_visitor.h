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

    CompoundShape *cs3 = new CompoundShape();
    cs3->addShape(new Circle(5.5));
    cs3->addShape(cs2);

    ShapeInfoVisitor *visitor = new ShapeInfoVisitor();
    // cs2->accept(visitor);

    // EXPECT_EQ("CompoundShape{\n"
    //           "  Circle (12.35)\n"
    //           "  CompoundShape{\n"
    //           "    Circle (1.10)\n"
    //           "    Rectangle (3.14 4.00)\n"
    //           "  }\n"
    //           "}\n",
    //           visitor->getResult());

    cs3->accept(visitor);

    EXPECT_EQ("CompoundShape{\n"
              "  Circle (5.50)\n"
              "  CompoundShape{\n"
              "    Circle (12.35)\n"
              "    CompoundShape{\n"
              "      Circle (1.10)\n"
              "      Rectangle (3.14 4.00)\n"
              "    }\n"
              "  }\n"
              "}\n",
              visitor->getResult());
    std::cout<<visitor->getResult()<<std::endl;
}