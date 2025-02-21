#include <gtest/gtest.h>

extern "C" {
#include "scene.h"
}

void expect_vec3(t_vec3 vec, double x, double y, double z) {
	const double epsilon = 0.0001;
	EXPECT_NEAR(vec.x, x, epsilon);
	EXPECT_NEAR(vec.y, y, epsilon);
	EXPECT_NEAR(vec.z, z, epsilon);
}

// is_valid_double
// exept true
TEST(ConfigTest, IsValidDouble_valid1) {
	EXPECT_EQ(is_valid_double("1"), true);
}

TEST(ConfigTest, IsValidDouble_valid2) {
	EXPECT_EQ(is_valid_double("1.0"), true);
}

TEST(ConfigTest, IsValidDouble_valid3) {
	EXPECT_EQ(is_valid_double("1."), true);
}

TEST(ConfigTest, IsValidDouble_valid4) {
	EXPECT_EQ(is_valid_double(".1"), true);
}

TEST(ConfigTest, IsValidDouble_valid5) {
	EXPECT_EQ(is_valid_double("-1"), true);
}

TEST(ConfigTest, IsValidDouble_valid6) {
	EXPECT_EQ(is_valid_double("-1."), true);
}

TEST(ConfigTest, IsValidDouble_valid7) {
	EXPECT_EQ(is_valid_double("-1.0"), true);
}

TEST(ConfigTest, IsValidDouble_valid8) {
	EXPECT_EQ(is_valid_double("-.1"), true);
}

// exept false
TEST(ConfigTest, IsValidDouble_invalid1) {
	EXPECT_EQ(is_valid_double("+1.2"), false);
}

TEST(ConfigTest, IsValidDouble_invalid2) {
	EXPECT_EQ(is_valid_double("1.2.3"), false);
}

TEST(ConfigTest, IsValidDouble_invalid3) {
	EXPECT_EQ(is_valid_double("1e-2"), false);
}

// parse_unit
// expect eq
TEST(ConfigTest, ParseUint) {
	EXPECT_EQ(parse_uint("123"), 123);
}

TEST(ConfigTest, ParseUintZero) {
	EXPECT_EQ(parse_uint("0"), 0);
}

TEST(ConfigTest, ParseUintMax) {
	EXPECT_EQ(parse_uint("4294967295"), 4294967295);
}

// expect exit
TEST(ConfigTest, ParseUintOverflow) {
	EXPECT_EXIT(parse_uint("4294967296"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseUintNegative) {
	EXPECT_EXIT(parse_uint("-1"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseUintSign) {
	EXPECT_EXIT(parse_uint("+1"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseUintSign2) {
	EXPECT_EXIT(parse_uint("+-1"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseUintDot) {
	EXPECT_EXIT(parse_uint("1.2"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseUintNonNumeric) {
	EXPECT_EXIT(parse_uint("a"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseUintEmpty) {
	EXPECT_EXIT(parse_uint(""), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseUintSpace) {
	EXPECT_EXIT(parse_uint(" "), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseUintWithSpace) {
	EXPECT_EXIT(parse_uint("1 "), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseUintWithSpace2) {
	EXPECT_EXIT(parse_uint(" 1"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseUintWithSpace3) {
	EXPECT_EXIT(parse_uint("1 2"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_double
// expect eq
TEST(ConfigTest, ParseDouble) {
	EXPECT_DOUBLE_EQ(parse_double("123.4"), 123.4);
}

TEST(ConfigTest, ParseDoubleNegative) {
	EXPECT_DOUBLE_EQ(parse_double("-123.4"), -123.4);
}

TEST(ConfigTest, ParseDoubleZero) {
	EXPECT_DOUBLE_EQ(parse_double("0"), 0);
}

TEST(ConfigTest, ParseDoubleStartWithZero) {
	EXPECT_DOUBLE_EQ(parse_double("0.123"), 0.123);
}

TEST(ConfigTest, ParseDoubleStartWithDot) {
	EXPECT_DOUBLE_EQ(parse_double(".123"), 0.123);
}

// expect exit
TEST(ConfigTest, ParseDoubleEmpty) {
	EXPECT_EXIT(parse_double(""), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseDoubleSpace) {
	EXPECT_EXIT(parse_double(" "), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseDoubleWithSpace) {
	EXPECT_EXIT(parse_double("1.2 "), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseDoubleWithSpace2) {
	EXPECT_EXIT(parse_double(" 1.2"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseDoubleWithSpace3) {
	EXPECT_EXIT(parse_double("1. 2"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseDoubleNonNumeric) {
	EXPECT_EXIT(parse_double("a"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseDoubleSign) {
	EXPECT_EXIT(parse_double("+1.2"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseDoubleSign2) {
	EXPECT_EXIT(parse_double("+-1.2"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_rgb
// exept eq
TEST(ConfigTest, ParseRgb) {
	t_rgb rgb = parse_rgb("1,2,3");
	expect_vec3(rgb, 1, 2, 3);
}

TEST(ConfigTest, ParseRgbMax) {
	t_rgb rgb = parse_rgb("255,255,255");
	expect_vec3(rgb, 255, 255, 255);
}

TEST(ConfigTest, ParseRgbZero) {
	t_rgb rgb = parse_rgb("0,0,0");
	expect_vec3(rgb, 0, 0, 0);
}

// expect exit
TEST(ConfigTest, ParseRgbNegative) {
	EXPECT_EXIT(parse_rgb("-1,2,3"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseRgbOutOfRange) {
	EXPECT_EXIT(parse_rgb("256,2,3"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseRgbExtraSpace) {
	EXPECT_EXIT(parse_rgb("1, 2, 3"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseRgbExtraComma) {
	EXPECT_EXIT(parse_rgb("1,,2,3"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseRgbMissingComma) {
	EXPECT_EXIT(parse_rgb("1,2 3"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseRgbMissingValue) {
	EXPECT_EXIT(parse_rgb("1,2,"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_ambient
// expect eq
TEST(ConfigTest, ParseAmbient) {
	auto line = "A  0.2  255,255,255";
	auto ambient = parse_ambient(line);
	EXPECT_DOUBLE_EQ(ambient.ratio, 0.2);
	expect_vec3(ambient.color, 255, 255, 255);
}

// expect exit
TEST(ConfigTest, ParseAmbientMissingRatio) {
	EXPECT_EXIT(parse_ambient("A 255,255,255"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseAmbientMissingColor) {
	EXPECT_EXIT(parse_ambient("A 0.2"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}
