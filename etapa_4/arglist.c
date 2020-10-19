#include <stdlib.h>
#include <stdio.h>
#include "arglist.h"

void add_arg(arg_list* list, lex_val* id, int type)
{
  if (list == NULL) return;

  arg_list* current = list;

  while (current->next != NULL)
  {
    current = current->next;
  }

  current->next = (arg_list*) malloc(sizeof(arg_list));
  current->next->id = id->value.s;
  current->next->line = id->line;
  current->next->type = type;
  current->next->next = NULL;
}