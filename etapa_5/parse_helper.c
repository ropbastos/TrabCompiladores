#include <string.h>
#include "parse_helper.h"
#include "iloc.h"
#include "stack.h"

int prev_offset = -1;


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
      sb = new_symbol_entry(current->id, current->line, VAR, type,
                             size, NULL, NULL, scope->offset, scope->is_global, NULL);
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
      sb = new_symbol_entry(current->id, current->line, VEC, type,
                             size, NULL, NULL, 0, scope->is_global, NULL);
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
  symbol_entry* sb = new_symbol_entry(id->value.s, id->line, FUNC, type,
                                       size, params, id, 0, scope->is_global, label());
  if (ht_lookup(sb->label, scope) != NULL)
  {
    syntactic_error(ERR_DECLARED, NULL, -1, ht_lookup(sb->label, scope));
  }
  ht_insert(sb, scope);
}

void add_args_to_scope(symb_table* scope, arg_list* args)
{
  arg_list* current = args;
  while (current != NULL)
  {
    symbol_entry* sb = new_symbol_entry(current->id, 0, VAR, INT, 4, 
                                        NULL, NULL, scope->offset, 0, NULL);
    ht_insert(sb, scope);
    scope->offset += 4;
    current = current->next;
  }
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
  if (src_lookup == NULL && exp->val != NULL 
      && strcmp(exp->label, "True") != 0 && strcmp(exp->label, "False") != 0
      && strcmp(exp->label, "&&") != 0 && strcmp(exp->label, "||") != 0
      && strcmp(exp->label, "==") != 0 && strcmp(exp->label, "!=") != 0
      && strcmp(exp->label, "<=") != 0 && strcmp(exp->label, ">=") != 0)
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

void generate_binary_exp_code(node* op, node* left_exp, node* right_exp, inst* inst, char* temp)
{
  op->temp = temp;
  concat_end(&(op->code), left_exp->code);
  concat_end(&(op->code), right_exp->code);
  insert_end(&(op->code), inst);
}

void gen_relop_code(node* exp, node* left_exp, node* right_exp)
{
  exp->temp = reg();
  
  inst* branch = new_inst(NULL, "cbr", exp->temp, NULL, "HOLE", "HOLE");
  insert_end(&(exp->code), branch);
  if (left_exp->t == NULL && right_exp->t == NULL)
  {
    exp->t = new_hole_list(&(exp->code->instruction->arg3));
  }
  else
  {
    hole_list_cat(&exp->t, &left_exp->t);
    hole_list_cat(&exp->t, &right_exp->t);
    hole_list* new_hole = new_hole_list(&(exp->code->instruction->arg3));
    hole_list_cat(&exp->t, &new_hole);
  }
  
  if (left_exp->f == NULL && right_exp->f == NULL)
  {
    exp->f = new_hole_list(&(exp->code->instruction->arg4));
  }
  else
  {
    hole_list_cat(&exp->f, &left_exp->f);
    hole_list_cat(&exp->f, &right_exp->f);
    hole_list* new_hole = new_hole_list(&(exp->code->instruction->arg4));
    hole_list_cat(&exp->f, &new_hole);
  }
  concat_end(&left_exp->code, right_exp->code);

  if (strcmp(exp->label, "<") == 0)
    insert_end(&right_exp->code, 
      new_inst(NULL, "cmp_LT", left_exp->temp, right_exp->temp, exp->temp, NULL)); 
  if (strcmp(exp->label, ">") == 0)
    insert_end(&right_exp->code, 
      new_inst(NULL, "cmp_GT", left_exp->temp, right_exp->temp, exp->temp, NULL)); 
  if (strcmp(exp->label, "==") == 0)
    insert_end(&right_exp->code, 
      new_inst(NULL, "cmp_EQ", left_exp->temp, right_exp->temp, exp->temp, NULL)); 
  if (strcmp(exp->label, ">=") == 0)
    insert_end(&right_exp->code, 
      new_inst(NULL, "cmp_GE", left_exp->temp, right_exp->temp, exp->temp, NULL)); 
  if (strcmp(exp->label, "<=") == 0)
    insert_end(&right_exp->code, 
      new_inst(NULL, "cmp_LE", left_exp->temp, right_exp->temp, exp->temp, NULL)); 
  if (strcmp(exp->label, "!=") == 0)
    insert_end(&right_exp->code, 
      new_inst(NULL, "cmp_NE", left_exp->temp, right_exp->temp, exp->temp, NULL));
       
  concat_end(&right_exp->code, exp->code);
  exp->code = left_exp->code;
}

void gen_logicop_code(node* op, node* left_exp, node* right_exp)
{
  op->temp = reg();

  if (strcmp(op->label, "&&") == 0)
  {
    char* true_label = label();
    patch(left_exp->t, true_label);
    hole_list_cat(&op->t, &right_exp->t);
    hole_list_cat(&op->f, &left_exp->f);
    hole_list_cat(&op->f, &right_exp->f);
    concat_end(&op->code, left_exp->code);
    insert_end(&op->code, new_inst(true_label, "nop", NULL, NULL, NULL, NULL));
    concat_end(&op->code, right_exp->code);
  }
  else if (strcmp(op->label, "||") == 0)
  {
    char* false_label = label();
    patch(left_exp->f, false_label);
    hole_list_cat(&op->f, &right_exp->f);
    hole_list_cat(&op->t, &left_exp->t);
    hole_list_cat(&op->t, &right_exp->t);
    concat_end(&op->code, left_exp->code);
    insert_end(&op->code, new_inst(false_label, "nop", NULL, NULL, NULL, NULL));
    concat_end(&op->code, right_exp->code);
  }
  else if(strcmp(op->label, "!") == 0)
  {
    hole_list_cat(&op->t, &left_exp->f);
    hole_list_cat(&op->f, &left_exp->t);
    concat_end(&op->code, left_exp->code);
  }
}

void gen_bool_lit_exp_code(node* exp)
{
  if (strcmp(exp->label, "True") == 0)
  {
    insert_end(&exp->code, new_inst(NULL, "jumpI", NULL, NULL, "HOLE", NULL));
    hole_list* new_hole = new_hole_list(&(exp->code->instruction->arg3));
    hole_list_cat(&exp->t, &new_hole);
  }
  else if (strcmp(exp->label, "False") == 0)
  {
    insert_end(&exp->code, new_inst(NULL, "jumpI", NULL, NULL, "HOLE", NULL));
    hole_list* new_hole = new_hole_list(&(exp->code->instruction->arg3));
    hole_list_cat(&exp->f, &new_hole);
  }
}

void gen_if_code(node* ifcmd, node* cond, node* true_block, node* false_block)
{
  char* true_label = label();
  char* false_label = label();

  patch(cond->t, true_label);
  patch(cond->f, false_label);

  if (false_block == NULL)
  {
    concat_end(&ifcmd->code, cond->code);
    insert_end(&ifcmd->code, new_inst(true_label, "nop", NULL, NULL, NULL, NULL));
    concat_end(&ifcmd->code, true_block->code);
    insert_end(&ifcmd->code, new_inst(false_label, "nop", NULL, NULL, NULL, NULL));
  }
  else
  {
    char* end_label = label();
    concat_end(&ifcmd->code, cond->code);
    insert_end(&ifcmd->code, new_inst(true_label, "nop", NULL, NULL, NULL, NULL));
    concat_end(&ifcmd->code, true_block->code);
    insert_end(&ifcmd->code, new_inst(NULL, "jumpI", NULL, NULL, end_label, NULL));
    insert_end(&ifcmd->code, new_inst(false_label, "nop", NULL, NULL, NULL, NULL));
    concat_end(&ifcmd->code, false_block->code);
    insert_end(&ifcmd->code, new_inst(end_label, "nop", NULL, NULL, NULL, NULL));
  }
}

void gen_while_code(node* while_cmd, node* cond, node* block)
{
  char* true_label = label();
  char* false_label = label();
  char* loop_label = label();

  patch(cond->t, true_label);
  patch(cond->f, false_label);
  insert_end(&while_cmd->code, new_inst(loop_label, "nop", NULL, NULL, NULL, NULL));
  concat_end(&while_cmd->code, cond->code);
  insert_end(&while_cmd->code, new_inst(true_label, "nop", NULL, NULL, NULL, NULL));
  concat_end(&while_cmd->code, block->code);
  insert_end(&while_cmd->code, new_inst(NULL, "jumpI", NULL, NULL, loop_label, NULL));
  insert_end(&while_cmd->code, new_inst(false_label, "nop", NULL, NULL, NULL, NULL));
}

void gen_for_code(node* for_cmd, node* initialization, node* cond, node* afterthought, node* block)
{
  if (initialization != NULL)
    concat_end(&for_cmd->code, initialization->code);
  
  char* true_label = label();
  char* false_label = label();
  patch(cond->t, true_label);
  patch(cond->f, false_label);
  char* loop_label = label();
  insert_end(&for_cmd->code, new_inst(loop_label, "nop", NULL, NULL, NULL, NULL));
  if (cond != NULL)
    concat_end(&for_cmd->code, cond->code);
  insert_end(&for_cmd->code, new_inst(true_label, "nop", NULL, NULL, NULL, NULL));
  if (block->code != NULL)
    concat_end(&for_cmd->code, block->code);
  if (afterthought != NULL)
    concat_end(&for_cmd->code, afterthought->code);
  insert_end(&for_cmd->code, new_inst(NULL, "jumpI", NULL, NULL, loop_label, NULL));
  insert_end(&for_cmd->code, new_inst(false_label, "nop", NULL, NULL, NULL ,NULL));
}

node* find_return_node(node* tree)
{
  if (tree == NULL) return NULL;
  if (tree->is_return) return tree;

  node* return_node;

  if (tree->child_num)
  {
    for (int i = 0; i < tree->child_num; i++)
    {
      return_node = find_return_node(tree->children[i]);
      if (return_node != NULL)
      {
        return return_node;
      }
    }
  }
  return NULL;
}

void gen_func_code(node* header, node* body, int offset, symb_table* scope, stack* scope_stack)
{
  int is_main = 0;
  if (strcmp(header->label, "main") == 0)
    is_main = 1;

  // Iguala rsp e rfp.
  symbol_entry* func = st_lookup(header->label, scope_stack);
  if (is_main == 0)
  {
    insert_end(&header->code, new_inst(func->iloc_func_label, "i2i", "rsp", NULL, "rfp", NULL));
  }
  else
  {
    insert_end(&header->code, new_inst("L0", "i2i", "rsp", NULL, "rfp", NULL));
  }
  
  // Abre espaco pras variaveis locais e argumentos.
  if (is_main && offset != 0)
    insert_end(&header->code, new_inst(NULL, "addI", "rsp", arg(offset), "rsp", NULL));
  // Final do prologo.
  if (is_main == 0)
    insert_end(&header->code, new_inst(NULL, "addI", "rsp", arg(16+arg_list_len(func->args)*4), "rsp", NULL));
  // Obtem os parametros.
  int param_num = arg_list_len(func->args);
  char* reg_param = reg();
  for (int i = 0; i < param_num; i++)
  {
    insert_end(&header->code, new_inst(NULL, "loadAI", "rfp", arg(12+i*4), reg_param, NULL));
    insert_end(&header->code, new_inst(NULL, "storeAI", reg_param, NULL, "rfp", arg(20+i)));
  }
  // Insere codigo do corpo.
  if (body != NULL)
    concat_end(&header->code, body->code);
  // Sequencia de retorno.
  node* return_node = find_return_node(body);
  if (return_node != NULL)
  {
    symbol_entry* return_val = ht_lookup(return_node->children[0]->label, scope);
    char* ret_reg = reg();
    // Retorno é um literal.
    if (return_val != NULL && return_val->symbol_type == LIT)
    {
      int ret_val = return_node->children[0]->val->value.i;
      insert_end(&header->code, new_inst(NULL, "loadI", arg(ret_val), NULL, ret_reg, NULL));
      insert_end(&header->code, new_inst(NULL, "storeAI", ret_reg, NULL, "rfp", "12"));
    }
    // Retorno é um identificador.
    else if (return_val != NULL && return_val->symbol_type == VAR)
    {
      int offset = return_val->offset;
      insert_end(&header->code, new_inst(NULL, "loadAI", "rfp", arg(offset), ret_reg, NULL));
      insert_end(&header->code, new_inst(NULL, "storeAI", ret_reg, NULL, "rfp", "16"));
    }
    // Retorno é uma exp arit.
    else
    {
      printf("Codigo do return_node:\n");
      print_code(return_node->code);
      concat_end(&header->code, return_node->code);
      printf("Codigo do header depois de concat cod do return_node:\n");
      print_code(header->code);
    }
    // Retorno é uma exp booleana.
    char* rsp_reg = reg();
    char* rfp_reg = reg();
    printf("antes de inserir inst gen_func_code\n");
    insert_end(&header->code, new_inst(NULL, "loadAI", "rfp", "0", ret_reg, NULL));
    printf("inseriu insttt\n");
    insert_end(&header->code, new_inst(NULL, "loadAI", "rfp", "4", rsp_reg, NULL));
    insert_end(&header->code, new_inst(NULL, "loadAI", "rfp", "8", rfp_reg, NULL));
    insert_end(&header->code, new_inst(NULL, "i2i", rsp_reg, NULL, "rsp", NULL));
    insert_end(&header->code, new_inst(NULL, "i2i", rfp_reg, NULL, "rfp", NULL));
    insert_end(&header->code, new_inst(NULL, "jump", NULL, NULL, ret_reg, NULL));
  }
  else
  {
    
  }
  printf("antes de inserir o halt em gen func code\n");
  // Halt para terminar o programa no caso da funcao ser a main.
  if (is_main)
    insert_end(&header->code, new_inst(NULL, "halt", NULL, NULL, NULL, NULL));

  printf("vai sair de gen_func_code\n");
};

void gen_func_call_code(node* call, prod* args, symbol_entry* func, stack* scope_stack)
{
  call->temp = reg();
  // Calc. end. de retorno (5 instrucoes + 2*(numero de parametros) abaixo).
  char* temp = reg();
  int return_offset = 5;
  int param_num = 0;
  if (args->arg_list != NULL)
  {
    param_num = arg_list_len(args->arg_list);
    return_offset += param_num*2;
  }
  // Salva end. de retorno.
  insert_end(&call->code, new_inst(NULL, "addI", "rpc", arg(return_offset), temp, NULL));
  insert_end(&call->code, new_inst(NULL, "storeAI", temp, NULL, "rsp", "0"));
  // Salva rsp e rfp.
  insert_end(&call->code, new_inst(NULL, "storeAI", "rsp", NULL, "rsp", "4"));
  insert_end(&call->code, new_inst(NULL, "storeAI", "rfp", NULL, "rsp", "8"));
  // Empilha os parametros.
  arg_list* param = args->arg_list;
  int param_offset = 12;
  for (int i = 0; i < param_num; i++)
  {
    symbol_entry* param_sb = st_lookup(param->id, scope_stack);
    int var_offset = param_sb->offset;
    if (param_sb->symbol_type == VAR)
      insert_end(&call->code, new_inst(NULL, "loadAI", "rfp", arg(var_offset), temp, NULL));
    else if (param_sb->symbol_type == LIT)
      insert_end(&call->code, new_inst(NULL, "loadI", param_sb->label, NULL, temp, NULL));
    insert_end(&call->code, new_inst(NULL, "storeAI", temp, NULL, "rsp", arg(param_offset)));
    param_offset += 4;
    param = param->next;
  }
  // Salta para o codigo da funcao.
  insert_end(&call->code, new_inst(NULL, "jumpI", NULL, NULL, func->iloc_func_label, NULL));
  // Carrega o valor de retorno.
  if (param_num == 0)
    insert_end(&call->code, new_inst(NULL, "loadAI", "rsp", "12", call->temp, NULL));
  else
    insert_end(&call->code, new_inst(NULL, "loadAI", "rsp", "16", call->temp, NULL)); 
};