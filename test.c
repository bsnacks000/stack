
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "stack.h"

typedef struct {
  float x;
  float y;
} some_data;

// macro build types and functions
STACK_DECLARE(int_stack, int)

STACK_DECLARE(charp_stack, char*)

STACK_DECLARE(some_data_stack, some_data*)

int main() {
  int_stack s;
  int_stack_init(&s);

  int_stack_push(&s, 42);
  int_stack_push(&s, 43);
  int_stack_push(&s, 44);
  int_stack_push(&s, 45);
  int_stack_push(&s, 46);
  int_stack_push(&s, 47);

  if (int_stack_empty(&s)) return 1;

  int result = 0;
  int expected = 44;

  while (s.head != NULL) {
    int_stack_pop(&s, &result);
    assert(expected == result);
    expected--;
  }

  charp_stack cs;
  charp_stack_init(&cs);

  charp_stack_push(&cs, "world");
  charp_stack_push(&cs, "hello");

  char* message;

  charp_stack_pop(&cs, &message);
  assert(strcmp(message, "hello"));

  charp_stack_pop(&cs, &message);
  assert(strcmp(message, "world"));

  some_data_stack ds;
  some_data_stack_init(&ds);

  some_data d = {.x = 42.0};
  some_data e = {.x = 43.0};
  some_data f = {.x = 44.0};

  some_data_stack_push(&ds, &d);
  some_data_stack_push(&ds, &e);
  some_data_stack_push(&ds, &f);

  some_data* d_ptr;
  float expected_value = 44.0;

  while (ds.head != NULL) {
    some_data_stack_pop(&ds, &d_ptr);
    assert(d_ptr->x == expected_value);
    expected_value -= 1.0;
  }

  return 0;
}
