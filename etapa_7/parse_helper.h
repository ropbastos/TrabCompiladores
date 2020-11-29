#ifndef SEMANTICS_H
#define SEMANTICS_H

#include <stdio.h>
#include <stdlib.h>
#include "errors.h"

typedef struct prod_val {
  struct node* ast_node;
  struct id_list_item* id_list;
  struct arg_list_item* arg_list;
} prod;

void add_variables_to_scope(int type, id_list* ids, symb_table* scope);

id_list* new_id_list(lex_val* id, int vec_size);

void add_functions_to_scope(int type, lex_val* id, arg_list* params, symb_table* scope);

void add_args_to_scope(symb_table* scope, arg_list* args);

arg_list* new_arg_list(int type, lex_val* id);

void generic_attrib_errors_check(lex_val* id, node* exp, int should_be_vector, stack* scope_stack, int line);

void binary_exp_type_and_error_check(node* binary_operator, node* left_exp, node* right_exp, int line);

void gen_ini_code(node* ini, lex_val* dst, lex_val* src_var, node* src_lit, stack* scope_stack);

void gen_attrib_code(node* attrib, node* exp, symbol_entry* dst);

void generate_binary_exp_code(node* op, node* left_exp, node* right_exp, inst* inst, char* temp);

void gen_relop_code(node* exp, node* left_exp, node* right_exp);

void gen_logicop_code(node* op, node* left_exp, node* right_exp);

void gen_bool_lit_exp_code(node* exp);

void gen_if_code(node* ifcmd, node* cond, node* true_block, node* false_block);

void gen_while_code(node* while_cmd, node* cond, node* block);

void gen_for_code(node* for_cmd, node* initialization, node* cond, node* afterthought, node* block);

void gen_func_code(node* header, node* body, int offset, symb_table* scope, stack* scope_stack);

void gen_func_call_code(node* call, prod* args, symbol_entry* func, stack* scope_stack);

void gen_return_code(node* return_node, node* exp, symb_table* scope);

int shift_val_check(lex_val* id, lex_val* shift_amount, stack* scope_stack, int line);

void patch_ini_offsets(hole_list* holes, id_list* ids, int offset);

#endif