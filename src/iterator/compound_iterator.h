// you should define a template class or type `ForwardIterator`
#pragma once
#include"iterator.h"

template<class ForwardIterator>
class CompoundIterator : public Iterator{
    private:
    ForwardIterator _begin;
    ForwardIterator _end;
    ForwardIterator _current;

public:
    CompoundIterator(ForwardIterator begin, ForwardIterator end): _begin(begin),_end(end){ }

    void first() override { _current=_begin;}

    Shape* currentItem() const override { return *_current;}

    void next() override { _current++;}

    bool isDone() const override { return _current==_end;}
};