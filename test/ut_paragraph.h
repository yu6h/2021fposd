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
        }
        void TearDown() override{
            delete p;
            delete p2;
        }
};
TEST_F(CaseParagraph,Level){
    EXPECT_EQ(1,p->getLevel());
    EXPECT_EQ(6,Paragraph(6,"test").getLevel());
    EXPECT_EQ(5,Paragraph(5,"another meaningless test").getLevel());
}
TEST_F(CaseParagraph,Text){

    p->add(new ListItem("list1"));
    p->add(new ListItem("list2"));
    p->add(new Text("text"));

    EXPECT_EQ("# title\n- list1\n- list2\ntext",p->getText());

 
    p2->add(new ListItem("list3"));
    p2->add(new ListItem("list4"));
    p2->add(new Text("sub text"));
    p->add(p2);

    EXPECT_EQ(
    "# title\n"
    "- list1\n"
    "- list2\n"
    "text\n"
    "## title2\n"
    "- list3\n"
    "- list4\n"
    "sub text",p->getText());

    Paragraph wakanda(6, "wakanda forever");
    EXPECT_EQ("###### wakanda forever\n",wakanda.getText());

    Paragraph cap(3, "I cannot do this all day!!");
    EXPECT_EQ("### I cannot do this all day!!\n",cap.getText());

    p2->add(&cap);
    EXPECT_EQ(
    "# title\n"
    "- list1\n"
    "- list2\n"
    "text\n"
    "## title2\n"
    "- list3\n"
    "- list4\n"
    "sub text\n"
    "### I cannot do this all day!!\n",p->getText());
}
TEST_F(CaseParagraph,Exception){
    EXPECT_ANY_THROW(new Paragraph(0,"I am Loki of Asgard and I am burdened with glorious purpose meaning"));
    EXPECT_ANY_THROW(new Paragraph(7,"Mr.Stark I don't feel so good"));
    EXPECT_NO_THROW(p2->add(new Paragraph(6,"xxxxx")));
    EXPECT_ANY_THROW(p2->add(new Paragraph(1,"dsafsad")));

}
