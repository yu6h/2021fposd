#pragma once
#include<gtest/gtest.h>
#include"../src/paragraph.h"
#include"../src/list_item.h"
#include"../src/text.h"
class CaseParagraph: public ::testing::Test{
    protected:
        Paragraph* p;
        Paragraph* p2;
        void SetUp() override{
            p = new Paragraph(1,"title");
            p2 = new Paragraph(2, "title2");

            p->add(new ListItem("list1"));
            p->add(new ListItem("list2"));
            p->add(new Text("text"));

            p2->add(new ListItem("list3"));
            p2->add(new ListItem("list4"));
            p2->add(new Text("sub text"));

            p->add(p2);
        }
        void TearDown() override{
            delete p;
            // delete p2;
        }
};
TEST_F(CaseParagraph,Level){
    EXPECT_EQ(1,p->getLevel());
    EXPECT_EQ(6,Paragraph(6,"test").getLevel());
    EXPECT_EQ(5,Paragraph(5,"another meaningless test").getLevel());
}
TEST_F(CaseParagraph,Text){
 

    EXPECT_EQ(
    "title",p->getText());

    Paragraph wakanda(6, "wakanda forever");
    EXPECT_EQ("wakanda forever",wakanda.getText());

    Paragraph *cap= new Paragraph(3, "I cannot do this all day!!");
    EXPECT_EQ("I cannot do this all day!!",cap->getText());

    delete cap;
    EXPECT_EQ(
    "title2",p2->getText());
}
TEST_F(CaseParagraph,Exception){
    EXPECT_ANY_THROW(Paragraph(0,"I am Loki of Asgard and I am burdened with glorious purpose meaning"));
    EXPECT_ANY_THROW(Paragraph(7,"Mr.Stark I don't feel so good"));
    
    Paragraph *err = new Paragraph(1,"dsafsad");
    EXPECT_ANY_THROW(p2->add(err));
    delete err;
    
    EXPECT_NO_THROW(p2->add(new Paragraph(6,"xxxxx")));
}
