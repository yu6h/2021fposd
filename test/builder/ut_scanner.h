#include"../../src/builder/scanner.h"

TEST(CaseScanner, ScanWordsAccurately)
{
    std::string input = "I Circle\n"
                        " eee ,tt\n"
                        "{t3.14159xc8.45a";
    Scanner scanner1(input);
    EXPECT_EQ("Circle",scanner1.next());
    EXPECT_EQ(",",scanner1.next());
    EXPECT_EQ("{",scanner1.next());
    EXPECT_DOUBLE_EQ(3.14159,scanner1.nextDouble());
    EXPECT_DOUBLE_EQ(8.45,scanner1.nextDouble());

    std::string input2 = "hahaha,{ xx} [ ] dsfCircle";
    Scanner scanner2(input2);
    EXPECT_EQ(",",scanner2.next());
    EXPECT_EQ("{",scanner2.next());
    EXPECT_EQ("}",scanner2.next());
    EXPECT_EQ("[",scanner2.next());
    EXPECT_EQ("]",scanner2.next());
    EXPECT_EQ("Circle",scanner2.next());

    std::string input3 =
    "CompoundShape {\n" 
    "  Circle (1.00)\n" 
    "  Rectangle (3.14 4.00)\n" 
    "  Triangle ([3.00,0.00] [0.00,4.00])\n" 
    "}\n";
    Scanner scanner3(input3);
    EXPECT_EQ("CompoundShape",scanner3.next());
    EXPECT_EQ("{",scanner3.next());
    EXPECT_EQ("Circle",scanner3.next());
    // EXPECT_EQ("(",scanner3.next());
    EXPECT_DOUBLE_EQ(1,scanner3.nextDouble());
    EXPECT_EQ(")",scanner3.next());
    EXPECT_EQ("Rectangle",scanner3.next());
    // EXPECT_EQ("(",scanner3.next());
    // EXPECT_EQ("[",scanner3.next());
    EXPECT_DOUBLE_EQ(3.14,scanner3.nextDouble());
    // EXPECT_EQ(",",scanner3.next());
    EXPECT_DOUBLE_EQ(4.0,scanner3.nextDouble());
    EXPECT_EQ(")",scanner3.next());
    EXPECT_EQ("Triangle",scanner3.next());
    EXPECT_DOUBLE_EQ(3.0,scanner3.nextDouble());
    // EXPECT_EQ(",",scanner3.next());
    EXPECT_DOUBLE_EQ(0.0,scanner3.nextDouble());
    EXPECT_DOUBLE_EQ(0.0,scanner3.nextDouble());
    // EXPECT_EQ(",",scanner3.next());
    
    EXPECT_DOUBLE_EQ(4.0,scanner3.nextDouble());
    EXPECT_EQ("]",scanner3.next());
    EXPECT_EQ(")",scanner3.next());
    EXPECT_EQ("}",scanner3.next());
    EXPECT_ANY_THROW(scanner3.nextDouble());
    EXPECT_ANY_THROW(scanner3.next());

}