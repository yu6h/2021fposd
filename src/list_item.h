#pragma once
#include"article.h"
#include<string>


class ListItem : public Article {
   public:
    ListItem(std::string text): Article(0,text){}

    std::string getText() const override{
        return "- "+_text;
    }

    void add(Article* dpFormat) override{
        throw std::string("method not allowed");
    }
};