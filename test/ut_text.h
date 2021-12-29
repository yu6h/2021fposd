#pragma once
#include<gtest/gtest.h>
#include"../src/text.h"
#include"../src/list_item.h"
#include"../src/paragraph.h"
class CaseText: public ::testing::Test{
    protected:
        Text* text;
        void SetUp() override{
            text = new Text("text");
        }
        void TearDown() override{
            delete text;
        }
};
TEST_F(CaseText,Level){
    EXPECT_EQ(0,text->getLevel());
}
TEST_F(CaseText,Text){
    EXPECT_EQ("text",text->getText());
}
TEST_F(CaseText,Exception){
    Article* err1 = new Text("dasd");
    Article* err2 = new ListItem("dfadsf");
    Article* err3 = new Paragraph(3,"dfadsf");
    EXPECT_ANY_THROW(text->add(err1));
    EXPECT_ANY_THROW(text->add(err2));
    EXPECT_ANY_THROW(text->add(err3));
    EXPECT_NO_THROW(text->getLevel());
    EXPECT_NO_THROW(text->getText());
    delete err1;
    delete err2;
    delete err3;
}