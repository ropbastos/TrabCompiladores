#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"


// Create hash table.
ht_entry** hash_table()
{
  ht_entry** ht = (ht_entry**) calloc(TABLE_SIZE, sizeof(struct ht_entry));
  return ht;
}

// Create symbol table.
symb_table* symbol_table(int offset)
{
  symb_table* sbtable = (symb_table*) malloc(sizeof(symb_table));
  sbtable->offset = offset;
  sbtable->is_global = 0;
  sbtable->table = hash_table();
  return sbtable; 
}

// Hash symbol.
int hash(char* label)
{ 
  // Simple sum of characters.
  int hash = 0;
  
  for(int i = 0; i < strlen(label); i++)
  {
    hash += label[i];
  }

  return hash;
}

// Insert symbol in hashtable.
void ht_insert(symbol_entry* symbol, symb_table* table)
{
  ht_entry** ht = table->table;
  if (ht == NULL) return;

  int key = hash(symbol->label);

  key %= TABLE_SIZE;

  // Make new table entry.
  ht_entry* newptr = malloc(sizeof(ht_entry));
  newptr->symbol = symbol;
  newptr->next = NULL;

  // Check for empty list.
  if (ht[key] == NULL)
  {
    ht[key] = newptr;
  }
  else
  {
    ht_entry* prevptr = ht[key];
    while (1)
    {
      // Insert at tail.
      if (prevptr->next == NULL)
      {
        prevptr->next = newptr;
        break;
      }
      // Update pointer.
      prevptr = prevptr->next;
    }
  }
}

// Look symbol up in hash table. 
symbol_entry* ht_lookup(char* label, symb_table* table)
{
  ht_entry** ht = table->table;
  if (ht == NULL) return NULL;

  int key = hash(label);

  key %= TABLE_SIZE;

  if (ht[key] == NULL) return NULL;

  ht_entry* present_item = ht[key];

  do {
    if (strcmp(present_item->symbol->label, label) == 0)
    {
      return present_item->symbol;
    }
    present_item = present_item->next;
  } while (present_item != NULL);

  return NULL;
}

// Free up hash table memory.
void ht_free_aux(ht_entry* entry)
{
  if (entry->next)
  {
    ht_free_aux(entry->next);
  }
  free(entry->symbol->label);
  if (entry->symbol->args) free(entry->symbol->args);
  free(entry->symbol);
  free(entry->next);
  free(entry);
}

void ht_free(ht_entry** ht)
{
  for (int i = 0; i < TABLE_SIZE; i++)
  {
    if (ht[i] != NULL)
    {
      if (ht[i]->next)
      {
        ht_free_aux(ht[i]->next);
      }
      free(ht[i]->symbol->label);
      if (ht[i]->symbol->args) free(ht[i]->symbol->args);
      free(ht[i]->symbol);
      free(ht[i]);
    }   
  }
  free(ht);
}


symbol_entry* new_symbol_entry(char* label, int line, int symbol_type,
                               int data_type, int size, arg_list* args,
                               lex_val* val, int offset, int is_global,
                               char* iloc_label)
  {
    symbol_entry* sb = malloc(sizeof(struct symbol_entry));
    sb->label = strdup(label);
    sb->line = line;
    sb->symbol_type = symbol_type;
    sb->data_type = data_type;
    sb->size = size;
    sb->offset = offset;
    sb->is_global = is_global;
    sb->args = args;
    sb->val = val;
    sb->iloc_func_label = (iloc_label) ? strdup(iloc_label) : NULL;

    return sb;
  }

void ht_print(ht_entry** ht)
{
  printf("\n");
  int j = 0;
  for (int i = 0; i < TABLE_SIZE; i++)
  {
    ht_entry* current_entry = ht[i];
    while (current_entry != NULL)
    {
      printf("Entry %d label: %s - size: %d, offset: %d\n",
       j, current_entry->symbol->label, current_entry->symbol->size,
       current_entry->symbol->offset);
      current_entry = current_entry->next;
      j++;
    }
  }
  printf("\n");
}

void print_ht_entry(ht_entry** ht, int key)
{
  printf("HT entry label is: %s, offset: %d\n",
         ht[key%TABLE_SIZE]->symbol->label, ht[key%TABLE_SIZE]->symbol->offset);
}


// Arg lists

void add_arg(arg_list** list, lex_val* id, int type)
{
  if (list == NULL) return;

  arg_list* new_arg = malloc(sizeof(struct arg_list_item));
  new_arg->id = id->value.s;
  new_arg->line = id->line;
  new_arg->type = type;
  new_arg->next = *list;
  *list = new_arg; 
}

void add_arg_call(arg_list* list, arg_list* to_add)
{
  if (list == NULL) return;

  arg_list* current = list;

  while (current->next != NULL)
  {
    current = current->next;
  }

  current->next = to_add;
}

void print_args(arg_list* list)
{
  if (list == NULL)
  {
    printf("NULL ARG LIST.\n");
    return;
  }

  arg_list* current = list;
  do {
    printf("arg item: %s\n", current->id);
    current = current->next;
  } while (current != NULL);
}

int arg_list_len(arg_list* list)
{
  if (list == NULL) return 0;

  arg_list* current = list;
  int len = 1;
  while (current->next != NULL)
  {
    current = current->next;
    len++;
  }

  return len;
}