#include <stdlib.h>
#include "../utils.h"
#include "vector.h"

struct vec* vec_new() {
  struct vec* vec = malloc(sizeof(struct vec));

  vec->arr = calloc(1, sizeof(void*));
  vec->cap = 1;
  vec->len = 0;
  return vec;
}

void vec_push(struct vec* vec, void* val) {
  if (vec == NULL) return; // Perhaps make an error
  vec->arr[vec->len] = val;
  vec->len++;

  if (vec->len == vec->cap) {
    vec->cap = vec->cap * 2;
    vec->arr = reallocarray(vec->arr, vec->cap, sizeof(void*));
  }
}

void* vec_pop(struct vec* vec) {
  if (vec == NULL) return NULL; // Perhaps make an error
  if (vec->len == 0) return NULL;
  void* ret = vec->arr[vec->len - 1];
  vec->len--;

  if (vec->cap == 1) {
    vec->arr[vec->len] = NULL;
    return ret;
  }
  if (vec->len == (vec->cap / 4)) {
    void** old_arr = vec->arr;
    vec->cap = vec->cap / 2;
    vec->arr = calloc(vec->cap, sizeof(void*));
    for (int i = 0; i < vec->len; i++) {
      vec->arr[i] = old_arr[i];
    }
    free(old_arr);
  }

  return ret;
}

enum result vec_destroy(struct vec** vec) {
  if (*vec == NULL) return destroyed;
  if ((*vec)->len != 0) return full;
  free((*vec)->arr);
  free(*vec);
  vec = NULL;
  return empty;
}
