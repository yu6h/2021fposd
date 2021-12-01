#pragma once
#include<gtest/gtest.h>
#include"../src/circle.h"
#include <cmath>
class CaseCircle: public ::testing::Test {
    protected:
        Circle* circle;
        void SetUp() override {
            circle = new Circle(1.10);
        }
        void TearDown() override {
            delete circle;
        }
};

TEST_F(CaseCircle,Area){
    double r =1.1;
    EXPECT_NEAR(r*r*M_PI,circle->area(),0.001);
    EXPECT_NEAR(10*10*M_PI,Circle(10).area(),0.001);
}
TEST_F(CaseCircle,Perimeter){
    double r =1.1;
    EXPECT_NEAR(2*r*M_PI,circle->perimeter(),0.001);
    EXPECT_NEAR(2*10*M_PI,Circle(10).perimeter(),0.001);
}
TEST_F(CaseCircle,Info){
    EXPECT_EQ("Circle (1.10)",circle->info());
    EXPECT_EQ("Circle (11.21)",Circle(11.2111).info());
}
TEST_F(CaseCircle,Exception){

    //
    try{
        Circle cir(-9);
        FAIL();
    }catch(std::invalid_argument e){
        ASSERT_STREQ("radius cannot less or eqal than zero.", e.what());
    }
    try{
        Circle cir0(0);
        FAIL();
    }catch(std::invalid_argument e){
        ASSERT_STREQ("radius cannot less or eqal than zero.", e.what());
    }
    try{
        Circle cir2(5.0);
        Circle cir2_1(5.0);
        cir2.addShape(&cir2_1);
        FAIL();
    }catch(const char* e){
        ASSERT_STREQ("can't add shape", e);
    }
    try{
        Circle cir3(5.0);
        Circle cir3_1(5.0);
        cir3.deleteShape(&cir3_1);
        FAIL();
    }catch(const char* e){
        ASSERT_STREQ("can't delete shape", e);
    }
    EXPECT_THROW(Circle(-5),std::invalid_argument);
    EXPECT_THROW(Circle(0),std::invalid_argument);
    EXPECT_NO_THROW(Circle(0.001));
}

TEST_F(CaseCircle,CreateIterator){
    Iterator* it = circle->createIterator();
    EXPECT_TRUE(typeid(*it)==typeid(NullIterator));
    delete it;
}