// C program for linked list implementation of stack 
#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include "stack.h"
  
struct StackNode* newNode(ht_entry** ht) 
{ 
  struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode)); 
  stackNode->ht = ht; 
  stackNode->next = NULL; 
  return stackNode; 
} 
  
int is_empty(struct StackNode* root) 
{ 
  return !root; 
} 
  
void push(struct StackNode** root, ht_entry** ht) 
{ 
  struct StackNode* stackNode = newNode(ht); 
  stackNode->next = *root; 
  *root = stackNode; 
} 
  
ht_entry** pop(struct StackNode** root) 
{ 
  if (is_empty(*root)) 
      return NULL; 
  struct StackNode* temp = *root; 
  *root = (*root)->next; 
  ht_entry** popped = temp->ht; 
  free(temp); 

  return popped; 
} 
  
ht_entry** peek(struct StackNode* root) 
{ 
  if (is_empty(root)) 
    return NULL; 
  return root->ht; 
} 

struct StackNode* new_stack()
{
  struct StackNode* root = NULL; 
  return root;
}