#include"../../src/builder/article_parser.h"
#include"../../src/visitor/html_visitor.h"

TEST(CaseParser, ParseArticle){
    ArticleParser* parser = new ArticleParser(".//test//data//simple_paragraph.txt");
    parser->parse();
    Article* article = parser->getArticle();
    // std::cout<<hh->area()<<std::endl;
    HtmlVisitor visitor;
    article->accept(&visitor);

    EXPECT_EQ(
        "<div>"
        "<h1>This is a simple paragraph</h1>"
        "<li>This is a list item</li>"
        "<span>This is a text</span>"
        "</div>"
        ,visitor.getResult());

    delete parser;
    ArticleParser* parser2 = new ArticleParser(".//test//data//complex_paragraph.txt");
    parser2->parse();
    Article* article2 = parser->getArticle();
    // std::cout<<hh->area()<<std::endl;
    HtmlVisitor visitor2;
    article2->accept(&visitor2);

    EXPECT_EQ(
        "<div>"
        "<h1>This is a complex paragraph</h1>"
        "<li>This is a list item</li>"
        "<div>"
        "<h2>This is an inner paragraph</h2>"
        "<span>This is an inner text</span>"
        "<li>This is an inner list item</li>"
        "</div>"
        "<span>This is a text</span>"
        "</div>"
        ,visitor2.getResult());
    
    // delete parser;
    // ShapeParser* parser2 = new ShapeParser(".//test//data//complex_compound.txt");
    // parser2->parse();
    // Shape* aa = parser2->getShape();
    // aa->accept(&visitor);
    // EXPECT_EQ("CompoundShape {\n"
    //         "  Circle (1.00)\n"
    //         "  Triangle ([3.00,0.00] [0.00,4.00])\n"
    //         "  CompoundShape {\n"
    //         "    Circle (1.00)\n"
    //         "    Rectangle (3.14 4.00)\n"
    //         "    Triangle ([3.00,0.00] [0.00,4.00])\n"
    //         "  }\n"
    //         "  Rectangle (3.14 4.00)\n"
    //         "}\n",visitor.getResult());
    // delete parser2;
}