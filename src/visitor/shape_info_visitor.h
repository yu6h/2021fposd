#pragma once

#include <string>

#include "../circle.h"
#include "../compound_shape.h"
#include "../rectangle.h"
#include "../triangle.h"
#include "./shape_visitor.h"

class ShapeInfoVisitor : public ShapeVisitor
{
public:
    void visitCircle(Circle *circle)
    {
        result.append(circle->info()).append("\n");
    }
    void visitRectangle(Rectangle *rectangle)
    {
        result.append(rectangle->info()).append("\n");
    }
    void visitTriangle(Triangle *triangle)
    {
        result.append(triangle->info()).append("\n");
    }
    void visitCompoundShape(CompoundShape *compoundShape)
    {
        if(depth == 0) result = "";
        Iterator *it = compoundShape->createIterator();
        depth++;
        result.append("CompoundShape{\n");
        for (it->first(); !it->isDone(); it->next())
        {
            for (int i = 0; i < depth; i++)result.append("  ");
            it->currentItem()->accept(this);
        }
        depth--;
        for (int i = 0; i < depth; i++)result.append("  ");
        result.append("}\n");
    }
    std::string getResult()
    {
        return result;
    }
private:
    int depth = 0;
    std::string result = "";
};