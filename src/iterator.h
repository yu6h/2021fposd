#pragma once
#include"article.h"
class Iterator{
    private:
    Article* _begin;
    Article* _end;
    Article* _current;
    public:
    Iterator(Article* begin,Article* end):_begin(begin),_end(end){}

    void first(){
        _current = _begin;
    }
    Article* currentItem(){
        return _current;
    }
    void next(){
        _current++;
    }
    bool isDone(){
        return _current==_end;
    }
};