#include <stdlib.h>
#include "../utils.h"

struct tree* tree_new() {
  struct tree* tree = malloc(sizeof(struct tree));
  tree->val = NULL;
  tree->left = NULL;
  tree->right = NULL;
  return tree;
} 

void tree_push(struct tree* tree, void* val) {
  if (tree->val == NULL) {
    tree->val = val;
  } else if (tree->left == NULL) {

  }
}
