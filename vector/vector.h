struct vec {
  unsigned int cap; // Should propably change this type
  unsigned int len;
  void** arr;
};

struct vec* vec_new();

void vec_push(struct vec* vec, void* val);

void* vec_pop(struct vec* vec);

enum result vec_destroy();
