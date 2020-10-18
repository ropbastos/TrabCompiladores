#include "stack.h"

typedef struct id_list_item {
  char* id;
  int line;
  struct id_list_item* next;
} id_list;

void add_id(id_list* list, lex_val* id);
void print_ids(id_list* list);

