#include "parse_helper.h"


void add_variables_to_scope(int type, id_list* ids, ht_entry** scope)
{
  id_list* current = ids;
  int size;
  symbol_entry* sb = NULL;

  while(current != NULL)
  {
    // Check if declared already.
    if (ht_lookup(current->id, scope) != NULL && ht_lookup(current->id, scope)->symbol_type != LIT)
    {
      syntactic_error(ERR_DECLARED, NULL, -1, ht_lookup(current->id, scope));
    }
    // Check if initialized with different type object.
    if (current->ini_type != NOT_INITIALIZED && current->ini_type != type)
      syntactic_error(ERR_WRONG_TYPE, current->id, current->line, NULL);

    if (current->vec_size == NOT_A_VECTOR)
    {
      switch (type)
      {
        case CHAR:
        case BOOL:
          size = 1;
          break;
        case INT:
          size = 4;
          break;
        case FLOAT:
          size = 8;
          break;
        case STR:
          size = current->str_size;
          break;
        default:
          size = -1;
      }
      sb = new_symbol_entry(current->id, current->line, VAR, type, size, NULL, NULL);
    }
    else // Is a vector.
    {
      switch (type)
      {
        case CHAR:
        case BOOL:
          size = 1 * current->vec_size;
          break;
        case INT:
          size = 4 * current->vec_size;
          break;
        case FLOAT:
          size = 8 * current->vec_size;
          break;
        case STR:
          if (current->str_size != NOT_INITIALIZED)
            size = current->str_size * current->vec_size;
          else size = NOT_INITIALIZED;
          break;
        default:
          size = -1;
      }
      sb = new_symbol_entry(current->id, current->line, VEC, type, size, NULL, NULL);
    }

    ht_insert(sb, scope);
    current = current->next;
  }
}

id_list* new_id_list(lex_val* id, int vec_size)
{
  id_list* ids = malloc(sizeof(struct id_list_item));
  ids->id = id->value.s;
  ids->line = id->line;
  ids->vec_size = vec_size;
  ids->str_size = NOT_A_STRING;
  ids->ini_type = NOT_INITIALIZED;
  ids->next = NULL;

  return ids;
}

void add_functions_to_scope(int type, lex_val* id, arg_list* params, ht_entry** scope)
{
  // Determine size.
  int size;
  switch (type)
  {
    case CHAR:
    case BOOL:
      size = 1;
      break;
    case INT:
      size = 4;
      break;
    case FLOAT:
      size = 8;
      break;
    default:
      size = -1;
  }

  // Add function name to scope.
  symbol_entry* sb = new_symbol_entry(id->value.s, id->line, FUNC, type, size, params, id);
  if (ht_lookup(sb->label, scope) != NULL)
  {
    syntactic_error(ERR_DECLARED, NULL, -1, ht_lookup(sb->label, scope));
  }
  ht_insert(sb, scope);
}

arg_list* new_arg_list(int type, lex_val* id)
{
  arg_list* param_list = malloc(sizeof(struct arg_list_item));
  param_list->id = id->value.s;
  param_list->line = id->line;
  param_list->type = type;
  param_list->next = NULL;
}

