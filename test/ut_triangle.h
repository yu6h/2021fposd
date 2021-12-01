#pragma once
#include<gtest/gtest.h>
#include"../src/triangle.h"
#include"../src/two_dimensional_vector.h"
#include <cmath>
class CaseTriangle: public ::testing::Test {
    protected:
        Triangle* triangle;
    void SetUp() override{
        triangle = new Triangle(TwoDimensionalVector(3,12.433),TwoDimensionalVector(17.56789,-4));
    }
    void TearDown() override{
        delete triangle;
    }
};
TEST_F(CaseTriangle,Area){
    EXPECT_NEAR(115.210788185,triangle->area(),0.001);
    EXPECT_NEAR(6,Triangle(TwoDimensionalVector(3,0),TwoDimensionalVector(0,4)).area(),0.001);
}
TEST_F(CaseTriangle,Perimeter){
    EXPECT_NEAR(52.7679085294,triangle->perimeter(),0.001);
    EXPECT_NEAR(12,Triangle(TwoDimensionalVector(3,0),TwoDimensionalVector(0,4)).perimeter(),0.001);
}
TEST_F(CaseTriangle,Exception){
    EXPECT_THROW(Triangle(TwoDimensionalVector(3,12.433),TwoDimensionalVector(6,24.866)),std::invalid_argument);
    EXPECT_THROW(Triangle(TwoDimensionalVector(3,12.433),TwoDimensionalVector(-6,-24.866)),std::invalid_argument);
    EXPECT_NO_THROW(Triangle(TwoDimensionalVector(3,12.433),TwoDimensionalVector(-6,-25.866)));
    try{
        Triangle tri2(TwoDimensionalVector(3,0),TwoDimensionalVector(0,4));
        Triangle tri2_1(TwoDimensionalVector(3,0),TwoDimensionalVector(0,4));
        tri2.addShape(&tri2_1);
        FAIL();
    }catch(const char* e){
        ASSERT_STREQ("can't add shape", e);
    }
    try{
        Triangle tri3(TwoDimensionalVector(3,0),TwoDimensionalVector(0,4));
        Triangle tri3_1(TwoDimensionalVector(3,0),TwoDimensionalVector(0,4));
        tri3.deleteShape(&tri3_1);
        FAIL();
    }catch(const char* e){
        ASSERT_STREQ("can't delete shape", e);
    }
}
TEST_F(CaseTriangle,Info){
    EXPECT_EQ("Triangle ([3.00,12.43] [17.57,-4.00])",triangle->info());
}
TEST_F(CaseTriangle,CreateIterator){
    Iterator* it = triangle->createIterator();
    EXPECT_TRUE(typeid(*it)==typeid(NullIterator));
    delete it;
}