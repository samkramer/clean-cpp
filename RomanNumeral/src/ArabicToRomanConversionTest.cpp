#include "ArabicToRomanConversion.h"
#include "gtest/gtest.h"

class ArabicToRomanTest : public ::testing::Test
{
public:
	std::string convertArabicNumberToRomanNumeral(size_t arabicNumber) {
		return roman::convertArabicNumberToRomanNumeral(arabicNumber);
	}
};

TEST_F(ArabicToRomanTest, conversionOfArabicNumbersToRomanNumerals_1) {
	ASSERT_EQ(convertArabicNumberToRomanNumeral(1), "I");
}

TEST_F(ArabicToRomanTest, conversionOfArabicNumbersToRomanNumerals_2) {
	ASSERT_EQ(convertArabicNumberToRomanNumeral(2), "II");
}

TEST_F(ArabicToRomanTest, conversionOfArabicNumbersToRomanNumerals_3) {
	ASSERT_EQ(convertArabicNumberToRomanNumeral(3), "III");
}

TEST_F(ArabicToRomanTest, conversionOfArabicNumbersToRomanNumerals_4) {
	ASSERT_EQ(convertArabicNumberToRomanNumeral(4), "IV");
}

TEST_F(ArabicToRomanTest, conversionOfArabicNumbersToRomanNumerals_5) {
	ASSERT_EQ(convertArabicNumberToRomanNumeral(5), "V");
}

TEST_F(ArabicToRomanTest, conversionOfArabicNumbersToRomanNumerals_6) {
	ASSERT_EQ(convertArabicNumberToRomanNumeral(6), "VI");
}

TEST_F(ArabicToRomanTest, conversionOfArabicNumbersToRomanNumerals_9) {
	ASSERT_EQ(convertArabicNumberToRomanNumeral(9), "IX");
}

TEST_F(ArabicToRomanTest, conversionOfArabicNumbersToRomanNumerals_10) {
	ASSERT_EQ(convertArabicNumberToRomanNumeral(10), "X");
}

TEST_F(ArabicToRomanTest, conversionOfArabicNumbersToRomanNumerals_20) {
	ASSERT_EQ(convertArabicNumberToRomanNumeral(20), "XX");
}

TEST_F(ArabicToRomanTest, conversionOfArabicNumbersToRomanNumerals_Works) {

	ASSERT_EQ(convertArabicNumberToRomanNumeral(30), "XXX");
	ASSERT_EQ(convertArabicNumberToRomanNumeral(33), "XXXIII");
	ASSERT_EQ(convertArabicNumberToRomanNumeral(37), "XXXVII");
	ASSERT_EQ(convertArabicNumberToRomanNumeral(50), "L");
	ASSERT_EQ(convertArabicNumberToRomanNumeral(99), "XCIX");
	ASSERT_EQ(convertArabicNumberToRomanNumeral(100), "C");
	ASSERT_EQ(convertArabicNumberToRomanNumeral(200), "CC");
	ASSERT_EQ(convertArabicNumberToRomanNumeral(300), "CCC");
	ASSERT_EQ(convertArabicNumberToRomanNumeral(499), "CDXCIX");
	ASSERT_EQ(convertArabicNumberToRomanNumeral(500), "D");
	ASSERT_EQ(convertArabicNumberToRomanNumeral(1000), "M");
	ASSERT_EQ(convertArabicNumberToRomanNumeral(2000), "MM");
	ASSERT_EQ(convertArabicNumberToRomanNumeral(2017), "MMXVII");
	ASSERT_EQ(convertArabicNumberToRomanNumeral(3000), "MMM");
	ASSERT_EQ(convertArabicNumberToRomanNumeral(3333), "MMMCCCXXXIII");
	ASSERT_EQ(convertArabicNumberToRomanNumeral(3999), "MMMCMXCIX");
}
