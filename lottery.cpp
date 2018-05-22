/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			lottery.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * Implementation of a library for analyzing lottery tips.
 *-----------------------------------------------------------------------------
*/
#include <stdio.h>
#include "lottery.h"
#include <stdlib.h>

const char* fileName;
char separator;
int* drawn_numbers;
bool is_drawn = false;

bool 	init_lottery (const char *csv_file, char csv_separator)
{
 FILE* fd=fopen(csv_file, "r");
  if (fd == NULL) {
      return false;
  }
  fileName = csv_file;
  separator = csv_separator;
  is_drawn = false;
  fclose(fd);
  return true;
}

bool 	get_tip (int tip_number, int tip[TIP_SIZE])
{
  FILE* fd = fopen(fileName, "r");
  if (tip_number < 0 || fd == 0) {
    fclose(fd);
    return false;
  }

  char tip_line[MAX_LINE_LEN] = {0};
  int count = 0;
  char* line = fgets(tip_line, MAX_LINE_LEN, fd);

  while (line != NULL && count < tip_number) {
    line = fgets(tip_line, MAX_LINE_LEN, fd);
    count++;
    if (tip_line != line) {
      fclose(fd);
      return false;
    }
  }
  if (ftell(fd) == EOF) {
    fclose(fd);
    return false;
  }
  int index = 0;
  while (tip_line[index] != separator && index < UUID_LEN) {
    index++;
  }

  int tip_array_index = 0;
  int number_to_insert = 0;
  while (tip_array_index < TIP_SIZE) {
    index++;
    if (tip_line[index] >= '0' && tip_line[index] <= '9') {
      number_to_insert = number_to_insert*10 + (tip_line[index] - '0');
    }
    else{
      tip[tip_array_index] = number_to_insert;
      number_to_insert = 0;
      tip_array_index++;
    }
  }
  fclose(fd);
  return true;
}

bool 	set_drawing (int drawing_numbers[TIP_SIZE])
{
  for (int i = 0; i < TIP_SIZE; i++) {
    if (drawing_numbers[i] <1 || drawing_numbers[i] >45) {
      return false;
    }
  }
  drawn_numbers = drawing_numbers;
  is_drawn = true;
  return true;
}

int 	get_tip_result (int tip_number)
{
  if (!is_drawn) {
    return -1;
  }
  int tip_array[TIP_SIZE];
  if (!get_tip(tip_number, tip_array)) {
    return -2;
  }
  int tip_result = 0;
  for (int i = 0; i < TIP_SIZE; i++) {
    for (int j = 0; j < TIP_SIZE; j++) {
      if (tip_array[i] == drawn_numbers[j]) {
        tip_result++;
      }
    }
  }
  return tip_result;
}

int 	get_right_tips_count (int right_digits_count)
{
  if (right_digits_count < 0 || right_digits_count > TIP_SIZE || !is_drawn) {
    return -1;
  }
  int tip_result = 0;
  int row = 0;
  int right_tips_count = 0;
  while (tip_result != -1 && tip_result != 2) {
    tip_result = get_tip_result(row);
    if (tip_result == right_digits_count) {
      right_tips_count++;
    }
    row++;
  }
  return right_tips_count;
}
