#pragma once
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


    Circle c(10.0);
    Iterator* cc = c.createIterator();
    ASSERT_TRUE(typeid(*cc)==typeid(NullIterator));
    delete cc;

    Rectangle r(10.0,80.0);
    Iterator* rr = r.createIterator();
    ASSERT_TRUE(typeid(*rr)==typeid(NullIterator));
    delete rr;

    Triangle t(TwoDimensionalVector(3,0),TwoDimensionalVector(0,4));
    Iterator* tt = t.createIterator();
    ASSERT_TRUE(typeid(*tt)==typeid(NullIterator));
    delete tt;
}
