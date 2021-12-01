#pragma once
#include<gtest/gtest.h>
#include"../src/two_dimensional_vector.h"
#include <cmath>

class CaseTwoDimensionalVector: public ::testing::Test {
    protected:
        TwoDimensionalVector* vector1;
        TwoDimensionalVector* vector2;
        void SetUp() override{
            vector1 = new TwoDimensionalVector(3.00, 12.433);
            vector2 = new TwoDimensionalVector(17.56789, -4);
        }
        void TearDown() override{
            delete vector1;
            delete vector2;
        }
};
TEST_F(CaseTwoDimensionalVector,Length){

    EXPECT_NEAR(3.00,vector1->x(),0.001);
    EXPECT_NEAR(12.4333,vector1->y(),0.001);
    EXPECT_NEAR(12.7898197407,vector1->length(),0.001);
    EXPECT_NEAR(18.0175125656,vector2->length(),0.001);
    EXPECT_NEAR(21.9605762231,vector1->subtract(*vector2).length(),0.001);
}
TEST_F(CaseTwoDimensionalVector,Info){
    EXPECT_EQ("[3.00,12.43]",vector1->info());
    EXPECT_EQ("[10.00,0.28]",TwoDimensionalVector(10,0.28).info());
}
TEST_F(CaseTwoDimensionalVector,DotProduct){
    EXPECT_NEAR(2.97167,vector1->dot(*vector2),0.001);
    EXPECT_NEAR(0,TwoDimensionalVector(-2,-2).dot(TwoDimensionalVector(-2,2)),0.001);
}
TEST_F(CaseTwoDimensionalVector,CrossProduct){
    EXPECT_NEAR(-230.42157637,vector1->cross(*vector2),0.001);
    EXPECT_NEAR(100,TwoDimensionalVector(10,0).cross(TwoDimensionalVector(0,10)),0.001);
}
TEST_F(CaseTwoDimensionalVector,Subtract){
    TwoDimensionalVector expected(-14.56789,16.433);
    EXPECT_NEAR(expected.x(),vector1->subtract(*vector2).x(),0.001);
    EXPECT_NEAR(expected.y(),vector1->subtract(*vector2).y(),0.001);
}
TEST_F(CaseTwoDimensionalVector,Exeception){
    // EXPECT_THROW(TwoDimensionalVector(0,0),std::invalid_argument);
    EXPECT_NO_THROW(TwoDimensionalVector(0.1,0));
    EXPECT_NO_THROW(TwoDimensionalVector(0,-0.001));
}