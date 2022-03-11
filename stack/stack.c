#include <stdlib.h>
#include "stack.h"
#include "../utils.h"

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
  free(node); 
  return val; 
}

enum result stack_destroy(struct stack** stack) {
  if (*stack == NULL) return destroyed;
  if ((*stack)->head != NULL) return full;
  free(*stack);
  stack = NULL;
  return empty;
}
