#include "stack.h"
#define NOT_A_VECTOR -1

// ID lists

typedef struct id_list_item {
  char* id;
  int line;
  int vec_size;
  struct id_list_item* next;
} id_list;

void add_id(id_list* list, lex_val* id, int vec_size);
void print_ids(id_list* list);