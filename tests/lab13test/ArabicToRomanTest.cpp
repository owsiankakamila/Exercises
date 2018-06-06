//
// Created by mwypych on 01.06.17.
//

#include <gtest/gtest.h>
#include <ArabicRoman.h>


TEST(arabic_basic_tests, Arabic_One_To_Roman_Returns_I) {
    EXPECT_EQ("1", ArabicToRoman(1) );
}

TEST(exceptions_tests, Arabic_To_High) {
    EXPECT_THROW(ArabicToRoman(4000),std::invalid_argument);
}

TEST(exceptions_tests, Arabic_To_High_With_Message) {
    try {
        ArabicToRoman(4000);
        FAIL();
    }catch (const std::invalid_argument &e) {
        EXPECT_STREQ("To high number",e.what());
    }
}




using TestParam = std::pair<int, std::string>;

class ArabicToRomanDataDrivenTests : public ::testing::TestWithParam<TestParam> {

};

TEST_P(ArabicToRomanDataDrivenTests, ArabicToRomanShouldReturnExpectedResult) {
    const TestParam &p = GetParam();
    EXPECT_EQ(p.second, ArabicToRoman(p.first)) << "Did call ArabicToRoman (" << p.first << ")\n";
}

std::vector<TestParam> basicNumbers{{1, "I"},{5,"V"},{10,"X"}};
std::vector<TestParam> leftsideNumbers{{4, "IV"},{9,"IX"},{14,"XIV"},{44,"XLIV"}};


INSTANTIATE_TEST_CASE_P(BasicResults,
                        ArabicToRomanDataDrivenTests,
                        ::testing::ValuesIn(basicNumbers));
INSTANTIATE_TEST_CASE_P(LeftSideResults,
                        ArabicToRomanDataDrivenTests,
                        ::testing::ValuesIn(leftsideNumbers));


