#ifndef STACK_H
#define STACK_H

#include "hash.h"

// A structure to represent a stack 
typedef struct StackNode { 
  symb_table* sbtable; 
  struct StackNode* next; 
} stack; 

int is_empty(struct StackNode* root);
void push(struct StackNode** root, symb_table* ht);
symb_table* pop(struct StackNode** root);
symb_table* peek(struct StackNode* root);
stack* new_stack();

// Look for a label in all scopes stacked.
void move_stack(struct StackNode* dst, struct StackNode* src);
symbol_entry* st_lookup(char* label, struct StackNode* root);

#endif