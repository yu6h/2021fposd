#include"./shape_parser.h"
#include"./scanner.h"
#include<string>
#include<iostream>
int main()
{
// Example
    std::string input = "I Circle eee ,tt{t0.14159a";
    Scanner scanner(input);
    std::string first = scanner.next();      // `first` is "Circle"
    std::cout<<first<<std::endl;
    std::string second = scanner.next();     // `second` is ","
    std::cout<<second<<std::endl;
    double third = scanner.nextDouble();     // `third` is 3.14159
    std::cout<<third<<std::endl;


    
    return 0;
}