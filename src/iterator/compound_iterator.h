#pragma once
#include"null_iterator.h"
#include<list>
#include<vector>
#include <typeinfo>



template<class ForwardIterator>
class CompoundIterator : public Iterator {
    private:
    ForwardIterator _current;
    ForwardIterator _begin;
    ForwardIterator _end;
   public:
    CompoundIterator(ForwardIterator begin, ForwardIterator end):_begin(begin),_end(end)
    {
        first();
    }

    void first() override {
        _current = _begin;
    }

    Article* currentItem() const override {
        if(isDone())throw(std::string("This CompoundIterator is in the end"));
        return *_current;
    }

    void next() override 
    {
        if(isDone())throw(std::string("This CompoundIterator is in the end"));
        _current++;
    }

    bool isDone() const override { return _current == _end;}
};
