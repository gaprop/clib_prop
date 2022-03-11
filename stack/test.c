#include "../utils.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  struct stack* stack = stack_new();
  int* x = malloc(sizeof(int));
  *x = 3;
  int* y = malloc(sizeof(int));
  *y = 4;
  int* z = malloc(sizeof(int));
  *z = 5;

  stack_push(stack, x);
  stack_push(stack, y);
  stack_push(stack, z);
  
  for (int* i = (int*) stack_pop(stack); i != NULL; i = (int *) stack_pop(stack)) {
    int val = *i;
    printf("%d\n", val);
    free(i);
  }

  switch(stack_destroy(&stack)) {
    case destroyed:
      printf("Stack was already destroyed\n");
      break;
    case empty:
      printf("Stack was freed successfully\n");
      break;
    case full:
      printf("The stack is still full\n");
    default:
      break;
  }

  switch(stack_destroy(&stack)) {
    case destroyed:
      printf("Stack was already destroyed\n");
      break;
    case empty:
      printf("Stack was freed successfully\n");
      break;
    case full:
      printf("The stack is still full\n");
    default:
      break;
  }
}
