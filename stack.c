#include <stdlib.h>
#include "stack.h"
#include "utils.h"

struct stack* stack_new() {
  struct stack* stack = malloc(sizeof(struct stack));
  stack->head = NULL;
  return stack;
}

void stack_push(struct stack* stack, void* val) {
  struct node* node = malloc(sizeof(struct node));
  node->val = val;
  node->next = stack->head;

  stack->head = node;
}

void* stack_pop(struct stack* stack) {
  if (stack->head == NULL) return NULL;
  struct node* node = stack->head;
  void* val = node->val;

  stack->head = node->next;
  free(node); return val; 
}

enum result stack_destroy(struct stack** stack) {
  if (*stack == NULL) return destroyed;
  if ((*stack)->head != NULL) return full;
  free(*stack);
  stack = NULL;
  return empty;
}

// This example does not work
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
