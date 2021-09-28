bin/test: test/test.cpp# what
	g++ -std=c++11 test/test.cpp -o bin/test -lgtest -lpthread