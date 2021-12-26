#pragma once

#include <iostream>
#include <string>

#include "./builder/shape_builder.h"
#include "./builder/shape_parser.h"
#include "./visitor/shape_info_visitor.h"

class InputHandler
{
public:
    InputHandler():builder(ShapeBuilder::getInstance()),isContinued(true),compoundLevel(0){}
    enum Choice
    {
        ChoiceAddCircle = 1,
        ChoiceAddRectangle,
        ChoiceAddTriangle,
        ChoiceCompound,
        ChoiceSave,
        ChoiceExitCompound = 5,
        ChoiceExit
    };
    void handle();

private:
    void printEditorInstructions();
    void handleEditorInstructions(int instruction);
    void save();
    void addCircle();
    void addRectangle();
    void addTriangle();
    void printCompoundInstructions();
    void handleCompoundInstructions(int instruction);
    void addCompound();
    int getInstruction();

    ShapeBuilder *builder;
    bool isContinued;
    int compoundLevel;
};