#include <stdlib.h>
#include <iostream>
#include <gtest/gtest.h>


int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS( );
}

TEST(Sanity, First){
    ASSERT_TRUE(true);
}