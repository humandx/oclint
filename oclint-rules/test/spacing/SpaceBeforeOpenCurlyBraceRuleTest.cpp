#include "TestHeaders.h"
#include "rules/spacing/SpaceBeforeOpenCurlyBraceRule.cpp"


class SpaceBeforeOpenCurlyBraceRuleTest : public ::testing::Test {
};

TEST_F(SpaceBeforeOpenCurlyBraceRuleTest, PropertyTest)
{
    SpaceBeforeOpenCurlyBraceRule rule;
    EXPECT_EQ(3, rule.priority());
    EXPECT_EQ("space before open curly brace", rule.name());
}

TEST_F(SpaceBeforeOpenCurlyBraceRuleTest, GoodMethod)
{
    testRuleOnCode(new SpaceBeforeOpenCurlyBraceRule(), "void m() {\n  \n}");
}

TEST_F(SpaceBeforeOpenCurlyBraceRuleTest, ViolationForBadMethod)
{
    testRuleOnCode(new SpaceBeforeOpenCurlyBraceRule(), "void m(){\n  \n}",
        0, 1, 1, 1, 9, "{ must have exactly one space preceding it, unless ^{ or @{.");
}

TEST_F(SpaceBeforeOpenCurlyBraceRuleTest, ViolationForLoneCurly)
{
    testRuleOnCode(new SpaceBeforeOpenCurlyBraceRule(), "void m() \n{\n  \n}", 0, 2, 1, 2, 1, "{ must be in line with the method or compound statement declaration.");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
