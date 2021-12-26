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
    Circle *notC1ButTheSameContent;
    Rectangle *r1;
    Triangle* triangle;
    void SetUp() override
    {
        cs1 = new CompoundShape();
        c1 = new Circle(1.1);
        notC1ButTheSameContent = new Circle(1.1);
        
        r1 = new Rectangle(3.14, 4);
        triangle = new Triangle(TwoDimensionalVector(3.0,0),TwoDimensionalVector(0,4.0));
        cs1->addShape(c1);
        cs1->addShape(r1);
        cs1->addShape(c1);
        cs1->addShape(notC1ButTheSameContent);
        cs1->addShape(triangle);
        cs2 = new CompoundShape();
        c2 = new Circle(12.34567);

        cs2->addShape(c1);
        cs2->addShape(c2);
        cs2->addShape(cs1);
        cs2->addShape(c1);
    }
    void TearDown() override
    {
        delete cs1;
        delete cs2;
        delete c1;
        delete c2;
        delete notC1ButTheSameContent;
        delete r1;
        delete triangle;
    }
};
TEST_F(CaseCompoundShape, Area){
    EXPECT_NEAR(1.1*1.1*M_PI*5+12.35*12.35*M_PI+3.14*4+6,cs2->area(),0.5);
}
TEST_F(CaseCompoundShape, Perimeter){
    EXPECT_NEAR(2*1.1*M_PI*5+2*12.35*M_PI+2*(3.14+4)+12,cs2->perimeter(),0.5);
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
        "  Circle (1.10)\n"
        "  Circle (12.35)\n"
        "  CompoundShape {\n"
        "    Circle (1.10)\n"
        "    Rectangle (3.14 4.00)\n"
        "    Circle (1.10)\n"
        "    Circle (1.10)\n"
        "    Triangle ([3.00,0.00] [0.00,4.00])\n"
        "  }\n"
        "  Circle (1.10)\n"
        "}\n",
        visitor.getResult());
    cs2->deleteShape(c1);
    cs2->accept(&visitor);
    EXPECT_EQ(
        "CompoundShape {\n"
        "  Circle (12.35)\n"
        "  CompoundShape {\n"
        "    Circle (1.10)\n"
        "    Rectangle (3.14 4.00)\n"
        "    Circle (1.10)\n"
        "    Circle (1.10)\n"
        "    Triangle ([3.00,0.00] [0.00,4.00])\n"
        "  }\n"
        "  Circle (1.10)\n"
        "}\n",
        visitor.getResult());

    cs2->deleteShape(c1);
    cs2->accept(&visitor);
    EXPECT_EQ(
        "CompoundShape {\n"
        "  Circle (12.35)\n"
        "  CompoundShape {\n"
        "    Rectangle (3.14 4.00)\n"
        "    Circle (1.10)\n"
        "    Circle (1.10)\n"
        "    Triangle ([3.00,0.00] [0.00,4.00])\n"
        "  }\n"
        "  Circle (1.10)\n"
        "}\n",
        visitor.getResult());

    cs2->deleteShape(c1);
    cs2->accept(&visitor);
    EXPECT_EQ(
        "CompoundShape {\n"
        "  Circle (12.35)\n"
        "  CompoundShape {\n"
        "    Rectangle (3.14 4.00)\n"
        "    Circle (1.10)\n"
        "    Triangle ([3.00,0.00] [0.00,4.00])\n"
        "  }\n"
        "  Circle (1.10)\n"
        "}\n",
        visitor.getResult());
    cs2->deleteShape(c1);
    cs2->accept(&visitor);
    EXPECT_EQ(
        "CompoundShape {\n"
        "  Circle (12.35)\n"
        "  CompoundShape {\n"
        "    Rectangle (3.14 4.00)\n"
        "    Circle (1.10)\n"
        "    Triangle ([3.00,0.00] [0.00,4.00])\n"
        "  }\n"
        "}\n",
        visitor.getResult());

    //測試刪除不存在的物件時，不能拋出例外
    EXPECT_NO_THROW(cs2->deleteShape(c1));
    cs2->accept(&visitor);
    EXPECT_EQ(
        "CompoundShape {\n"
        "  Circle (12.35)\n"
        "  CompoundShape {\n"
        "    Rectangle (3.14 4.00)\n"
        "    Circle (1.10)\n"
        "    Triangle ([3.00,0.00] [0.00,4.00])\n"
        "  }\n"
        "}\n",visitor.getResult()
    );
}
