#pragma once
#include <gtest/gtest.h>
#include "../../src/visitor/shape_info_visitor.h"
#include <iostream>
TEST(CaseVisitor, CompoundShape)
{

    CompoundShape* cs1 = new CompoundShape();
    Circle* c1 = new Circle(1.1);
    cs1->addShape(c1);
    Rectangle *r1 = new Rectangle(3.14, 4);
    cs1->addShape(r1);

    CompoundShape *cs2 = new CompoundShape();
    Circle *c2 = new Circle(12.34567);
    cs2->addShape(c2);
    cs2->addShape(cs1);

    CompoundShape *cs3 = new CompoundShape();
    Circle *c3 = new Circle(5.5);
    cs3->addShape(c3);
    cs3->addShape(cs2);
    Rectangle *r2 = new Rectangle(5.3, 66);
    cs3->addShape(r2);

    CompoundShape *cs4 = new CompoundShape();
    Rectangle *r3 = new Rectangle(87, 66);
    cs4->addShape(r3);
    cs4->addShape(cs3);
    Rectangle *r4= new Rectangle(5.5, 66);
    cs4->addShape(r4);
    ShapeInfoVisitor visitor;
    visitor.visitCompoundShape(cs2);
    EXPECT_EQ("CompoundShape {\n"
              "  Circle (12.35)\n"
              "  CompoundShape {\n"
              "    Circle (1.10)\n"
              "    Rectangle (3.14 4.00)\n"
              "  }\n"
              "}\n",
              visitor.getResult());
    
    // cs3.accept(&visitor);
    visitor.visitCompoundShape(cs3);

    EXPECT_EQ("CompoundShape {\n"
              "  Circle (5.50)\n"
              "  CompoundShape {\n"
              "    Circle (12.35)\n"
              "    CompoundShape {\n"
              "      Circle (1.10)\n"
              "      Rectangle (3.14 4.00)\n"
              "    }\n"
              "  }\n"
              "  Rectangle (5.30 66.00)\n"
              "}\n",
              visitor.getResult());

    // cs4.accept(&visitor);
    visitor.visitCompoundShape(cs4);
    EXPECT_EQ("CompoundShape {\n"
              "  Rectangle (87.00 66.00)\n"
              "  CompoundShape {\n"
              "    Circle (5.50)\n"
              "    CompoundShape {\n"
              "      Circle (12.35)\n"
              "      CompoundShape {\n"
              "        Circle (1.10)\n"
              "        Rectangle (3.14 4.00)\n"
              "      }\n"
              "    }\n"
              "    Rectangle (5.30 66.00)\n"
              "  }\n"
              "  Rectangle (5.50 66.00)\n"
              "}\n",
              visitor.getResult());
    delete cs4;
}
TEST(CaseVisitor, Circle){
    ShapeInfoVisitor visitor;
    Circle haha(5.5);
    visitor.visitCircle(&haha);
    EXPECT_EQ(visitor.getResult(),"Circle (5.50)\n");
}
TEST(CaseVisitor, Rectangle){
    ShapeInfoVisitor visitor;
    Rectangle spyderman(88.12,99.33);
    visitor.visitRectangle(&spyderman);
    EXPECT_EQ(visitor.getResult(),"Rectangle (88.12 99.33)\n");
}
TEST(CaseVisitor, Triangle){
    ShapeInfoVisitor visitor;
    Triangle daredevil(TwoDimensionalVector(3,12.433),TwoDimensionalVector(17.56789,-4));
    visitor.visitTriangle(&daredevil);
    EXPECT_EQ(visitor.getResult(),"Triangle ([3.00,12.43] [17.57,-4.00])\n");
}
