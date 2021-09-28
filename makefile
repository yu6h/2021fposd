bin/ut_all: test/test.cpp test/test_square.h# what
	g++ -std=c++11 test/test.cpp -o bin/ut_all --gtest_output=xml:result.xml -lgtest -lpthread