// you should define a template class or type `ForwardIterator`
#pragma once
#include"null_iterator.h"
#include<list>
#include<vector>
#include <typeinfo>
class Shape;
class CompoundShape;

template<class ForwardIterator>
class CompoundIterator : public Iterator{
    private:

    ForwardIterator _current;
    ForwardIterator _begin;
    ForwardIterator _end;
    
    
public:
    CompoundIterator(ForwardIterator begin, ForwardIterator end):_begin(begin),_end(end)
    {
        _current = _begin;
    }

    void first() override 
    {
        _current = _begin;
    }

    Shape* currentItem() const override {
        if(isDone())throw(std::string("in the end"));
        return *_current;
    }

    void next() override 
    {
        if(isDone())throw(std::string("in the end"));
        _current++;
    }

    bool isDone() const override { return _current == _end;}
};
//sdfdsfdssdf