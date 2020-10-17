#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"


// Create hash table.
ht_entry** hash_table()
{
  ht_entry** ht = calloc(TABLE_SIZE, sizeof(struct ht_entry));
  return ht;
}

// Hash symbol.
int hash(symbol_entry* symbol)
{ 
  // Simple sum of characters.
  int hash = 0;
  
  for(int i = 0; i < strlen(symbol->label); i++)
  {
    hash += symbol->label[i];
  }

  return hash;
}

// Insert symbol in hashtable.
void ht_insert(symbol_entry* symbol, ht_entry** ht)
{
  int key = hash(symbol);

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
symbol_entry* ht_lookup(symbol_entry* symbol, ht_entry** ht)
{
  int key = hash(symbol);

  key %= TABLE_SIZE;

  if (ht[key] == NULL) return NULL;

  ht_entry* present_item = ht[key];

  do {
    if (strcmp(present_item->symbol->label, symbol->label) == 0)
    {
      return present_item->symbol;
    }
    present_item = present_item->next;
  } while (present_item != NULL);
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
      free(ht[i]->next);
      free(ht[i]);
    }   
  }
  free(ht);
}

void print_ht_entry(ht_entry** ht, int key)
{
  printf("HT entry label is: %s\n", ht[key%TABLE_SIZE]->symbol->label);
}