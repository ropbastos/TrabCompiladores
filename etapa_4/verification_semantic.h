

// Função
ht_entry** get_scope(struct StackNode** scope_stack);
ht_entry** add_to_scope(id_list* current, int type, int symbol_type, ht_entry** scope);
symbol_entry* add_to_func_scope(lex_val* current, int type, struct StackNode** scope_stack, ht_entry** scope,  arg_list* args, lex_val* val);
id_list* get_global_id(lex_val* id, int vec_size);
int get_data_type(node* one, node* second, int line);
arg_list* get_args_list(lex_val* id, int type);