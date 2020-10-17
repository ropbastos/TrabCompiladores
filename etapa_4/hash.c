#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"


// Create hash table.
item** hash_table()
{
  item** ht = calloc(TABLE_SIZE, sizeof(struct item));
  return ht;
}

// Hash symbol.
int hash(symbol* symbol)
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
void ht_insert(symbol* symbol, item** ht)
{
  int key = hash(symbol);

  key %= TABLE_SIZE;

  printf("INSERT GENERATED KEY: %d\n", key);

  // Make new table entry.
  item* newptr = malloc(sizeof(item));
  newptr->symbol = symbol;
  newptr->next = NULL;

  // Check for empty list.
  if (ht[key] == NULL)
  {
    ht[key] = newptr;
  }
  else
  {
    item* prevptr = ht[key];
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


item* ht_lookup(symbol* symbol, item** ht)
{
  int key = hash(symbol);

  key %= TABLE_SIZE;

  if (ht[key] == NULL) return NULL;

  item* present_item = ht[key];

  do {
    if (strcmp(present_item->symbol->label, symbol->label) == 0)
    {
      return present_item;
    }
    present_item = present_item->next;
  } while (present_item != NULL);
}

void print_ht_entry(item** ht, unsigned long key)
{
  printf("HT entry label is: %s\n", ht[key%TABLE_SIZE]->symbol->label);
}