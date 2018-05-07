/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			test_lottery.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "lottery.h"

#include "test_lottery.h"

/******************************************************************************
 * test_init_lottery
 *
 *
 ******************************************************************************/
TEST(init_lottery)
{
	ASSERT_FALSE(init_lottery("no_tips.csv", ','), "Init with wrong file: False expected");
	ASSERT_TRUE(init_lottery("tips1.csv", ','), "Init with right file: True expected");
}

TEST(get_invalid_tip)
{
	int tip[TIP_SIZE];
	init_lottery("tips2.csv", ';');
	ASSERT_FALSE(get_tip(-1, tip), "Tipp #-1 not available, False expected");
	ASSERT_FALSE(get_tip(1000000, tip), "Tipp #444444444 not available, False expected");
}

/******************************************************************************
 * test_get_tip
 *
 *
 ******************************************************************************/
TEST(get_tip_with_comma)
{
	int tip[TIP_SIZE];
	init_lottery("tips1.csv", ',');

	ASSERT_TRUE(get_tip(0, tip), "Tip #0 available; True expected");
	ASSERT_EQUALS(37, tip[0]);
	ASSERT_EQUALS(26, tip[1]);
	ASSERT_EQUALS(38, tip[2]);
	ASSERT_EQUALS(6, tip[3]);
	ASSERT_EQUALS(14, tip[4]);
	ASSERT_EQUALS(36, tip[5]);

	ASSERT_TRUE(get_tip(1, tip), "Tip #1 available; True expected");
	ASSERT_EQUALS(39, tip[0]);
	ASSERT_EQUALS(24, tip[1]);
	ASSERT_EQUALS(20, tip[2]);
	ASSERT_EQUALS(22, tip[3]);
	ASSERT_EQUALS(6, tip[4]);
	ASSERT_EQUALS(19, tip[5]);

	ASSERT_TRUE(get_tip(21, tip), "Tip #21 available; True expected");
	ASSERT_EQUALS(28, tip[0]);
	ASSERT_EQUALS(16, tip[1]);
	ASSERT_EQUALS(40, tip[2]);
	ASSERT_EQUALS(45, tip[3]);
	ASSERT_EQUALS(39, tip[4]);
	ASSERT_EQUALS(5, tip[5]);

	ASSERT_TRUE(get_tip(43, tip), "Tip #43 available; True expected");
	ASSERT_EQUALS(37, tip[0]);
	ASSERT_EQUALS(17, tip[1]);
	ASSERT_EQUALS(9, tip[2]);
	ASSERT_EQUALS(14, tip[3]);
	ASSERT_EQUALS(22, tip[4]);
	ASSERT_EQUALS(45, tip[5]);
}

TEST(get_tip_with_semicolon)
{
	int tip[TIP_SIZE];
	init_lottery("tips2.csv", ';');

	ASSERT_TRUE(get_tip(0, tip), "Tip #0 available");

	ASSERT_EQUALS(9, tip[0]);
	ASSERT_EQUALS(15, tip[1]);
	ASSERT_EQUALS(22, tip[2]);
	ASSERT_EQUALS(36, tip[3]);
	ASSERT_EQUALS(41, tip[4]);
	ASSERT_EQUALS(45, tip[5]);
}

TEST(set_invalid_drawing)
{
	int invalid_drawing1[TIP_SIZE] = {3, 1, 38, 2, 0, 45};
	int invalid_drawing2[TIP_SIZE] = {3, 1, 38, 46, 38, 45};

	ASSERT_FALSE(set_drawing(invalid_drawing1), "Drawing may not have a number smaller than 0");
	ASSERT_FALSE(set_drawing(invalid_drawing2), "Drawing may not have a number greater than 45");
}

TEST(get_tip_result_without_drawing)
{
	init_lottery("tips1.csv", ',');
	ASSERT_EQUALS(-1, get_tip_result(5));
}

TEST(get_tip_result_from_invalid_tip)
{
	init_lottery("tips1.csv", ',');

	int drawing_result[TIP_SIZE] = {37, 26, 38, 6, 14, 36};
	set_drawing(drawing_result);

	ASSERT_EQUALS(-2, get_tip_result(-1));
	ASSERT_EQUALS(-2, get_tip_result(44));
}

/******************************************************************************
 * test_set_drawing
 *
 *
 ******************************************************************************/
TEST(set_drawing)
{
	init_lottery("tips1.csv", ',');

	int drawing_result1[TIP_SIZE] = {37, 26, 38, 6, 14, 36};
	int drawing_result2[TIP_SIZE] = {8, 35, 14, 27, 37, 42};

	set_drawing(drawing_result1);
	ASSERT_EQUALS(6, get_tip_result(0));
	ASSERT_EQUALS(2, get_tip_result(43));
	ASSERT_EQUALS(3, get_tip_result(3));
	ASSERT_EQUALS(1, get_tip_result(16));

	set_drawing(drawing_result2);
	ASSERT_EQUALS(2, get_tip_result(0));
	ASSERT_EQUALS(0, get_tip_result(1));
	ASSERT_EQUALS(6, get_tip_result(31));
}

/******************************************************************************
 * test_set_drawing_ordered
 *
 *
 ******************************************************************************/
TEST(set_drawing_ordered)
{
	int drawing_result[TIP_SIZE] = {6, 14, 26, 36, 37, 38};
	int drawing_result1[TIP_SIZE] = {8, 14, 27, 35, 37, 42};

	init_lottery("tips1.csv", ',');

	set_drawing(drawing_result);
	ASSERT_EQUALS(6, get_tip_result(0));
	ASSERT_EQUALS(2, get_tip_result(43));
	ASSERT_EQUALS(3, get_tip_result(3));
	ASSERT_EQUALS(1, get_tip_result(16));

	set_drawing(drawing_result1);
	ASSERT_EQUALS(2, get_tip_result(0));
	ASSERT_EQUALS(0, get_tip_result(1));
	ASSERT_EQUALS(6, get_tip_result(31));
}

TEST(get_right_tips_count_invalid_setup)
{
	int drawing_result[TIP_SIZE] = {6, 14, 26, 36, 37, 38};

	init_lottery("tips1.csv", ',');
	ASSERT_EQUALS(-1, get_right_tips_count(0));

	set_drawing(drawing_result);
	ASSERT_EQUALS(-1, get_right_tips_count(-1));
	ASSERT_EQUALS(-1, get_right_tips_count(TIP_SIZE + 1));

}
/******************************************************************************
 * test_get_right_tips_count
 *
 *
 ******************************************************************************/
TEST(get_right_tips_count)
{
	int drawing_result[TIP_SIZE] = {6, 14, 26, 36, 37, 38};

	init_lottery("tips1.csv", ',');

	set_drawing(drawing_result);
	ASSERT_EQUALS(1, get_right_tips_count(6));
	ASSERT_EQUALS(0, get_right_tips_count(5));
	ASSERT_EQUALS(0, get_right_tips_count(4));
	ASSERT_EQUALS(1, get_right_tips_count(3));
	ASSERT_EQUALS(6, get_right_tips_count(2));
	ASSERT_EQUALS(18, get_right_tips_count(1));
	ASSERT_EQUALS(18, get_right_tips_count(0));
}

// TEST(large_file)
// {
// 	int drawing_result[TIP_SIZE] = {6, 14, 26, 36, 37, 38};
//
// 	init_lottery("tips2.csv", ';');
//
// 	set_drawing(drawing_result);
// 	ASSERT_EQUALS(1, get_right_tips_count(6));
// 	ASSERT_EQUALS(0, get_right_tips_count(5));
// 	ASSERT_EQUALS(0, get_right_tips_count(4));
// 	ASSERT_EQUALS(1, get_right_tips_count(3));
// 	ASSERT_EQUALS(6, get_right_tips_count(2));
// 	ASSERT_EQUALS(18, get_right_tips_count(1));
// 	ASSERT_EQUALS(18, get_right_tips_count(0));
// }
