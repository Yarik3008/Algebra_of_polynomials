#include "TPolinom.h"
#include <gtest.h>


TEST(Polinom, Assigned_polinom_is_equal_assignable) {
	TPolinom originalPolinom;
	originalPolinom.AddMonom(TMonom(1.0, 3, 0, 0));
	TPolinom assignedPolinom;
	assignedPolinom = originalPolinom;
	EXPECT_EQ(assignedPolinom.ToString(), originalPolinom.ToString());
}

TEST(Polinom, Correct_adding_operator) {
	TPolinom temp;
	temp.AddMonom(TMonom(1.0, 3, 0, 0));
	temp.AddMonom(TMonom(1.0, 3, 0, 0));
	TPolinom temp2;
	temp2.AddMonom(TMonom(2.0, 3, 0, 0));
	EXPECT_EQ(temp.ToString(), temp2.ToString());
}

TEST(Polinom, Correct_constant_multiply) {
	TPolinom temp;
	temp.AddMonom(TMonom(1.0, 3, 0, 0));
	temp = temp * 4.0;
	TPolinom temp2;
	temp2.AddMonom(TMonom(4.0, 3, 0, 0));
	EXPECT_EQ(temp.ToString(), temp2.ToString());
}
