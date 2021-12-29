#pragma once

TEST(CaseCompoundIterator, Iterator) {
    CompoundShape* cs1 = new CompoundShape();
    Circle* c1 = new Circle(1.1);
    Rectangle* r1 = new Rectangle(3.14 ,4);

    cs1->addShape(c1);
    cs1->addShape(r1);

    CompoundShape* cs2 = new CompoundShape();
    Circle* c2 = new Circle(12.34567);
    cs2->addShape(c2);
    cs2->addShape(cs1);

    //測試cs1的CompoundIterator
    Iterator* it0 = cs1->createIterator();
    it0->first();
    EXPECT_EQ(c1, it0->currentItem());

    it0->next();
    EXPECT_EQ(r1, it0->currentItem());

    it0->next();
    EXPECT_TRUE(it0->isDone());

    delete it0;
    //測試cs2的CompoundIterator
    Iterator* it = cs2->createIterator();
    it->first();
    EXPECT_EQ(c2, it->currentItem());

    it->next();
    EXPECT_EQ(cs1, it->currentItem());

    it->next();
    EXPECT_TRUE(it->isDone());

    try{
        it->next();
        FAIL();
    }catch(std::string e){
        EXPECT_EQ("This CompoundIterator is in the end",e);
    }

    try{
        it->currentItem();
        FAIL();
    }catch(std::string e){
        EXPECT_EQ("This CompoundIterator is in the end",e);
    }
    delete it;
    

    // delete cs1;
    // delete c1;
    // delete r1;
    delete cs2;
    // delete c2;
}
