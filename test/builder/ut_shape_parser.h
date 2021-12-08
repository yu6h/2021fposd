#include"../../src/builder/shape_parser.h"
#include"../../src/visitor/shape_info_visitor.h"



TEST(CaseParser, ParseCompound){
    ShapeParser* parser = new ShapeParser(".//test//data//simple_compound.txt");
    parser->parse();
    Shape* hh = parser->getShape();
    std::cout<<hh->area()<<std::endl;
    ShapeInfoVisitor visitor;
    hh->accept(&visitor);
    std::cout<<visitor.getResult()<<std::endl;
    // ASSERT_NEAR(1*1*M_PI + 2*2*M_PI, result->area(), 0.01);
}
