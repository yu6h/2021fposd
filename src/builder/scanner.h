#pragma once
#include <string>
#include <vector>
#include "../shape.h"
#include <regex>
#include <iostream>
class Scanner
{
public:
    Scanner(std::string input) : _input(input) {}

    std::string next()
    {
        std::string result = "";
        bool foundIt = false;
        if(isDone())throw std::invalid_argument("It is already in the end.");
        do 
        {
            for (auto token : tokenList)
            {
                if (_input.compare(pos, token.length(), token) == 0)
                {
                    pos = pos + token.length();
                    result = token;
                    foundIt = true;
                    break;
                }
            }
            if (foundIt)
                break;
            else
                pos++;
        }while(!isDone());

        return result;
    }

    void skipWhiteSpace()
    {
        while (_input[pos] == ' ' || _input[pos] == '\n'|| _input[pos] == '\t')
        {
            pos++;
        }
    }

    double nextDouble()
    {
        std::string s = "";
        if(isDone()) throw std::invalid_argument("It is already in the end.");
        while (!isDone() && !(_input[pos] <= '9' && _input[pos] >= '0'))pos++;
        while (pos != _input.length())
        {
            if ((_input[pos] <= '9' && _input[pos] >= '0') || _input[pos] == '.')
            {
                s = s + _input[pos];
                pos++;
            }
            else
            {
                break;
            }
        }
        return std::stod(s);
    }

    bool isDone()
    {
        skipWhiteSpace();
        return pos == _input.length();
    }

private:
    const std::vector<std::string> tokenList = {"Circle", "Rectangle", "Triangle", "CompoundShape", "(", ")", "[", "]", "{", "}", ","};
    std::string _input;
    std::string::size_type pos = 0;
};
