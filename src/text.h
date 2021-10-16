#pragma once
#include<string>
#include"article.h"
class Text : public Article {

   public:
    Text(std::string text):Article(0,text) {}

    std::string getText() const override {return _text;}

    void add(Article* dpFormat) override{
        throw std::string("method not allowed");
    }
};