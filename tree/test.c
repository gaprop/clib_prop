#include "../utils.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  struct tree* tree = tree_new();
  int* x = malloc(sizeof(int));
  int* y = malloc(sizeof(int));
  int* z = malloc(sizeof(int));
  *x = 3;
  *y = 4;
  *z = 5;

  tree_push(tree, x, *x);
  tree_push(tree, y, *y);
  tree_push(tree, z, *z);

  for (int* i = (int*) tree_pop(tree); i != NULL; i = (int *) tree_pop(tree)) {
    int val = *i;
    printf("%d\n", val);
    free(i);
  }

  switch(tree_destroy(&tree)) {
    case destroyed:
      printf("Stack was already destroyed\n");
      break;
    case empty:
      printf("Stack was freed successfully\n");
      break;
    case full:
      printf("The tree is still full\n");
    default:
      break;
  }

  switch(tree_destroy(&tree)) {
    case destroyed:
      printf("Stack was already destroyed\n");
      break;
    case empty:
      printf("Stack was freed successfully\n");
      break;
    case full:
      printf("The tree is still full\n");
    default:
      break;
  }
}
