#pragma once
#include<gtest/gtest.h>
#include "../src/rectangle.h"
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
}
TEST_F(CaseRectangle, Perimeter){
    EXPECT_NEAR(15.28,rectangle->perimeter(),0.001);
}
TEST_F(CaseRectangle, Info){
    EXPECT_EQ("Rectangle (3.14 4.50)",rectangle->info());
}
TEST_F(CaseRectangle, Exception){
    EXPECT_THROW(new Rectangle(-8,5),Rectangle::SideLengthLessThanZeroError);
}

