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
    EXPECT_EQ(0,ListItem("Wakanda Forever!!!").getLevel());
}
TEST_F(CaseListItem,Text){
    EXPECT_EQ("list1",x->getText());
    EXPECT_EQ("Wakanda Forever!!!",ListItem("Wakanda Forever!!!").getText());
}

TEST_F(CaseListItem,Exception){
    Article *err1 = new ListItem("hahahaha");
    EXPECT_ANY_THROW(x->add(err1));
    EXPECT_NO_THROW(x->getLevel());
    EXPECT_NO_THROW(x->getText());
    delete err1;
}