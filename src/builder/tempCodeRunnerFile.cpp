   ShapeBuilder *builder = ShapeBuilder::getInstance();
    // ShapeBuilder::xx = 0;
    builder->buildCompoundBegin();
    builder->buildCircle(2);
    builder->buildRectangle(3,6);
    builder->buildCompoundEnd();

    Shape* shape = builder->getShape();

    ShapeInfoVisitor visitor;
    shape->accept(&visitor);
    // delete builder;
    ShapeBuilder *hahaha = ShapeBuilder::getInstance();

    ShapeInfoVisitor visitor2;
    shape->accept(&visitor2);
    std::cout<<visitor2.getResult()<<std::endl;
    // delete hahaha;