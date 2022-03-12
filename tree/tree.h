
struct node {
  unsigned int key;
  void* val;
  struct node* left;
  struct node* right;
};

struct tree {
  struct node* root;
};

struct tree* tree_new();

// the compare value needs a different type, propably
void tree_push(struct tree* tree, void* val, unsigned int key);

void* tree_pop(struct tree* tree);

enum result tree_destroy(struct tree** tree);
