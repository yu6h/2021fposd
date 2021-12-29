#include "../src/circle.h"
#include "../src/compound_shape.h"
#include "../src/rectangle.h"
#include <gtest/gtest.h>
#include "../src/visitor/shape_info_visitor.h"
class CaseCompoundShape : public ::testing::Test
{
protected:
    CompoundShape *cs1;
    CompoundShape *cs2;
    Circle *c1;
    Circle *c2;
    Circle *c3;
    Rectangle *r1;
    Rectangle *r2;
    Triangle* triangle;
    void SetUp() override
    {
        cs1 = new CompoundShape();
        c1 = new Circle(1.1);
        cs1->addShape(c1);
        r1 = new Rectangle(3.14, 4);
        cs1->addShape(r1);
        c2 = new Circle(2.5);
        cs1->addShape(c2);
        triangle = new Triangle(TwoDimensionalVector(3.0,0),TwoDimensionalVector(0,4.0));
        cs1->addShape(triangle);

        cs2 = new CompoundShape();

        c3 = new Circle(10.5);
        cs2->addShape(c3);
        cs2->addShape(cs1);
        r2 = new Rectangle(4,10.5);
        cs2->addShape( r2);
    }
    void TearDown() override
    {
        // delete c1;
        // delete notC1ButTheSameContent;
        // delete r1;
        // delete triangle;
        // delete c2;
        // delete cs1;
        delete cs2;
    }
};
TEST_F(CaseCompoundShape, Area){
    EXPECT_NEAR(1.1*1.1*M_PI+3.14*4+2.5*2.5*M_PI+6
    +10.5*10.5*M_PI+4*10.5,cs2->area(),0.5);
}
TEST_F(CaseCompoundShape, Perimeter){
    EXPECT_NEAR(2*1.1*M_PI+(3.14+4)*2+2*2.5*M_PI+12
    +2*10.5*M_PI+(4+10.5)*2,cs2->perimeter(),0.5);
}
TEST_F(CaseCompoundShape, Info)
{
    EXPECT_EQ(
        "CompoundShape",
        cs2->info());
}
TEST_F(CaseCompoundShape, Delete)
{
    ShapeInfoVisitor visitor;
    cs2->accept(&visitor);
    EXPECT_EQ(
        "CompoundShape {\n"
        "  Circle (10.50)\n"
        "  CompoundShape {\n"
        "    Circle (1.10)\n"
        "    Rectangle (3.14 4.00)\n"
        "    Circle (2.50)\n"
        "    Triangle ([3.00,0.00] [0.00,4.00])\n"
        "  }\n"
        "  Rectangle (4.00 10.50)\n"
        "}\n",
        visitor.getResult());
    cs2->deleteShape(c1);
    cs2->accept(&visitor);
    EXPECT_EQ(
        "CompoundShape {\n"
        "  Circle (10.50)\n"
        "  CompoundShape {\n"
        "    Rectangle (3.14 4.00)\n"
        "    Circle (2.50)\n"
        "    Triangle ([3.00,0.00] [0.00,4.00])\n"
        "  }\n"
        "  Rectangle (4.00 10.50)\n"
        "}\n",
        visitor.getResult());

    cs2->deleteShape(c2);
    cs2->accept(&visitor);
    EXPECT_EQ(
        "CompoundShape {\n"
        "  Circle (10.50)\n"
        "  CompoundShape {\n"
        "    Rectangle (3.14 4.00)\n"
        "    Triangle ([3.00,0.00] [0.00,4.00])\n"
        "  }\n"
        "  Rectangle (4.00 10.50)\n"
        "}\n",
        visitor.getResult());
    cs2->deleteShape(r1);
    cs2->accept(&visitor);
    EXPECT_EQ(
        "CompoundShape {\n"
        "  Circle (10.50)\n"
        "  CompoundShape {\n"
        "    Triangle ([3.00,0.00] [0.00,4.00])\n"
        "  }\n"
        "  Rectangle (4.00 10.50)\n"
        "}\n",
        visitor.getResult());

    cs2->deleteShape(triangle);
    cs2->accept(&visitor);
    EXPECT_EQ(
        "CompoundShape {\n"
        "  Circle (10.50)\n"
        "  CompoundShape {\n"
        "  }\n"
        "  Rectangle (4.00 10.50)\n"
        "}\n",
        visitor.getResult());

    cs2->deleteShape(cs1);
    cs2->accept(&visitor);
    EXPECT_EQ(
        "CompoundShape {\n"
        "  Circle (10.50)\n"
        "  Rectangle (4.00 10.50)\n"
        "}\n",
        visitor.getResult());
    //測試刪除不存在的物件時，不能拋出例外
    EXPECT_NO_THROW(cs2->deleteShape(c1));
    cs2->accept(&visitor);
    EXPECT_EQ(
        "CompoundShape {\n"
        "  Circle (10.50)\n"
        "  Rectangle (4.00 10.50)\n"
        "}\n",visitor.getResult()
    );
}
