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

// Look for a label in all scopes stacked.
void move_stack(struct StackNode* dst, struct StackNode* src);
symbol_entry* st_lookup(char* label, struct StackNode* root);