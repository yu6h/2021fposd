
#pragma once
#include<string>
class Article {
    protected:
    int _level;
    std::string _text;

   public:

    virtual ~Article(){};

    Article(int level,std::string text):_level(level),_text(text){}

    virtual std::string getText() const = 0;

    virtual int getLevel() const {return _level;}

    virtual void add(Article* dpFormat){};
};