#include <gtest/gtest.h>

extern "C" {
#include "scene.h"
}

TEST(ConfigTest, ParseUnit) {
	EXPECT_EQ(plus(1,2), 3);
}
