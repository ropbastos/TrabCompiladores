#ifndef SEMANTICS_H
#define SEMANTICS_H

#include <stdio.h>
#include <stdlib.h>
#include "errors.h"

void add_variables_to_scope(int type, id_list* ids, ht_entry** scope);

id_list* new_id_list(lex_val* id, int vec_size);

void add_functions_to_scope(int type, lex_val* id, arg_list* params, ht_entry** scope);

arg_list* new_arg_list(int type, lex_val* id);

void generic_attrib_errors_check(lex_val* id, node* exp, int should_be_vector, stack* scope_stack, int line);


#endif