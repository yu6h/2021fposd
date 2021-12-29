#include"../../src/builder/article_scanner.h"

TEST(CaseScanner, ScanWordsAccurately)
{
    // std::string input = "I Circle\n"
    //                     " eee ,tt\n"
    //                     "{t3.14159xc8.45a";
    // Scanner scanner1(input);
    // EXPECT_EQ("Circle",scanner1.next());
    // EXPECT_EQ(",",scanner1.next());
    // EXPECT_EQ("{",scanner1.next());
    // EXPECT_DOUBLE_EQ(3.14159,scanner1.nextDouble());
    // EXPECT_DOUBLE_EQ(8.45,scanner1.nextDouble());

    // std::string input2 = "hahaha,{ xx} [ ] dsfCircle";
    // Scanner scanner2(input2);
    // EXPECT_EQ(",",scanner2.next());
    // EXPECT_EQ("{",scanner2.next());
    // EXPECT_EQ("}",scanner2.next());
    // EXPECT_EQ("[",scanner2.next());
    // EXPECT_EQ("]",scanner2.next());
    // EXPECT_EQ("Circle",scanner2.next());

    std::string input3 =
    "Paragraph (1 \"This is a simple paragraph\") {"
    "ListItem (\"This is a list item\")"
    "Text (\"This is a text\")"
    "}";
    ArticleScanner scanner3(input3);
    EXPECT_EQ("Paragraph",scanner3.nextToken());
    EXPECT_EQ("(",scanner3.nextToken());
    EXPECT_DOUBLE_EQ(1,scanner3.nextInt());
    EXPECT_EQ("This is a simple paragraph",scanner3.nextStr());
    EXPECT_EQ(")",scanner3.nextToken());
    EXPECT_EQ("{",scanner3.nextToken());

    EXPECT_EQ("ListItem",scanner3.nextToken());
}
