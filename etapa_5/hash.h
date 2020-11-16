#ifndef HASH_H
#define HASH_H

#include "ast.h"
#define TABLE_SIZE 26

#define FUNC 80
#define VAR 81
#define LIT 82
#define VEC 83

// Arg lists
typedef struct arg_list_item {
  char* id;
  int line;
  int type;
  struct arg_list_item* next;
} arg_list;

void add_arg(arg_list** list, lex_val* id, int type);
void add_arg_call(arg_list* list, arg_list* to_add);
void print_args(arg_list* list);
int arg_list_len(arg_list* list);

// Table symbol.
typedef struct symbol_entry {
  char* label;
  int line, column;
  int symbol_type;
  int data_type;
  int size;
  int offset;
  int is_global;
  struct arg_list_item* args;
  char* iloc_func_label;
  lex_val* val;
} symbol_entry;

symbol_entry* new_symbol_entry(char* label, int line, int symbol_type, int data_type,
                               int size, arg_list* args, lex_val* val, int offset, 
                               int is_global, char* iloc_label);

/* Linked lists in each entry for handling collisions */
// List item.
typedef struct ht_entry
{
  symbol_entry* symbol;
  struct ht_entry* next;
}
ht_entry;

// Symbol table struct.
typedef struct {
  int is_global;
  int offset;
  ht_entry** table;
} symb_table;

ht_entry** hash_table();
symb_table* symbol_table(int offset);
int hash(char* label);
void ht_insert(symbol_entry* symbol, symb_table* table);
symbol_entry* ht_lookup(char* label, symb_table* table);

void ht_free_aux(ht_entry* entry);
void ht_free(ht_entry** ht);
void ht_print(ht_entry** ht);
void print_ht_entry(ht_entry** ht, int key);

#endif