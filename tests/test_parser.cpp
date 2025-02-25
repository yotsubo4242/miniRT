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

void expect_color(t_color rgb, int r, int g, int b){
	EXPECT_EQ(rgb.r, r);
	EXPECT_EQ(rgb.g, g);
	EXPECT_EQ(rgb.b, b);
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

// is_valid_double
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

// parse_unit
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

// parse_double
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

// parse_vec3
// exept eq
TEST(ConfigTest, ParseVec3) {
	t_vec3 vec = parse_vec3("1.2,3.4,5.6");
	expect_vec3(vec, 1.2, 3.4, 5.6);
}

TEST(ConfigTest, ParseVec3Negative) {
	t_vec3 vec = parse_vec3("-1.2,-3.4,-5.6");
	expect_vec3(vec, -1.2, -3.4, -5.6);
}

// parse_vec3
// expect exit
TEST(ConfigTest, ParseVec3ExtraSpace) {
	EXPECT_EXIT(parse_vec3("1.2, 3.4, 5.6"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseVec3ExtraComma) {
	EXPECT_EXIT(parse_vec3("1.2,,3.4,5.6"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseVec3MissingComma) {
	EXPECT_EXIT(parse_vec3("1.2,3.4 5.6"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseVec3MissingValue) {
	EXPECT_EXIT(parse_vec3("1.2,3.4,"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseVec3Empty) {
	EXPECT_EXIT(parse_vec3(""), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseVec3Space) {
	EXPECT_EXIT(parse_vec3(" "), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseRgb) {
	t_color rgb = parse_rgb("1,2,3");
	expect_color(rgb, 1, 2, 3);
}

TEST(ConfigTest, ParseRgbMax) {
	t_color rgb = parse_rgb("255,255,255");
	expect_color(rgb, 255, 255, 255);
}

TEST(ConfigTest, ParseRgbZero) {
	t_color rgb = parse_rgb("0,0,0");
	expect_color(rgb, 0, 0, 0);
}

// parse_rgb
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
	expect_color(ambient.color, 255, 255, 255);
}

// expect exit
TEST(ConfigTest, ParseAmbientMissingRatio) {
	EXPECT_EXIT(parse_ambient("A 255,255,255"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseAmbientMissingColor) {
	EXPECT_EXIT(parse_ambient("A 0.2"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_camera
// expect eq
TEST(ConfigTest, ParseCamera) {
	auto line = "C  -50,0,20  0,0,1  70";
	auto camera = parse_camera(line);
	expect_vec3(camera.position, -50, 0, 20);
	expect_vec3(camera.orientation, 0, 0, 1);
	EXPECT_DOUBLE_EQ(camera.fov, 70);
}

// expect exit
TEST(ConfigTest, ParseCameraMissingPosition) {
	EXPECT_EXIT(parse_camera("C 0,0,0 70"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseCameraMissingFov) {
	EXPECT_EXIT(parse_camera("C 0,0,0 0,0,0"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_light
TEST(ConfigTest, ParseLight) {
	auto line = "L  -40,0,30  0.7  255,255,255";
	auto light = parse_light(line);
	expect_vec3(light.position, -40, 0, 30);
	EXPECT_DOUBLE_EQ(light.brightness, 0.7);
	expect_color(light.color, 255, 255, 255);
}

// expect exit
TEST(ConfigTest, ParseLightMissingPosition) {
	EXPECT_EXIT(parse_light("L 0.7 255,255,255"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseLightMissingBrightness) {
	EXPECT_EXIT(parse_light("L 0,0,0 255,255,255"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParseLightMissingColor) {
	EXPECT_EXIT(parse_light("L 0,0,0 0.7"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_sphere
// expect eq
TEST(ConfigTest, ParseSphere) {
	auto line = "sp  -30,0,40  20  255,255,255";
	auto sphere = parse_sphere(line);
	expect_vec3(sphere.center, -30, 0, 40);
	EXPECT_DOUBLE_EQ(sphere.radius, 10);
	expect_color(sphere.color, 255, 255, 255);
}

// expect exit
TEST(ConfigTest, ParseSphereMissingCenter) {
	EXPECT_EXIT(parse_sphere("sp 20 255,255,255"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// expect exit
TEST(ConfigTest, ParseSphereMissingDiameter) {
	EXPECT_EXIT(parse_sphere("sp 0,0,0 255,255,255"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// expect exit
TEST(ConfigTest, ParseSphereMissingColor) {
	EXPECT_EXIT(parse_sphere("sp 0,0,0 20"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_plane
TEST(ConfigTest, ParsePlane) {
	auto line = "pl  0,1,0  0,0,1  255,255,255";
	auto plane = parse_plane(line);
	expect_vec3(plane.point, 0, 1, 0);
	expect_vec3(plane.normal, 0, 0, 1);
	expect_color(plane.color, 255, 255, 255);
}

// expect exit
TEST(ConfigTest, ParsePlaneMissingPoint) {
	EXPECT_EXIT(parse_plane("pl 0,0,1 255,255,255"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

TEST(ConfigTest, ParsePlaneMissingColor) {
	EXPECT_EXIT(parse_plane("pl 0,1,0 0,0,1"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}
