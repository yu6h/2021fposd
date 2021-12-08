#include "./shape_parser.h"
#include "./scanner.h"
#include <string>
#include <iostream>
#include <typeinfo>
int main()
{
    // Example
    std::string input = "I Circle eee ,tt{t0.14159a";
    std::string input2 = "CompoundShape{\n"
                         "  Circle (1.0)\n"
                         "  Rectangle (3.14 4.00)\n"
                         "  Triangle ([3,0] [0,4])\n"
                         "}\n";
    Scanner scanner(input2);
    // std::string first = scanner.next();      // `first` is "Circle"
    // std::cout<<first<<std::endl;
    // std::string second = scanner.next();     // `second` is ","
    // std::cout<<second<<std::endl;
    // double third = scanner.nextDouble();     // `third` is 3.14159
    // std::cout<<std::stod("56")<<std::endl;
    std::cout << scanner.next() << std::endl;
    std::cout << scanner.next() << std::endl;
    std::cout << scanner.next() << std::endl;
    std::cout << scanner.nextDouble() << std::endl;
    std::cout << scanner.next() << std::endl;
    std::cout << scanner.next() << std::endl;
    std::cout << scanner.nextDouble() << std::endl;
    std::cout << scanner.nextDouble() << std::endl;
    std::cout << scanner.next() << std::endl;
    std::cout << scanner.next() << std::endl;
    std::cout << scanner.nextDouble() << std::endl;
    std::cout << scanner.nextDouble() << std::endl;
    std::cout << scanner.nextDouble() << std::endl;
    std::cout << scanner.nextDouble() << std::endl;
    std::cout << scanner.next() << std::endl;
    std::cout << scanner.next() << std::endl;
    std::cout << scanner.next() << std::endl;


    return 0;
}