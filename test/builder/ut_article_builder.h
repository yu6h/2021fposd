#include"../../src/builder/article_builder.h"
#include"../../src/visitor/markdown_visitor.h"
#include"../../src/visitor/html_visitor.h"
#include <gtest/gtest.h>
TEST(CaseArticleBuilder, buildArticle)
{
    ArticleBuilder* builder = ArticleBuilder::getInstance();
    builder->buildParagraphBegin(1,"title");
    builder->buildListItem("list1");
    builder->buildParagraphBegin(2, "title2");
    builder->buildListItem("list2");
    builder->buildText("text");
    builder->buildParagraphEnd();
    builder->buildListItem("list3");
    builder->buildListItem("list4");
    builder->buildText("sub text");
    builder->buildParagraphEnd();

    Article* article = builder->getArticle();

    ArticleVisitor* visitor = new HtmlVisitor();
    article->accept(visitor);
    EXPECT_EQ(
        "<div>"
        "<h1>title</h1>"
        "<li>list1</li>"
        "<div>"
        "<h2>title2</h2>"
        "<li>list2</li>"
        "<span>text</span>"
        "</div>"
        "<li>list3</li>"
        "<li>list4</li>"
        "<span>sub text</span>"
        "</div>",
        visitor->getResult());
    
    builder->reset();
    delete visitor;
    // delete shape;
    // delete builder;

}
TEST(CaseArticleBuilder, singleton)
{
    // FAIL();
    EXPECT_EQ(ArticleBuilder::getInstance(),ArticleBuilder::getInstance());
}

// TEST(CaseShapeBuilder, buildCircle)
// {
//     ShapeBuilder* builder = ShapeBuilder::getInstance();

//     builder->buildCircle(10.0);
//     Shape *s = builder->getShape();
//     EXPECT_EQ("Circle (10.00)",s->info());
//     builder->reset();
//     // delete s;
//     // delete builder;
// }
// TEST(CaseShapeBuilder, buildRectangle)
// {
//     ShapeBuilder* builder = ShapeBuilder::getInstance();
//     builder->buildRectangle(10.0,12.0);
//     Shape *s = builder->getShape();
//     EXPECT_EQ("Rectangle (10.00 12.00)",s->info());
//     builder->reset();
//     // delete s;
//     // delete builder;
// }
// TEST(CaseShapeBuilder, buildTriangle)
// {
//     ShapeBuilder* builder = ShapeBuilder::getInstance();

//     builder->buildTriangle(10.0,12.0,9.0,8.7);
//     Shape *s = builder->getShape();
//     EXPECT_EQ("Triangle ([10.00,12.00] [9.00,8.70])",s->info());
//     builder->reset();
//     // delete s;
//     // delete builder;
// }
