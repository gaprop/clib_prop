#include <stdlib.h>
#include "../utils.h"
#include "tree.h"

struct tree* tree_new() {
  struct tree* tree = malloc(sizeof(struct tree));
  tree->root = NULL;
  return tree;
} 

void tree_push(struct tree* tree, void* val, unsigned int key) {
  struct node** curr_node = &tree->root;

  while (*curr_node != NULL) {
    if ((*curr_node)->key >= key) {
      curr_node = &(*curr_node)->left;
    } else if ((*curr_node)->key < key) {
      curr_node = &(*curr_node)->right;
    }
  }

  *curr_node = malloc(sizeof(struct node));

  (*curr_node)->val = val;
  (*curr_node)->key = key;
  (*curr_node)->left = NULL;
  (*curr_node)->right = NULL;
}

void* tree_pop(struct tree* tree) {
  if (tree->root == NULL) return NULL;
  struct node* root = tree->root;
  void* val = root->val;

  if (root->left != NULL) {
    tree->root = root->left;
  } else {
    tree->root = root->right;
  }
  free(root);
  return val;
}

enum result tree_destroy(struct tree** tree) {
  if (*tree == NULL) return destroyed;
  if ((*tree)->root != NULL) return full;
  free(*tree);
  tree = NULL;
  return empty;
}
