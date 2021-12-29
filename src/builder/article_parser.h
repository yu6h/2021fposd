
#pragma once
#include<fstream>
#include<iostream>
#include "./article_builder.h"
#include "./article_scanner.h"
#include "../article.h"
class ShapeParser{
    private:
    std::fstream myFile;
    std::string text;
    Article* _article;
    ArticleScanner* _scanner;
    ArticleBuilder* _builder;
public:
    // `filePath` is a relative path of makefile
    ShapeParser(std::string filePath):_article(nullptr),text("")
    {
        std::string line;
        myFile.open(filePath,std::ios::in);
        if(myFile.is_open()){
            while(getline(myFile,line)){
                text.append(line).append("\n");//
            }
            myFile.close();
        }
        else{
            std::cout<<"fail to read file"<<std::endl;
        }
        // std::cout<<text<<std::endl;
        _scanner = new ArticleScanner(text);
        _builder = ArticleBuilder::getInstance();
    }
    std::string getText(){
        return text;
    }

    ~ShapeParser() 
    {
        delete _scanner;
        // delete _builder;
    }

    void parse() 
    {
        while(!_scanner->isDone()){
            std::string token = _scanner->nextToken();
            if(token == "Text"){
                std::string t = _scanner->nextStr();
                _builder->buildText(t);
            }else if(token == "ListItem"){
                std::string t = _scanner->nextStr();
                _builder->buildListItem(t);
            }else if(token == "Paragraph"){
                int i1 = _scanner->nextInt();
                std::string t = _scanner->nextStr();
                _builder->buildParagraphBegin(i1,t);
            }else if(token == "}"){
                _builder->buildParagraphEnd();
            }
        }
        _article = _builder->getArticle();

    }

    Article* getArticle() {return _article;}
};
