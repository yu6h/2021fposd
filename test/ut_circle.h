#pragma once
#include<gtest/gtest.h>
#include "../src/circle.h"
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
}
TEST_F(CaseCircle,Perimeter){
    double r =1.1;
    EXPECT_NEAR(2*r*M_PI,circle->perimeter(),0.001);
}
TEST_F(CaseCircle,Info){
    EXPECT_EQ("Circle (1.10)",circle->info());
}
TEST_F(CaseCircle,Exception){
    EXPECT_THROW(new Circle(-5),Circle::LessThanZeroError);
}