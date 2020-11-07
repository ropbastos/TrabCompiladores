#include "parse_helper.h"
#include <string.h>


void add_variables_to_scope(int type, id_list* ids, symb_table* scope)
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
      sb = new_symbol_entry(current->id, current->line, VAR, type, size, NULL, NULL, scope->offset);
      scope->offset += size;
    }
    else // Is a vector. OFFSET NOT BEING CALCULATED AS OF E5 FOR VECTORS.
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
      sb = new_symbol_entry(current->id, current->line, VEC, type, size, NULL, NULL, 0);
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

void add_functions_to_scope(int type, lex_val* id, arg_list* params, symb_table* scope)
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
  symbol_entry* sb = new_symbol_entry(id->value.s, id->line, FUNC, type, size, params, id, 0);
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

void generic_attrib_errors_check(lex_val* id, node* exp, int should_be_vector, stack* scope_stack, int line)
{
  symbol_entry* dst_lookup = st_lookup(id->value.s, scope_stack);
  symbol_entry* src_lookup = st_lookup(exp->label, scope_stack);
  // See if dst is declared.
  if (dst_lookup == NULL)
  {
    syntactic_error(ERR_UNDECLARED, id->value.s, line, NULL);
  }

  // See if src is declared.
  if (src_lookup == NULL && exp->val != NULL && strcmp(exp->label, "True") != 0 && strcmp(exp->label, "False") != 0)
  {
    syntactic_error(ERR_UNDECLARED, exp->label, line, NULL);
  }
  
  // Check types.
  if (dst_lookup->data_type == STR && exp->data_type != STR)
  {
    syntactic_error(ERR_STRING_TO_X, id->value.s, line, dst_lookup);
  }
  if (dst_lookup->data_type == CHAR && exp->data_type != CHAR)
  {
    syntactic_error(ERR_CHAR_TO_X, id->value.s, line, dst_lookup);
  }
  if (dst_lookup->data_type != STR && exp->data_type == STR)
  {
    syntactic_error(ERR_WRONG_TYPE, id->value.s, line, dst_lookup);
  }
  if (dst_lookup->data_type != CHAR && exp->data_type == CHAR)
  {
    syntactic_error(ERR_WRONG_TYPE, id->value.s, line, dst_lookup);
  }

  // See if dst is of correct type.
  if (should_be_vector == 0)
  {
    if (dst_lookup->symbol_type != VAR)
    {
      if (dst_lookup->symbol_type == VEC)
        syntactic_error(ERR_VECTOR, id->value.s, line, NULL);
      if (dst_lookup->symbol_type == FUNC)
        syntactic_error(ERR_FUNCTION, id->value.s, line, NULL);
    }
  } 
  else
  {
    if (dst_lookup->symbol_type != VEC)
      {
        if (dst_lookup->symbol_type == VAR)
          syntactic_error(ERR_VARIABLE, id->value.s, line, NULL);
        if (dst_lookup->symbol_type == FUNC)
          syntactic_error(ERR_FUNCTION, id->value.s, line, NULL);
      }
  }

  // If dst is a string, check size compatibility.
  if (dst_lookup->data_type == STR && dst_lookup->size != NOT_A_STRING 
      && exp->size > dst_lookup->size)
    syntactic_error(ERR_STRING_SIZE, id->value.s, line, NULL);

  // If dst is a string, but was not initialized or attributed to before and thus has no size
  // set it's size according to the first attribution.
  if (dst_lookup->data_type == STR && dst_lookup->size == NOT_A_STRING)
  {
    dst_lookup->size = exp->size;
  }
}

void binary_exp_type_and_error_check(node* binary_operator, node* left_exp, node* right_exp, int line)
{
  if (left_exp->data_type == INT && right_exp->data_type == INT) binary_operator->data_type = INT;
  if (left_exp->data_type == FLOAT && right_exp->data_type == FLOAT) binary_operator->data_type = FLOAT;
  if (left_exp->data_type == BOOL && right_exp->data_type == BOOL) binary_operator->data_type = BOOL;
  if (left_exp->data_type == FLOAT && right_exp->data_type == INT
    || left_exp->data_type == INT && right_exp->data_type == FLOAT) binary_operator->data_type = FLOAT;
  if (left_exp->data_type == BOOL && right_exp->data_type == INT
    || left_exp->data_type == INT && right_exp->data_type == BOOL) binary_operator->data_type = INT;
  if (left_exp->data_type == BOOL && right_exp->data_type == FLOAT
    || left_exp->data_type == FLOAT && right_exp->data_type == BOOL) binary_operator->data_type = FLOAT;
  if (left_exp->data_type == CHAR && right_exp->data_type == CHAR) binary_operator->data_type = CHAR;
  if (left_exp->data_type == CHAR && right_exp->data_type != CHAR)
    syntactic_error(ERR_CHAR_TO_X, left_exp->label, line, NULL);
  if (left_exp->data_type != CHAR && right_exp->data_type == CHAR)
    syntactic_error(ERR_CHAR_TO_X, right_exp->label, line, NULL);
  if (left_exp->data_type == STR && right_exp->data_type != STR)
    syntactic_error(ERR_STRING_TO_X, left_exp->label, line, NULL);
  if (left_exp->data_type != STR && right_exp->data_type == STR)
    syntactic_error(ERR_STRING_TO_X, right_exp->label, line, NULL);
  if (left_exp->data_type == STR && right_exp->data_type == STR)
    if (strcmp(binary_operator->label, "+") == 0)
    {
      binary_operator->data_type = STR; 
      binary_operator->size = left_exp->size + right_exp->size;
    }
    else
    {
      syntactic_error(ERR_STRING_TO_X, right_exp->label, line, NULL);
    }     
}

int shift_val_check(lex_val* id, lex_val* shift_amount, stack* scope_stack, int line)
{
  if (shift_amount->value.i > 16)
  {
    syntactic_error(ERR_WRONG_PAR_SHIFT, NULL, line, NULL);
  }
  symbol_entry* lookup_result = st_lookup(id->value.s, scope_stack);
  if(lookup_result == NULL)
  {
    syntactic_error(ERR_UNDECLARED, id->value.s, line, NULL);
  }

  return lookup_result->data_type;
}

