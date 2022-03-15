#include "../utils.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  struct vec* vec = vec_new();
  int* x = malloc(sizeof(int));
  int* y = malloc(sizeof(int));
  int* z = malloc(sizeof(int));
  *x = 3;
  *y = 4;
  *z = 5;

  vec_push(vec, x);
  vec_push(vec, y);
  vec_push(vec, z);

  for (int* i = (int*) vec_pop(vec); i != NULL; i = (int *) vec_pop(vec)) {
    int val = *i;
    printf("%d\n", val);
    free(i);
  }

  switch(vec_destroy(&vec)) {
    case destroyed:
      printf("Vec was already destroyed\n");
      break;
    case empty:
      printf("Vec was freed successfully\n");
      break;
    case full:
      printf("The vec is still full\n");
    default:
      break;
  }

  switch(vec_destroy(&vec)) {
    case destroyed:
      printf("Vec was already destroyed\n");
      break;
    case empty:
      printf("Vec was freed successfully\n");
      break;
    case full:
      printf("The vec is still full\n");
    default:
      break;
  }
}
