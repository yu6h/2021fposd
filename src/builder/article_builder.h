#pragma once

#include <list>
#include "../paragraph.h"
#include "../text.h"
#include "../list_item.h"
class ArticleBuilder
{
private:
    std::list<Article *> _articles;

    ArticleBuilder() {}

    bool isThisParagraphEmpty(Article* paragraph){
        Iterator* it = paragraph->createIterator();
        if(it->isDone()){
            delete it;
            return true;
        }
        else{
            delete it;
            return false;
        }
        
    }
public:
    ~ArticleBuilder()
    {
        reset();
    }
    static ArticleBuilder *getInstance()
    {
        static ArticleBuilder _instance;
        return &_instance;
    }

    void buildText(std::string text)
    {
        _articles.push_back(new Text(text));
    }

    void buildListItem(std::string text)
    {
        _articles.push_back(new ListItem(text));
    }

    void buildParagraphBegin(int level, std::string text)
    {
        _articles.push_back(new Paragraph(level,text));
    }

    void buildParagraphEnd()
    {
        std::list<Article *> components;
        while (typeid(*_articles.back()) != typeid(Paragraph) || !isThisParagraphEmpty(_articles.back()))
        {
            components.push_front(_articles.back());
            _articles.pop_back();
        }
        Article *paragraph = _articles.back();
        for (auto it = components.begin(); it != components.end(); it++)
        {
            paragraph->add(*it);
        }
    }

    Article *getArticle()
    {
        Article *lastArticle = _articles.back();
        // _shapes.pop_back();
        return lastArticle;
    }

    void reset()
    {
        // while(!_articles.empty()) delete _articles.front(), _articles.pop_front();
        _articles.clear();
    }
};