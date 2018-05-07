/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: <your class name here>
 * ---------------------------------------------------------
 * Exercise Number: 0
 * File:			test_lottery.h
 * Author:			Peter Bauer
 * Due Date:		#due#
 * ----------------------------------------------------------
 * Description:
 * Test functions for lottery
 * ----------------------------------------------------------
 */
#ifndef ___TEST_LOTTERY_H
#define ___TEST_LOTTERY_H

#include "shortcut.h"

TEST(init_lottery);
TEST(get_invalid_tip);
TEST(get_tip_with_comma);
TEST(get_tip_with_semicolon);
TEST(set_invalid_drawing);
TEST(get_tip_result_without_drawing);
TEST(get_tip_result_from_invalid_tip);
TEST(set_drawing);
TEST(set_drawing_ordered);
TEST(get_right_tips_count_invalid_setup);
TEST(get_right_tips_count);
//TEST(large_file);

#endif
