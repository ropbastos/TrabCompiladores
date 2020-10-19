#include "lexval.h"

typedef struct arg_list_item {
  char* id;
  int line;
  int type;
  struct arg_list_item* next;
} arg_list;

void add_arg(arg_list* list, lex_val* id, int type);