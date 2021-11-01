#include "../src/circle.h"
#include "../src/utility.h"
#include"../src/compound_shape.h"
#include"../src/rectangle.h"
#include<gtest/gtest.h>
class CaseCompoundShape: public ::testing::Test{
    protected:
        CompoundShape* cs1;
        CompoundShape* cs2;
        Circle* c1;
        Circle* c2;
        Circle* notC1ButTheSameContent;
        Rectangle* r1;
        void SetUp() override{
            cs1 = new CompoundShape();
            c1 = new Circle(1.1);
            notC1ButTheSameContent = new Circle(1.1);
            r1 = new Rectangle(3.14 ,4);
            cs1->addShape(c1);
            cs1->addShape(r1);
            cs1->addShape(c1);
            cs1->addShape(notC1ButTheSameContent);
            cs2 = new CompoundShape();
            c2 = new Circle(12.34567);

            cs2->addShape(c2);
            cs2->addShape(cs1);
            cs2->addShape(c1);
        }
        void TearDown() override{
            delete cs1;
            delete cs2;
            delete c1;
            delete c2;
            delete notC1ButTheSameContent;
            delete r1;
        }
};

TEST_F(CaseCompoundShape, Info) {
    EXPECT_EQ(
        "CompoundShape\n"
        "{\n"
        "Circle (12.35)\n"
        "CompoundShape\n"
        "{\n"
        "Circle (1.10)\n"
        "Rectangle (3.14 4.00)\n"
        "Circle (1.10)\n"
        "Circle (1.10)\n"
        "}\n"
        "Circle (1.10)\n"
        "}",cs2->info()
    );
}
TEST_F(CaseCompoundShape, Delete) {
    cs1->deleteShape(c1);
    EXPECT_EQ(
        "CompoundShape\n"
        "{\n"
        "Circle (12.35)\n"
        "CompoundShape\n"
        "{\n"
        "Rectangle (3.14 4.00)\n"
        "Circle (1.10)\n"
        "}\n"
        "Circle (1.10)\n"
        "}",cs2->info()
    );
    cs1->deleteShape(r1);
    EXPECT_EQ(
        "CompoundShape\n"
        "{\n"
        "Circle (12.35)\n"
        "CompoundShape\n"
        "{\n"
        "Circle (1.10)\n"
        "}\n"
        "Circle (1.10)\n"
        "}",cs2->info()
    );
    cs1->deleteShape(notC1ButTheSameContent);
    EXPECT_EQ(
        "CompoundShape\n"
        "{\n"
        "Circle (12.35)\n"
        "CompoundShape\n"
        "{\n"
        "}\n"
        "Circle (1.10)\n"
        "}",cs2->info()
    );
    cs2->deleteShape(cs1);
    EXPECT_EQ(
        "CompoundShape\n"
        "{\n"
        "Circle (12.35)\n"
        "Circle (1.10)\n"
        "}",cs2->info()
    );
    cs2->deleteShape(c2);
    EXPECT_EQ(
        "CompoundShape\n"
        "{\n"
        "Circle (1.10)\n"
        "}",cs2->info()
    );
    cs2->deleteShape(c1);
    EXPECT_EQ(
        "CompoundShape\n"
        "{\n"
        "}",cs2->info()
    );
}


