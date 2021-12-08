#include"../../src/builder/scanner.h"

TEST(CaseScanner, XXXX)
{
    std::string input = "I Circle\n eee ,tt\n{t3.14159a";
    Scanner scanner(input);
    std::string first = scanner.next();      // `first` is "Circle"
    EXPECT_EQ("Circle",first);
    std::string second = scanner.next();     // `second` is ","
    EXPECT_EQ(",",second);
    double third = scanner.nextDouble();     // `third` is 3.14159
    EXPECT_DOUBLE_EQ(3.14159,third);
}