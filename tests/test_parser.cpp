#include <gtest/gtest.h>

extern "C" {
#include "scene.h"
}

TEST(ConfigTest, IsValidDouble_valid_1) {
	EXPECT_EQ(is_valid_double("1"), true);
}

TEST(ConfigTest, IsValidDouble_valid_2) {
	EXPECT_EQ(is_valid_double("1.0"), true);
}

TEST(ConfigTest, IsValidDouble_valid_3) {
	EXPECT_EQ(is_valid_double("1."), true);
}

TEST(ConfigTest, IsValidDouble_valid_4) {
	EXPECT_EQ(is_valid_double(".1"), true);
}

TEST(ConfigTest, IsValidDouble_valid_5) {
	EXPECT_EQ(is_valid_double("-1"), true);
}

TEST(ConfigTest, IsValidDouble_valid_6) {
	EXPECT_EQ(is_valid_double("-1."), true);
}

TEST(ConfigTest, IsValidDouble_valid_7) {
	EXPECT_EQ(is_valid_double("-1.0"), true);
}

TEST(ConfigTest, IsValidDouble_valid_8) {
	EXPECT_EQ(is_valid_double("-.1"), true);
}

TEST(ConfigTest, IsValidDouble_invalid_1) {
	EXPECT_EQ(is_valid_double("+1.2"), false);
}

TEST(ConfigTest, IsValidDouble_invalid_2) {
	EXPECT_EQ(is_valid_double("1.2.3"), false);
}

TEST(ConfigTest, IsValidDouble_invalid_3) {
	EXPECT_EQ(is_valid_double("1e-2"), false);
}

