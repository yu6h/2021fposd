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
                text.append(line).append("\n");
            }
            myFile.close();
        }
        // else{
        //     std::cout<<"fail"<<std::endl;
        // }
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
                _builder->buildCircle(_scanner->nextDouble());
            }else if(token == "Rectangle"){
                _builder->buildRectangle(_scanner->nextDouble(),_scanner->nextDouble());
            }else if(token == "Triangle"){
                _builder->buildTriangle(_scanner->nextDouble(),_scanner->nextDouble(),_scanner->nextDouble(),_scanner->nextDouble());
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
