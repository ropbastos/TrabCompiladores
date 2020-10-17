#include "ast.h"
#define TABLE_SIZE 26

// Table symbol.
typedef struct symbol_entry {
  char* label;
  char** args;
  int line;
  int node_type;
  int data_type;
  int size;
} symbol_entry;

/* Linked lists in each entry for handling collisions */
// List item.
typedef struct ht_entry
{
  symbol_entry* symbol;
  struct ht_entry* next;
}
ht_entry;

ht_entry** hash_table();
int hash(symbol_entry* item);
void ht_insert(symbol_entry* symbol, ht_entry** ht);
ht_entry* ht_lookup(symbol_entry* symbol, ht_entry** ht);
void print_ht_entry(ht_entry** ht, int key);