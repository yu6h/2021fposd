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
            delete cs1;
            delete cs2;
            delete c1;
            delete c2;
            delete r1;
        }
};

TEST_F(CaseCompoundShape, Info) {
    EXPECT_EQ(
        "Compound Shape\n"
        "{\n"
        "Circle (12.35)\n"
        "Compound Shape\n"
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
        "Compound Shape\n"
        "{\n"
        "Circle (12.35)\n"
        "Compound Shape\n"
        "{\n"
        "Rectangle (3.14 4.00)\n"
        "}\n"
        "}",cs2->info()
    );
}


// TEST_F(CaseCompoundShape, Iterator) {
//     Shape* cc1 = new Circle(1.0);
//     Shape* cc2 = new Circle(1.0);
//     Shape* rr = new Rectangle(5.0,10.0);
//     CompoundShape* cs = new CompoundShape();
//     cs->addShape(cc1);
//     cs->addShape(cc2);
//     cs->addShape(rr);
//     cs->addShape(cs1);
//     Iterator* it = cs->createIterator();


//     EXPECT_EQ(cs, it->currentItem());

//     it->first();
//     EXPECT_EQ(cc1, it->currentItem());

//     it->next();
//     EXPECT_EQ(cc2, it->currentItem());

//     it->next();
//     EXPECT_EQ(rr, it->currentItem());

//     it->next();
//     EXPECT_EQ(cs1, it->currentItem());

//     it->next();
//     EXPECT_EQ(c1, it->currentItem());

//     it->next();
//     EXPECT_EQ(r1, it->currentItem());

//     it->next();
//     EXPECT_TRUE(it->isDone());
//     delete cc1;
//     delete cc2;
//     delete rr;
//     delete it;
// }