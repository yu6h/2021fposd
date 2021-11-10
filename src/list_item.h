#pragma once
#include"article.h"
#include<string>
#include"iterator/null_iterator.h"
#include"visitor/article_visitor.h"

class ListItem : public Article {
   public:
    ListItem(std::string text): Article(0,text){}

    std::string getText() const override{
        return "- "+_text;
    }

    void add(Article* dpFormat) override{
        throw std::string("method not allowed");
    }

    Iterator* createIterator() override {
        return new NullIterator();
    }

    void accept(ArticleVisitor* visitor) override {
        visitor->visitListItem(this);
    }
};