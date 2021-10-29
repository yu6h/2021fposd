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