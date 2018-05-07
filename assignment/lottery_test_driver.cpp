/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			lottery_test_driver.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * Reading lottery data from csv file and analyze it.
 *-----------------------------------------------------------------------------
*/

#include "shortcut.h"
#include "test_lottery.h"

int main(int argc, char *argv[])
{
	ADD_TEST(init_lottery);
	ADD_TEST(get_invalid_tip);
	ADD_TEST(get_tip_with_comma);
	ADD_TEST(get_tip_with_semicolon);
	ADD_TEST(set_invalid_drawing);
	ADD_TEST(get_tip_result_without_drawing);
	ADD_TEST(get_tip_result_from_invalid_tip);
	ADD_TEST(set_drawing);
	ADD_TEST(set_drawing_ordered);
	ADD_TEST(get_right_tips_count_invalid_setup);
	ADD_TEST(get_right_tips_count);
//	ADD_TEST(large_file);

	run_tests();

	return 0;
}
