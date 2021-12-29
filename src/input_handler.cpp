#include "input_handler.h"
#include <iostream>
#include <fstream>
void InputHandler::handle()
{
    do
    {
        printEditorInstructions();
        int instruction = inputOnlyNumber();
        handleEditorInstructions(instruction);
    } while (isContinued);
}
int InputHandler::inputOnlyNumber()
{
    int instruction;
    while (!(std::cin >> instruction))
    {
        std::cout << "Invalid argument. Please try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }
    return instruction;
}
void InputHandler::printEditorInstructions()
{
    std::cout << "Please enter the following instruction number number to start building: \n"
                 "1. 'add circle': to add a circle\n"
                 "2. 'add rectangle': to add a rectangle\n"
                 "3. 'add triangle': to add a triangle\n"
                 "4. 'add compound': to add a compound\n"
                 "5. 'save': output shape to file\n"
                 "6. 'exit': to exit the program"
              << std::endl;
}

void InputHandler::handleEditorInstructions(int instruction)
{
    switch (instruction)
    {
    case ChoiceAddCircle:
        addCircle();
        break;
    case ChoiceAddRectangle:
        addRectangle();
        break;
    case ChoiceAddTriangle:
        addTriangle();
        break;
    case ChoiceCompound:
        addCompound();
        break;
    case ChoiceSave:
        save();
        break;
    case ChoiceExit:
        isContinued = false;
        break;
    default:
        std::cout << "Invalid argument. Please try again." << std::endl;
        break;
    }
}

void InputHandler::save()
{
    std::string filename;
    std::fstream outputFile;
    std::cout << "Please enter the file name to save the shape:" << std::endl;
    std::cin.ignore(100, '\n');
    std::getline(std::cin, filename);
    outputFile.open(filename.append(".txt"), std::ios::out);

    // Shape *shape = builder->getShape();
    ShapeInfoVisitor visitor;
    builder->getShape()->accept(&visitor);
    // shape->accept(&visitor);

    if (outputFile.is_open())
    {
        outputFile << visitor.getResult();
        outputFile.close();
        builder->reset();
        std::cout << "Save complete." << std::endl;
    }
    else
    {
        std::cout << "Save failed." << std::endl;
    }

}

void InputHandler::addCircle()
{
    double radius;
    std::cout << "Please enter the information of circle:" << std::endl;
    std::cout << "Radius of circle:" << std::endl;
    std::cin >> radius;
    try
    {
        builder->buildCircle(radius);
        std::cout << "Circle added." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Invalid instruction. Please try again." << std::endl;
    }
}

void InputHandler::addRectangle()
{
    double length, width;
    std::cout << "Please enter the information of rectangle:" << std::endl;
    std::cout << "Width of rectangle:" << std::endl;
    std::cin >> width;
    std::cout << "Length of rectangle:" << std::endl;
    std::cin >> length;
    try
    {
        builder->buildRectangle(length, width);
        std::cout << "Rectangle added." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Invalid instruction. Please try again." << std::endl;
    }
    
}

void InputHandler::addTriangle()
{
    double X1, Y1, X2, Y2;
    std::cout << "Please enter the information of triangle:" << std::endl;
    std::cout << "X1 of triangle:" << std::endl;
    std::cin >> X1;
    std::cout << "Y1 of triangle:" << std::endl;
    std::cin >> Y1;
    std::cout << "X2 of triangle:" << std::endl;
    std::cin >> X2;
    std::cout << "Y2 of triangle:" << std::endl;
    std::cin >> Y2;
    try
    {
        builder->buildTriangle(X1, Y1, X2, Y2);
        std::cout << "Triangle added." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Invalid instruction. Please try again." << std::endl;
    }
}

void InputHandler::printCompoundInstructions()
{
    std::cout << "Please enter the following instruction number to build the compound:\n"
                 "1. 'add circle': to add a circle\n"
                 "2. 'add rectangle': to add a rectangle\n"
                 "3. 'add triangle': to add a triangle\n"
                 "4. 'add compound': to add a compound\n"
                 "5. 'exit': to exit the program"
              << std::endl;
}

void InputHandler::handleCompoundInstructions(int instruction)
{

    switch (instruction)
    {
    case ChoiceAddCircle:
        addCircle();
        break;
    case ChoiceAddRectangle:
        addRectangle();
        break;
    case ChoiceAddTriangle:
        addTriangle();
        break;
    case ChoiceCompound:
        builder->buildCompoundBegin();
        compoundLevel++;
        break;
    case ChoiceExitCompound:
        builder->buildCompoundEnd();
        compoundLevel--;
        break;
    default:
        std::cout << "Invalid instruction. Please try again." << std::endl;
        break;
    }
}

void InputHandler::addCompound()
{
    builder->buildCompoundBegin();
    compoundLevel++;
    do
    {
        printCompoundInstructions();
        int instruction = inputOnlyNumber();
        handleCompoundInstructions(instruction);
    } while (compoundLevel > 0);
    std::cout << "Compound added." << std::endl;
}