#pragma once
#include <string>
#include <vector>
#include "../article.h"
#include <iostream>
class ArticleScanner
{
public:
    ArticleScanner(std::string input) : _input(input) {}
    std::string nextToken()
    {
        if(isDone())throw std::invalid_argument("It is already in the end.");
        do 
        {
            for (auto token : tokenList)
            {
                if (_input.compare(pos, token.length(), token) == 0)
                {
                    pos = pos + token.length();
                    return token;
                }
            }
            pos++;
        }while(!isDone());
        return std::string("");
    }

    std::string nextStr() 
    {
        while(_input[pos]!='\"')
        {
            pos++;
            if(pos == _input.length())throw std::invalid_argument("It is already in the end.");
        }
        
        std::string::size_type start = ++pos;
        std::string::size_type len = 0;
        while(_input[pos]!='\"')
        {
            pos++;
            len++;
            if(pos == _input.length())throw std::invalid_argument("It is already in the end.");
        }
        return std::string(_input,start,len);
    }
    void skipWhiteSpace()
    {
        while (_input[pos] == ' ' || _input[pos] == '\n'|| _input[pos] == '\t')
        {
            pos++;
        }
    }

    int nextInt()
    {
        std::string s = "";
        if(isDone()) throw std::invalid_argument("It is already in the end.");
        while (!isDone() && !(_input[pos] <= '9' && _input[pos] >= '0'))pos++;
        while (pos != _input.length())
        {
            if (_input[pos] <= '9' && _input[pos] >= '0')
            {
                s = s + _input[pos];
                pos++;
            }
            else
            {
                break;
            }
        }
        return std::stoi(s);
    }
    bool isDone()
    {
        skipWhiteSpace();
        return pos == _input.length();
    }

private:
    const std::vector<std::string> tokenList = {"ListItem", "Text", "Paragraph", "(", ")", "{", "}"};
    std::string _input;
    std::string::size_type pos = 0;
};
