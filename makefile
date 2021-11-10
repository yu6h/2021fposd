.PHONY: clean test

all: directories ut_main

TEST= test/ut_paragraph.h test/ut_list_item.h test/ut_text.h test/ut_main.cpp \
	  test/ut_list_item.h test/iterator/ut_null_iterator.h \
	  test/iterator/ut_compound_iterator.h test/visitor/ut_markdown_visitor.h \
	  test/visitor/ut_html_visitor.h
SRC= src/article.h src/list_item.h src/paragraph.h src/text.h \
	 src/iterator/iterator.h src/iterator/compound_iterator.h \
	 src/iterator/null_iterator.h src/visitor/article_visitor.h \
	 src/visitor/html_visitor.h src/visitor/markdown_visitor.h
OBJ = obj/markdown_visitor.o obj/html_visitor.o

ut_main: test/ut_main.cpp $(TEST) $(SRC) $(OBJ)
	g++ -std=c++11 test/ut_main.cpp $(OBJ) -o bin/ut_all -lgtest -lpthread

obj/markdown_visitor.o: src/visitor/markdown_visitor.cpp src/visitor/markdown_visitor.h
	g++ -std=c++11 -Wfatal-errors -Wall -c src/visitor/markdown_visitor.cpp -o obj/markdown_visitor.o

obj/html_visitor.o: src/visitor/html_visitor.cpp src/visitor/html_visitor.h
	g++ -std=c++11 -Wfatal-errors -Wall -c src/visitor/html_visitor.cpp -o obj/html_visitor.o

directories:
	mkdir -p bin

clean:
	rm -rf bin

test: all
	bin/ut_all