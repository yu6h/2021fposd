#pragma once
#include"../../src/iterator/compound_iterator.h"
#include<gtest/gtest.h>
#include"../../src/text.h"
#include"../../src/list_item.h"
#include"../../src/paragraph.h"
#include"../../src/iterator/null_iterator.h"
TEST(CaseCompoundIterator, Iterator) {
    Paragraph p(1, "title");
    ListItem* l1 = new ListItem("list1");
    ListItem* l2 = new ListItem("list2");
    Text* t1 = new Text("text");

    p.add(l1);
    p.add(l2);
    p.add(t1);

    Paragraph* p2 = new Paragraph(2, "title2");

    ListItem* l3 = new ListItem("list3");
    ListItem* l4 = new ListItem("list4");
    Text* t2 =  new Text("sub text");

    p2->add(l3);
    p2->add(l4);
    p2->add(t2);

    p.add(p2);



    Iterator* it0 = p.createIterator();
    it0->first();
    EXPECT_EQ(l1, it0->currentItem());

    it0->next();
    EXPECT_EQ(l2, it0->currentItem());

    it0->next();
    EXPECT_EQ(t1, it0->currentItem());

    it0->next();
    EXPECT_EQ(p2, it0->currentItem());

    it0->next();
    EXPECT_TRUE(it0->isDone());

    delete it0;


}