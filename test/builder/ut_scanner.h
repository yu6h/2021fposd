#include"../../src/builder/scanner.h"

TEST(CaseScanner, XXXX)
{
    std::string input = "I Circle\n eee ,tt\n{t3.14159a";
    Scanner scanner(input);
    EXPECT_EQ("Circle",scanner.next());
    EXPECT_EQ(",",scanner.next());
    EXPECT_EQ("{",scanner.next());
    EXPECT_DOUBLE_EQ(3.14159,scanner.nextDouble());

    std::string input2 = "hahaha,{ xx} [ ] dsfCircle";
    Scanner scanner2();


}