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
        Rectangle* r1;
        void SetUp() override{
            cs1 = new CompoundShape();
            c1 = new Circle(1.1);
            r1 = new Rectangle(3.14 ,4);
            cs1->addShape(c1);
            cs1->addShape(r1);

            cs2 = new CompoundShape();
            c2 = new Circle(12.34567);
            cs2->addShape(c2);
            cs2->addShape(cs1);

        }
        void TearDown() override{

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
        "}\n"
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
        "}\n"
        "}",cs2->info()
    );
}


