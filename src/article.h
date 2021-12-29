
#pragma once
#include<string>
class Iterator;
class ArticleVisitor;
class Article {
    protected:
    int _level;
    std::string _text;
   public:
    virtual ~Article(){};

    Article(int level,std::string text):_level(level),_text(text){}

    virtual std::string getText() const = 0;

    virtual std::string getTextAttribute() const {return _text;}

    virtual int getLevel() const {return _level;}

    virtual Iterator* createIterator() = 0;

    virtual void accept(ArticleVisitor* visitor) = 0;

    virtual void add(Article* dpFormat){};
};