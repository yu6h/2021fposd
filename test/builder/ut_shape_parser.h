#include"../../src/builder/shape_parser.h"




TEST(CaseParser, ParseCompound){
    std::string input = "compound {\n circle 1.0\n circle 2.0\n }";
    ShapeParser* parser = new ShapeParser(".//test//data//complex_compound.txt");
    // Shape* result = parser->parse(input);

    // ASSERT_NEAR(1*1*M_PI + 2*2*M_PI, result->area(), 0.01);
}
