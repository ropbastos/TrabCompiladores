#include <stdlib.h>
#include <stdio.h>
#include "idlist.h"

void add_id(id_list* list, lex_val* id, int vec_size)
{
  if (list == NULL) return;

  id_list* current = list;

  while (current->next != NULL)
  {
    current = current->next;
  }

  current->next = (id_list*) malloc(sizeof(id_list));
  current->next->id = id->value.s;
  current->next->line = id->line;
  current->next->vec_size = vec_size;
  current->next->next = NULL;
}

void print_ids(id_list* list)
{
  id_list* current = list;

  while (current != NULL)
  {
    printf("Global var in list: %s\n", current->id);
    current = current->next;
  }
}