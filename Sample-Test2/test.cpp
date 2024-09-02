#include "pch.h"
#include "gtest/gtest.h"
TEST(run1Test, R0Test) {
  EXPECT_EQ( 0.212,R0(1,1,1,1));
  EXPECT_EQ(0.136, R0(1,2,3,4));
  EXPECT_EQ(0.058, R0(4,3,2,1));
}


TEST(run1Test, R00Test) {
	EXPECT_EQ(0.600, R00(1,1,1,1));
	EXPECT_EQ(0.812, R00(1,2,3,4));
	EXPECT_EQ(1.629, R00(4,3,2,1));
}





int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}