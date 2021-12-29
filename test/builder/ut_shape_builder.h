#include"../../src/builder/shape_builder.h"
#include"../../src/visitor/shape_info_visitor.h"
#include <gtest/gtest.h>
TEST(CaseShapeBuilder, buildCompound)
{
    ShapeBuilder* builder = ShapeBuilder::getInstance();
    builder->buildCompoundBegin();
    builder->buildCircle(3);
    builder->buildCompoundBegin();
    builder->buildCircle(5.0);
    builder->buildRectangle(11.5,8.6);
    builder->buildTriangle(3.0,0,0,4.0);
    builder->buildCompoundEnd();
    builder->buildCompoundEnd();

    Shape* shape = builder->getShape();

    ShapeInfoVisitor* visitor = new ShapeInfoVisitor();
    shape->accept(visitor);
    EXPECT_EQ(
        "CompoundShape {\n"
        "  Circle (3.00)\n"
        "  CompoundShape {\n"
        "    Circle (5.00)\n"
        "    Rectangle (11.50 8.60)\n"
        "    Triangle ([3.00,0.00] [0.00,4.00])\n"
        "  }\n"
        "}\n",
        visitor->getResult());
    builder->reset();
    delete visitor;
    // delete shape;
    // delete builder;

}
TEST(CaseShapeBuilder, singleton)
{
    EXPECT_EQ(ShapeBuilder::getInstance(),ShapeBuilder::getInstance());
}

TEST(CaseShapeBuilder, buildCircle)
{
    ShapeBuilder* builder = ShapeBuilder::getInstance();

    builder->buildCircle(10.0);
    Shape *s = builder->getShape();
    EXPECT_EQ("Circle (10.00)",s->info());
    builder->reset();
    // delete s;
    // delete builder;
}
TEST(CaseShapeBuilder, buildRectangle)
{
    ShapeBuilder* builder = ShapeBuilder::getInstance();
    builder->buildRectangle(10.0,12.0);
    Shape *s = builder->getShape();
    EXPECT_EQ("Rectangle (10.00 12.00)",s->info());
    builder->reset();
    // delete s;
    // delete builder;
}
TEST(CaseShapeBuilder, buildTriangle)
{
    ShapeBuilder* builder = ShapeBuilder::getInstance();

    builder->buildTriangle(10.0,12.0,9.0,8.7);
    Shape *s = builder->getShape();
    EXPECT_EQ("Triangle ([10.00,12.00] [9.00,8.70])",s->info());
    builder->reset();
    // delete s;
    // delete builder;
}
