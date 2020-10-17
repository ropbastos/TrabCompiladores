#include "ast.h"
#define TABLE_SIZE 26

// Table symbol.
typedef struct symbol {
  char* label;
  char** args;
  int line;
  int node_type;
  int data_type;
  int size;
} symbol;

/* Linked lists in each entry for handling collisions */
// List item.
typedef struct item
{
  symbol* symbol;
  struct item* next;
}
item;

item** hash_table();
int hash(symbol* item);
void ht_insert(symbol* symbol, item** ht);
item* ht_lookup(symbol* symbol, item** ht);
void print_ht_entry(item** ht, unsigned long key);