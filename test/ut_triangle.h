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
    EXPECT_THROW(new Triangle(TwoDimensionalVector(3,12.433),TwoDimensionalVector(6,24.866)),std::invalid_argument);
    EXPECT_THROW(new Triangle(TwoDimensionalVector(3,12.433),TwoDimensionalVector(-6,-24.866)),std::invalid_argument);
    EXPECT_NO_THROW(new Triangle(TwoDimensionalVector(3,12.433),TwoDimensionalVector(-6,-25.866)));
}
