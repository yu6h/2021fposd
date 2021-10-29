#pragma once
#include"iterator.h"
#include<string>
class NullIterator : public Iterator {
public:
    void first() override { throw std::string("This method is not allowed! Because NullIterator doesn't point to any address.");}

    Shape* currentItem() const override { throw std::string("This method is not allowed! Because NullIterator doesn't point to any address.");}

    void next() override { throw std::string("This method is not allowed! Because NullIterator doesn't point to any address.");}

    bool isDone() const override {
        return true;
    }
};