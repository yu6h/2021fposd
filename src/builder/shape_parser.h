#pragma once
#include<fstream>
#include<iostream>
#include"./shape_builder.h"
#include"./scanner.h"
#include"./shape_builder.h"
class ShapeParser{
    private:
    std::fstream myFile;
    std::string text;
    Shape* _shape;
    Scanner* _scanner;
    ShapeBuilder* _builder;
public:
    // `filePath` is a relative path of makefile
    ShapeParser(std::string filePath):_shape(nullptr),text("")
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
            std::cout<<"fail"<<std::endl;
        }
        std::cout<<text<<std::endl;
        _scanner = new Scanner(text);
        _builder = new ShapeBuilder();
    }

    ~ShapeParser() 
    {
        delete _scanner;
        delete _builder;
    }

    void parse() 
    {
        while(!_scanner->isDone()){
            std::string token = _scanner->next();
            if(token == "Circle"){
                // std::cout<<"找到cir"<<std::endl;
                _builder->buildCircle(_scanner->nextDouble());
                // std::cout<<"endcir"<<std::endl;
            }else if(token == "Rectangle"){
                // std::cout<<"找到rect"<<std::endl;
                _builder->buildRectangle(_scanner->nextDouble(),_scanner->nextDouble());
                // std::cout<<"endrect"<<std::endl;
            }else if(token == "Triangle"){
                std::cout<<"找到tri"<<std::endl;
                _builder->buildTriangle(_scanner->nextDouble(),_scanner->nextDouble(),_scanner->nextDouble(),_scanner->nextDouble());
                _scanner->next();
                _scanner->next();
                std::cout<<"endtri"<<std::endl;
            }else if(token == "CompoundShape"){
                _scanner->next(); // ignore {
                _builder->buildCompoundBegin();
            }else if(token == "}"){
                _builder->buildCompoundEnd();
            }
        }
        _shape = _builder->getShape();

    }

    Shape* getShape() {return _shape;}
};
