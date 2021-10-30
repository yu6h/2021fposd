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
    
    std::vector<Shape*> myList;
    std::vector<Shape*>::iterator it;
    int index;
    
public:
    CompoundIterator(ForwardIterator begin, ForwardIterator end):_begin(begin),_end(end)
    {
        myList.assign(begin,end);
        index=0;
    }

    void first() override 
    {
        it = myList.begin();
        index=0;
    }

    Shape* currentItem() const override {
        return *it;
    }

    void next() override 
    {
        if(typeid(*it)==typeid(CompoundShape)){
            Iterator* x = (*it)->createIterator();
            x->first();
            int i = 0;
            while(!x->isDone()){
                myList.insert(it + (i++),x->currentItem());
                x->next();
            }
            delete x;
        }
        it++;     

    }

    bool isDone() const override { return it == myList.end();}
};