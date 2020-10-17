#include "ast.h"
#define TABLE_SIZE 26

#define FUNC 80

// Table symbol.
typedef struct symbol_entry {
  char* label;
  int line, column;
  int symbol_type;
  int data_type;
  int size;
  char** args;
  TOKEN_VAL val;
} symbol_entry;

symbol_entry* new_symbol_entry(char* label, int line, int column, int symbol_type,
                               int data_type, int size, char** args, lex_val* val);

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
symbol_entry* ht_lookup(symbol_entry* symbol, ht_entry** ht);
void ht_free_aux(ht_entry* entry);
void ht_free(ht_entry** ht);
void print_ht_entry(ht_entry** ht, int key);