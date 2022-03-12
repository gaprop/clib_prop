#include <stdlib.h>
#include "../utils.h"
#include "tree.h"

struct tree* tree_new() {
  struct tree* tree = malloc(sizeof(struct tree));
  tree->val = NULL;
  tree->left = NULL;
  tree->right = NULL;
  tree->key = 0;
  return tree;
} 

void tree_push(struct tree* tree, void* val, unsigned int key) {
  struct tree* curr_tree = tree;

  while (curr_tree->val != NULL) {
    if (curr_tree->key < key) {
      curr_tree = curr_tree->left;
    } else if (curr_tree->key >= key) {
      curr_tree = curr_tree->right;
    }
  }

  curr_tree->val = val;
  curr_tree->key = key;
  curr_tree->left = tree_new();
  curr_tree->right = tree_new();
  /* if (curr_tree->val == NULL) { */
    /* curr_tree->val = val; */
    /* curr_tree->key = key; */
    /* curr_tree->left = tree_new(); */
    /* curr_tree->right = tree_new(); */
  /* }  */
  /* if (tree->index < index) { */
    /* tree_push(tree->left, val, index); */
  /* } else if (tree->index >= index) { */
    /* tree_push(tree->right, val, index); */
  /* } */
}
