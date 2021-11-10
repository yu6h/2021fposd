#pragma once
#include<string>
#include"article.h"
#include<typeinfo>
#include<vector>
#include"iterator/compound_iterator.h"
#include"visitor/article_visitor.h"

class Paragraph : public Article {
    private:
        std::vector<Article*> articles;
   public:
    Paragraph(int level, std::string text):Article(level,text)
    {
        if(!(level>=1 && level<=6))throw std::string("Paragraph Constructor:wrong level parameter");
    }

    ~Paragraph() {}
    std::string getHtml() const override {
        return std::string("<");
    }
    std::string getText() const override {
        std::string textOfParagraph;
        for(int i=0;i<_level;i++)textOfParagraph.append("#");
        textOfParagraph.append(" ");
        textOfParagraph.append(_text);
        textOfParagraph.append("\n");

        
        for(int i=0;i<articles.size();i++){

            textOfParagraph.append(articles[i]->getText());

            if(i!= articles.size()-1)textOfParagraph.append("\n");
        }
        return textOfParagraph;
    }




    Iterator* createIterator() override {
        return new CompoundIterator<std::vector<Article*>::iterator>(articles.begin(),articles.end());
    }

    void add(Article* content) override {
        if(typeid(*content)==typeid(Paragraph)){
            if(this->_level >= static_cast<Paragraph*>(content)->getLevel()){
                throw std::string("cannot be added to this paragraph");
            };
        }
        articles.push_back(content);
    }

    void accept(ArticleVisitor* visitor) override {
        visitor->visitParagraph(this);
    }
};