#pragma once
#include<gtest/gtest.h>
#include"../src/list_item.h"

class CaseListItem: public ::testing::Test{
    protected:
        ListItem* x;
        void SetUp() override{
            x = new ListItem("list1");
        }
        void TearDown() override{
            delete x;
        }
};
TEST_F(CaseListItem,Level){
    EXPECT_EQ(0,x->getLevel());
}
TEST_F(CaseListItem,Text){
    EXPECT_EQ("- list1",x->getText());
}
TEST_F(CaseListItem,Exception){
    EXPECT_ANY_THROW(x->add(new ListItem("adfoasdfwe")));
}