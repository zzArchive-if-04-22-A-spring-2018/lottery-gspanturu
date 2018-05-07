#include <stdlib.h>
#include "general.h"

static void* free_list[64];
static int next_entry;

void init_free_list()
{
  next_entry = 0;
}

void sfree(void* address)
{
  free(address);
  free_list[next_entry++] = address;
}

void** get_free_list()
{
  return free_list;
}

int get_free_list_length()
{
  return next_entry;
}
