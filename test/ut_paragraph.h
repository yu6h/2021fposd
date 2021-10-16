#pragma once
#include<gtest/gtest.h>
#include"../src/paragraph.h"
#include"../src/iterator.h"
#include"../src/list_item.h"
#include"../src/text.h"
class CaseParagraph: public ::testing::Test{
    protected:
        Paragraph* p;
        void SetUp() override{
            p = new Paragraph(1,"title");
        }
        void TearDown() override{
            delete p;
        }
};
TEST_F(CaseParagraph,Level){
    EXPECT_EQ(1,p->getLevel());
}
TEST_F(CaseParagraph,Text){
    Paragraph p(1, "title");
    p.add(new ListItem("list1"));
    p.add(new ListItem("list2"));
    p.add(new Text("text"));

    EXPECT_EQ("#title\n-list1\n-list2\ntext",p.getText());

    Paragraph* p2 = new Paragraph(2, "title2");
    p2->add(new ListItem("list3"));
    p2->add(new ListItem("list4"));
    p2->add(new Text("sub text"));
    p.add(p2);

    EXPECT_EQ("#title\n-list1\n-list2\ntext\n##title2\n-list3\n-list4\nsub text",p.getText());

}
TEST_F(CaseParagraph,Exception){
    EXPECT_ANY_THROW(new Paragraph(0,"dfdsa"));
    EXPECT_ANY_THROW(new Paragraph(7,"dadfadgd"));
}
/**
TEST_F(CaseParagraph, Iterator){
    Paragraph ss(1, "title");

    Iterator it = ss.createIterator();

    ListItem* s1 = new ListItem("list1");
    ListItem* s2 = new ListItem("list1");
    Text* s3 = new Text("text");

    ss.add(s1);
    ss.add(s2);
    ss.add(s3);

    it.first();
    EXPECT_EQ(s1,it.currentItem());
    it.next();
    EXPECT_EQ(s2,it.currentItem());
    it.next();
    EXPECT_EQ(s3,it.currentItem());
    it.next();
    EXPECT_TRUE(it.isDone());

}
*/