#pragma once
#include<string>
#include"article.h"
#include<typeinfo>
#include<vector>

class Paragraph : public Article {
    private:
        std::vector<Article*> articles;

   public:
    Paragraph(int level, std::string text):Article(level,text)
    {
        if(!(level>=1 && level<=6))throw std::string("Paragraph Constructor:wrong level parameter");
    }

    ~Paragraph() {

    }

    std::string getText() const override {
        std::string textOfParagraph;
        if(_text.compare("")!=0){
            textOfParagraph.append("# ");
            textOfParagraph.append(_text);
            textOfParagraph.append("\n");
        }
        
        for(int i=0;i<articles.size();i++){
            if (typeid(*(articles[i]))==typeid(Paragraph))
            {
                textOfParagraph.append("#");
            }
            textOfParagraph.append(articles[i]->getText());

            if(i!= articles.size()-1)textOfParagraph.append("\n");
        }
        return textOfParagraph;
    }



    int count() const {
        return articles.size();
    }

    void add(Article* content) override {
        if(typeid(*content)==typeid(Paragraph)){
            if(this->_level >= static_cast<Paragraph*>(content)->getLevel()){
                throw std::string("cannot be added to this paragraph");
            };
        }
        articles.push_back(content);

    }


};