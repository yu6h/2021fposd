#include"../../src/builder/article_scanner.h"

TEST(CaseScanner, ScanWordsAccurately)
{
    std::string input = "I ListItem eee {\"string\"555\"next\"adfdae}too6a";
    ArticleScanner scanner(input);
  // `first` is "ListItem"
    EXPECT_EQ("ListItem",scanner.nextToken());
    EXPECT_EQ("string",scanner.nextStr());
    EXPECT_EQ("next",scanner.nextStr());
    EXPECT_EQ("}",scanner.nextToken());
    EXPECT_DOUBLE_EQ(6,scanner.nextInt());
           // `fourth` is 6


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
