#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include "stack.h"
  
struct StackNode* newNode(symb_table* sbtable) 
{ 
  struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode)); 
  stackNode->sbtable = sbtable; 
  stackNode->next = NULL; 
  return stackNode; 
} 
  
int is_empty(struct StackNode* root) 
{ 
  return !root; 
} 
  
void push(struct StackNode** root, symb_table* sbtable) 
{ 
  struct StackNode* stackNode = newNode(sbtable); 
  stackNode->next = *root; 
  *root = stackNode; 
} 
  
symb_table* pop(struct StackNode** root) 
{ 
  //printf("Entro pop.\n");
  if (is_empty(*root)) 
  {
    return NULL; 
  }
  //printf("Checou se empty dentro de pop.\n");
  struct StackNode* temp = *root; 
  //printf("root vai receber (*root)->next dentro de pop().\n");
  //if (root == NULL) printf("root eh NULL dentro de pop e vai ter seu next lido.\n");
  //if (*root == NULL) printf("*root eh NULL dentro de pop e vai ter seu next lido.\n");
  //if ((*root)->next == NULL) printf("(*root)->next eh NULL dentro de pop e vai ser posto em *root.\n");
  //if (*root == (*root)->next) printf("*root e (*root)->next dentro de pop() sao iguais.\n");
  *root = (*root)->next; 
  //printf("root recebeu (*root)->next dentro de pop().\n");
  symb_table* popped = temp->sbtable; 

  //ht_free(temp->sbtable->table);
  //free(temp->sbtable);
  free(temp); 

  return popped; 
} 
  
symb_table* peek(struct StackNode* root) 
{ 
  if (is_empty(root)) 
    return NULL; 
  return root->sbtable; 
} 

struct StackNode* new_stack()
{
  struct StackNode* root = NULL; 
  return root;
}

// Look for label on all scopes stacked.
void move_stack(struct StackNode* dst, struct StackNode* src)
{
  symb_table* scope = NULL;
  scope = pop(&src);
  while (scope != NULL)
  {
    push(&dst, scope);
    scope = pop(&src);
  }
}

symbol_entry* st_lookup(char* label, struct StackNode* scope_stack)
{
  //printf("st_lookup chamada.\n");
  stack* searched_scopes = NULL;
  symb_table* scope = NULL;

  scope = pop(&scope_stack);
  while (scope != NULL)
  {
    if (ht_lookup(label, scope) != NULL)
    {
      push(&searched_scopes, scope);
      move_stack(scope_stack, searched_scopes);
      return ht_lookup(label, scope);
    }
    push(&searched_scopes, scope);
    scope = pop(&scope_stack);
  }

  move_stack(scope_stack, searched_scopes);
  return NULL;
}