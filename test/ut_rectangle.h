#pragma once
#include<gtest/gtest.h>
#include"../src/rectangle.h"
#include<string>
class CaseRectangle: public ::testing::Test {
protected:
    Rectangle* rectangle;
    void SetUp() override{
        rectangle = new Rectangle(3.14,4.5);
    }
    void TearDown() override{
        delete rectangle;
    }
};
TEST_F(CaseRectangle, Area){
    EXPECT_NEAR(14.13,rectangle->area(),0.001);
    EXPECT_NEAR(50,Rectangle(5,10).area(),0.001);
}
TEST_F(CaseRectangle, Perimeter){
    EXPECT_NEAR(15.28,rectangle->perimeter(),0.001);
    EXPECT_NEAR(30,Rectangle(5,10).perimeter(),0.001);    
}
TEST_F(CaseRectangle, Info){
    EXPECT_EQ("Rectangle (3.14 4.50)",rectangle->info());
    EXPECT_EQ("Rectangle (5.00 10.00)",Rectangle(5,10).info());
    EXPECT_EQ("Rectangle (5.33 10.00)",Rectangle(5.333,10).info());
}

TEST_F(CaseRectangle, Exception){

    try{
        Rectangle nrec(-8,5);
        FAIL();
    }catch(std::invalid_argument e){
        ASSERT_STREQ("length and width both cannot less or eqal than zero.", e.what());
    }
    try{
        Rectangle n1rec(8,-5);
        FAIL();
    }catch(std::invalid_argument e){
        ASSERT_STREQ("length and width both cannot less or eqal than zero.", e.what());
    }
    try{
        Rectangle nnrec(-8,-5);
        FAIL();
    }catch(std::invalid_argument e){
        ASSERT_STREQ("length and width both cannot less or eqal than zero.", e.what());
    }
    try{
        Rectangle rec01(0,5);
        FAIL();
    }catch(std::invalid_argument e){
        ASSERT_STREQ("length and width both cannot less or eqal than zero.", e.what());
    }
    try{
        Rectangle rec10(1,0);
        FAIL();
    }catch(std::invalid_argument e){
        ASSERT_STREQ("length and width both cannot less or eqal than zero.", e.what());
    }
    try{
        Rectangle rec00(0,0);
        FAIL();
    }catch(std::invalid_argument e){
        ASSERT_STREQ("length and width both cannot less or eqal than zero.", e.what());
    }
    EXPECT_THROW(Rectangle(8,0),std::invalid_argument);
    EXPECT_THROW(Rectangle(0,5),std::invalid_argument);
    EXPECT_THROW(Rectangle(0,0),std::invalid_argument);
    try{
        Rectangle rec2(5.0,8.0);
        Rectangle rec2_1(5.0,10.0);
        rec2.addShape(&rec2_1);
        FAIL();
    }catch(const char* e){
        ASSERT_STREQ("can't add shape", e);
    }
    try{
        Rectangle rec3(5.0,1.0);
        Rectangle rec3_1(5.0,5.0);
        rec3.deleteShape(&rec3_1);
        FAIL();
    }catch(const char* e){
        ASSERT_STREQ("can't delete shape", e);
    }
}
TEST_F(CaseRectangle,CreateIterator){
    Iterator* it = rectangle->createIterator();
    EXPECT_TRUE(typeid(*it)==typeid(NullIterator));
    delete it;
}
