
struct tree {
  void* val;
  struct tree* left;
  struct tree* right;
}

struct tree* tree_new();

void tree_push(struct tree* tree, void* val);

void* tree_pop(struct tree* tree);

enum result tree_destroy(struct tree** tree);
