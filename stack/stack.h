// #ifndef HEADER_FILE
// #define HEADER_FILE

struct node {
  struct node* next;
  void* val;
};

struct stack {
  struct node* head;
};

struct stack* stack_new();

void stack_push(struct stack* stack, void* val);

void* stack_pop(struct stack* stack);

enum result stack_destroy(struct stack** stack);

// #endif
