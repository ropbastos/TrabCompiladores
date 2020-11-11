#ifndef SEMANTICS_H
#define SEMANTICS_H

#include <stdio.h>
#include <stdlib.h>
#include "errors.h"

void add_variables_to_scope(int type, id_list* ids, symb_table* scope);

id_list* new_id_list(lex_val* id, int vec_size);

void add_functions_to_scope(int type, lex_val* id, arg_list* params, symb_table* scope);

arg_list* new_arg_list(int type, lex_val* id);

void generic_attrib_errors_check(lex_val* id, node* exp, int should_be_vector, stack* scope_stack, int line);

void binary_exp_type_and_error_check(node* binary_operator, node* left_exp, node* right_exp, int line);

void generate_binary_exp_code(node* op, node* left_exp, node* right_exp, inst* inst, char* temp);

void gen_relop_code(node* exp, node* left_exp, node* right_exp);

void gen_logicop_code(node* op, node* left_exp, node* right_exp);

void gen_bool_lit_exp_code(node* exp);

void gen_if_code(node* ifcmd, node* cond, node* true_block, node* false_block);

void gen_while_code(node* while_cmd, node* cond, node* block);

int shift_val_check(lex_val* id, lex_val* shift_amount, stack* scope_stack, int line);


#endif