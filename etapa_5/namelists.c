#include <stdlib.h>
#include <stdio.h>
#include "namelists.h"

// ID lists.

void add_id(id_list** list, lex_val* id, int vec_size, int str_size, int ini_type)
{
  if (list == NULL) return;

  id_list* new_id = (id_list*) malloc(sizeof(id_list));
  new_id->id = id->value.s;
  new_id->line = id->line;
  new_id->vec_size = vec_size;
  new_id->str_size = str_size;
  new_id->ini_type = ini_type;
  new_id->next = *list;
  *list = new_id;
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


