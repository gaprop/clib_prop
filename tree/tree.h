
struct tree {
  unsigned int key;
  void* val;
  struct tree* left;
  struct tree* right;
};

struct tree* tree_new();

// the compare value needs a different type, propably
void tree_push(struct tree* tree, void* val, unsigned int key);

void* tree_pop(struct tree* tree);

enum result tree_destroy(struct tree** tree);
