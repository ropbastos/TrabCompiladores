#include "hash.h"

// A structure to represent a stack 
typedef struct StackNode { 
  ht_entry** ht; 
  struct StackNode* next; 
} stack; 

int is_empty(struct StackNode* root);
void push(struct StackNode** root, ht_entry** ht);
ht_entry** pop(struct StackNode** root);
ht_entry** peek(struct StackNode* root);
stack* new_stack();