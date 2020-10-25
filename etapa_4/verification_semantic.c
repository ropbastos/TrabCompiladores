#include <stdio.h>
#include <stdlib.h>
#include "errors.h"

ht_entry** get_scope(struct StackNode** scope_stack) {
  ht_entry** global_scope = pop(scope_stack);
  if (global_scope == NULL) {
    global_scope = hash_table();
  }
  return global_scope;
}

ht_entry** add_to_scope(id_list* current, int type, int symbol_type, ht_entry** scope){
  int size;
  symbol_entry* sb = NULL;

  while(current != NULL) {
    if (ht_lookup(current->id, scope) != NULL) syntactic_error(ERR_DECLARED, NULL, -1, ht_lookup(current->id, scope));

    if (current->vec_size == NOT_A_VECTOR){
      switch (type) {
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

    } else {
      symbol_type = VEC;
      switch (type) {
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
        default:
          size = -1;
      }
    }
    sb = new_symbol_entry(current->id, current->line, symbol_type, type, size, NULL, NULL);
    ht_insert(sb, scope);
    current = current->next;
  }

  return scope;
}

symbol_entry* add_to_func_scope(lex_val* current, int type, struct StackNode** scope_stack, ht_entry** scope,  arg_list* args, lex_val* val) {
  int size;
  switch (type){
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
  symbol_entry* sb = new_symbol_entry(current->value.s, current->line, FUNC, type, size, args, val);
  if (ht_lookup(sb->label, scope) != NULL){
    syntactic_error(ERR_DECLARED, NULL, -1, ht_lookup(sb->label, scope));
  }

  ht_insert(sb, scope);
  push(scope_stack, scope);

  return sb;
}

id_list* get_global_id(lex_val* id, int vec_size){

  id_list* global_ids = malloc(sizeof(struct id_list_item));

  global_ids->id = id->value.s;
  global_ids->line = id->line;
  global_ids->vec_size = vec_size;
  global_ids->next = NULL;

  return global_ids;
}

arg_list* get_args_list(lex_val* id, int type) {
  arg_list* param_list = malloc(sizeof(struct arg_list_item));
  param_list->id = id->value.s;
  param_list->line = id->line;
  param_list->type = type;
  param_list->next = NULL;
}

int get_data_type(node* one, node* second, int line) {
  if (one->data_type == INT && second->data_type == INT) return INT;
  if (one->data_type == FLOAT && second->data_type == FLOAT) return FLOAT;
  if (one->data_type == BOOL && second->data_type == BOOL) return BOOL;
  if (one->data_type == FLOAT && second->data_type == INT || one->data_type == INT && second->data_type == FLOAT) return FLOAT;
  if (one->data_type == BOOL && second->data_type == INT || one->data_type == INT && second->data_type == BOOL) return INT;
  if (one->data_type == BOOL && second->data_type == FLOAT || one->data_type == FLOAT && second->data_type == BOOL) return FLOAT;
  if (one->data_type == CHAR && second->data_type != CHAR) syntactic_error(ERR_CHAR_TO_X, one->label, line, NULL);
  if (one->data_type != CHAR && second->data_type == CHAR) syntactic_error(ERR_CHAR_TO_X, second->label, line, NULL);
  if (one->data_type == STR && second->data_type != STR) syntactic_error(ERR_STRING_TO_X, one->label, line, NULL);
  if (one->data_type != STR && second->data_type == STR) syntactic_error(ERR_STRING_TO_X, second->label, line, NULL);
}
