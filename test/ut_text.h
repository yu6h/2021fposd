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
    EXPECT_ANY_THROW(text->add(new Text("dasd")));
    EXPECT_ANY_THROW(text->add(new ListItem("dfadsf")));
    EXPECT_ANY_THROW(text->add(new Paragraph(3,"dfadsf")));
    EXPECT_NO_THROW(text->getLevel());
    EXPECT_NO_THROW(text->getText());
}