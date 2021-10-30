#include "../src/circle.h"
#include "../src/utility.h"
#include "../src/compound_shape.h"
#include"../src/rectangle.h"
#include<gtest/gtest.h>

TEST(CaseNullIterator, NullIterator){
    Iterator* it = new NullIterator();
    ASSERT_TRUE(it->isDone());
    delete it;
}
TEST(CaseCompoundIterator, Iterator) {
    CompoundShape* cs1 = new CompoundShape();
    Circle* c1 = new Circle(1.1);
    
    Rectangle* r1 = new Rectangle(3.14 ,4);

    cs1->addShape(c1);
    cs1->addShape(r1);

    CompoundShape* cs2 = new CompoundShape();
    Circle* c2 = new Circle(12.34567);

    cs2->addShape(c2);
    cs2->addShape(cs1);


    Iterator* it = cs2->createIterator();
    it->first();
    EXPECT_EQ(c2, it->currentItem());

    it->next();
    EXPECT_EQ(cs1, it->currentItem());

    it->next();
    EXPECT_TRUE(it->isDone());

    delete cs1;
    delete c1;
    delete r1;
    delete cs2;
    delete c2;
}