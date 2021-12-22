#include <iostream>
#include "./shape_builder.h"
#include "../visitor/shape_info_visitor.h"
int main()
{
    
    // ShapeBuilder builder = ShapeBuilder::getInstance();
    // // ShapeBuilder::xx = 0;
    // builder->buildCompoundBegin();
    // builder->buildCircle(2);
    // builder->buildRectangle(3, 6);
    // builder->buildCompoundEnd();
    // builder->buildCircle(3);
    // Shape *shape = builder->getShape();

    // ShapeInfoVisitor visitor;
    // shape->accept(&visitor);
    // std::cout << "visitor:" << std::endl;
    // std::cout << visitor.getResult() << std::endl;
    // shape = builder->getShape();

    // ShapeBuilder *hahaha = ShapeBuilder::getInstance();
    // hahaha->buildRectangle(11, 22);
    // Shape *shape2 = hahaha->getShape();

    // ShapeInfoVisitor visitor2;

    // shape2->accept(&visitor2);
    // std::cout << "visitor2:" << std::endl;
    // std::cout << visitor2.getResult() << std::endl;

    // Shape *shape3 = hahaha->getShape();

    // shape3->accept(&visitor2);
    // std::cout << "visitor2(shape3):" << std::endl;
    // std::cout << visitor2.getResult() << std::endl;
    // // delete hahaha;
    // std::cout << "test" << std::endl;
    return 0;
}
