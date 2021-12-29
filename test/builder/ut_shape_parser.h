#include"../../src/builder/shape_parser.h"
#include"../../src/visitor/shape_info_visitor.h"



TEST(CaseParser, ParseCompound){
    ShapeParser* parser = new ShapeParser(".//test//data//simple_compound.txt");
    parser->parse();
    Shape* hh = parser->getShape();
    // std::cout<<hh->area()<<std::endl;
    ShapeInfoVisitor visitor;
    hh->accept(&visitor);
    EXPECT_EQ("CompoundShape {\n"
                "  Circle (1.00)\n"
                "  Rectangle (3.14 4.00)\n"
                "  Triangle ([3.00,0.00] [0.00,4.00])\n"
                "}\n",visitor.getResult());
    delete parser;
    ShapeParser* parser2 = new ShapeParser(".//test//data//complex_compound.txt");
    parser2->parse();
    Shape* aa = parser2->getShape();
    aa->accept(&visitor);
    EXPECT_EQ("CompoundShape {\n"
            "  Circle (1.00)\n"
            "  Triangle ([3.00,0.00] [0.00,4.00])\n"
            "  CompoundShape {\n"
            "    Circle (1.00)\n"
            "    Rectangle (3.14 4.00)\n"
            "    Triangle ([3.00,0.00] [0.00,4.00])\n"
            "  }\n"
            "  Rectangle (3.14 4.00)\n"
            "}\n",visitor.getResult());
    delete parser2;
}
