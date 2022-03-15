#include <stdlib.h>
#include "../utils.h"
#include "tree.h"

#include <stdio.h>

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

struct node** predecessor(struct node* node) {
  if (node == NULL) return NULL;
  struct node** curr_node = &node->left;

  while ((*curr_node)->right != NULL) {
    (*curr_node) = (*curr_node)->right;
  }

  return curr_node;
}

void* node_delete(struct node** root, unsigned int key) {
  if (*root == NULL) return NULL;

  while ((*root)->key != key) {
    if ((*root)->key < key) {
      root = &(*root)->left;
    } else if ((*root)->key > key) {
      root = &(*root)->right;
    } else {
      return NULL;
    }
  }
  void* ret = (*root)->val;

  struct node* tmp = *root;
  if ((*root)->left == NULL) {
    struct node* right = (*root)->right;
    *root = right;
  } else if ((*root)->right == NULL) {
    struct node* left = (*root)->left;
    *root = left;
  } else {
    struct node** pred = predecessor(*root);
    struct node* left = (*pred)->left;

    (*pred)->right = (*root)->right;
    *root = *pred;
    *pred = left;
  }

  free(tmp);
  return ret;
}

void* tree_delete(struct tree* tree, unsigned int key) {
  if (tree->root == NULL) return NULL;
  return node_delete(&tree->root, key);
}

void* tree_pop(struct tree* tree) {
  if (tree->root == NULL) return NULL;
  return tree_delete(tree, tree->root->key);
}

enum result tree_destroy(struct tree** tree) {
  if (*tree == NULL) return destroyed;
  if ((*tree)->root != NULL) return full;
  free(*tree);
  tree = NULL;
  return empty;
}
