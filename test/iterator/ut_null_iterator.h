#pragma once
#include"../../src/iterator/null_iterator.h"
#include<gtest/gtest.h>


TEST(CaseNullIterator, NullIterator){
    Iterator* it = new NullIterator();
    ASSERT_TRUE(it->isDone());

    try{
        it->first();
        FAIL();
    }catch(std::string e){
        ASSERT_EQ("This method is not allowed! Because NullIterator doesn't point to any address."
        ,e);
    }
    try{
        it->currentItem();
        FAIL();
    }catch(std::string e){
        ASSERT_EQ("This method is not allowed! Because NullIterator doesn't point to any address."
        ,e);
    }
    try{
        it->first();
        FAIL();
    }catch(std::string e){
        ASSERT_EQ("This method is not allowed! Because NullIterator doesn't point to any address."
        ,e);
    }
    delete it;


    Text text("ddfasdfsdf");
    Iterator* cc = text.createIterator();
    ASSERT_TRUE(cc->isDone());
    delete cc;

    ListItem listItem("i am listitem");
    Iterator* rr = listItem.createIterator();
    ASSERT_TRUE(rr->isDone());
    delete rr;
}
