#ifndef NAMELISTS_H
#define NAMELISTS_H

#include "stack.h"
#define NOT_A_VECTOR -1
#define NOT_A_STRING -2
#define NOT_INITIALIZED -3

// ID lists

typedef struct id_list_item {
  char* id;
  int line;
  int vec_size;
  int str_size;
  int ini_type;
  int has_hole;
  struct id_list_item* next;
} id_list;

void add_id(id_list** list, lex_val* id, int vec_size, int str_size, int ini_type, int offset);
void print_ids(id_list* list);
int id_list_len(id_list* list);

#endif