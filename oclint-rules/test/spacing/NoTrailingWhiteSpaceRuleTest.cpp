#include "TestHeaders.h"
#include "rules/spacing/NoTrailingWhiteSpaceRule.cpp"

class NoTrailingWhiteSpaceRuleTest : public ::testing::Test {
};

TEST_F(NoTrailingWhiteSpaceRuleTest, PropertyTest)
{
    NoTrailingWhiteSpaceRule rule;
    EXPECT_EQ(3, rule.priority());
    EXPECT_EQ("NoTrailingWhiteSpace", rule.name());
}

TEST_F(NoTrailingWhiteSpaceRuleTest, GoodBlankLine)
{
    testRuleOnCode(new NoTrailingWhiteSpaceRule(), "void m() {\n}");
}

TEST_F(NoTrailingWhiteSpaceRuleTest, ViolationSpace)
{
    testRuleOnCode(new NoTrailingWhiteSpaceRule(), "void m() \n{\n  \n}", 0, 1, 1, 1, 9, "No trailing whitespace is allowed.");
    testRuleOnCode(new NoTrailingWhiteSpaceRule(), "void m() \n{\n  \n}", 1, 3, 1, 3, 2, "No trailing whitespace is allowed.");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
