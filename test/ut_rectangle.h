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
    EXPECT_THROW(new Rectangle(-8,5),std::invalid_argument);
    EXPECT_THROW(new Rectangle(8,0),std::invalid_argument);
    EXPECT_THROW(new Rectangle(0,5),std::invalid_argument);
    EXPECT_THROW(new Rectangle(0,0),std::invalid_argument);
}
