%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse_helper.h"
int yylex(void);
void yyerror (char const *s);
int get_line_number();
int get_col();

extern void* arvore;
stack* scope_stack = NULL;
extern int return_line;
extern int expected_return_type;
extern int return_type_is_correct;

typedef struct prod_val {
  struct node* ast_node;
  struct id_list_item* id_list;
  struct arg_list_item* arg_list;
} prod;
%}

%define parse.error verbose

/* Define union types */
%union {
  struct lex_val* lex_val;
  struct node* node;
  struct id_list_item* id_list;
  struct arg_list_item* arg_list;
  struct prod_val* prod;
  int type;
}

%token TK_PR_INT
%token TK_PR_FLOAT
%token TK_PR_BOOL
%token TK_PR_CHAR
%token TK_PR_STRING
%token TK_PR_IF
%token TK_PR_THEN
%token TK_PR_ELSE
%token TK_PR_WHILE
%token TK_PR_DO
%token TK_PR_INPUT
%token TK_PR_OUTPUT
%token TK_PR_RETURN
%token TK_PR_CONST
%token TK_PR_STATIC
%token TK_PR_FOREACH
%token TK_PR_FOR
%token TK_PR_SWITCH
%token TK_PR_CASE
%token TK_PR_BREAK
%token TK_PR_CONTINUE
%token TK_PR_CLASS
%token TK_PR_PRIVATE
%token TK_PR_PUBLIC
%token TK_PR_PROTECTED
%token TK_PR_END
%token TK_PR_DEFAULT

%token<lex_val> TK_OC_LE
%token<lex_val> TK_OC_GE
%token<lex_val> TK_OC_EQ
%token<lex_val> TK_OC_NE
%token<lex_val> TK_OC_AND
%token<lex_val> TK_OC_OR
%token<lex_val> TK_OC_SL
%token<lex_val> TK_OC_SR
%token<lex_val> TK_OC_FORWARD_PIPE
%token<lex_val> TK_OC_BASH_PIPE
%token<lex_val> TK_LIT_INT
%token<lex_val> TK_LIT_FLOAT
%token<lex_val> TK_LIT_FALSE
%token<lex_val> TK_LIT_TRUE
%token<lex_val> TK_LIT_CHAR
%token<lex_val> TK_LIT_STRING
%token<lex_val> TK_IDENTIFICADOR

%type<node> literal
%type<prod> local_list
%type<node> io
%type<node> cmds
%type<node> local_decl
%type<node> block
%type<node> body
%type<node> header
%type<node> func
%type<node> attrib
%type<node> func_call
%type<node> exp
%type<node> shift
%type<node> jmp_stmt
%type<node> if
%type<node> for
%type<node> while 
%type<node> control 
%type<prod> exp_list
%type<node> lit_exp
%type<node> unary
%type<node> bool
%type<node> program

%type<id_list> global_list
%type<arg_list> params
%type<type> type;

%token TOKEN_ERRO

/* Define precedences */
// Comma
%left ','
// Attribution
%right '='
// Conditional Op
%right '?' ':'
// Logical Op
%left TK_OC_OR
%left TK_OC_AND
// Bitwise Op
%left '|'
%left '&'
// Relational Op
%left TK_OC_EQ TK_OC_NE
%left TK_OC_GE '>'
%left TK_OC_LE '<'
// Bitwise shift
%left TK_OC_SL TK_OC_SR
// Sum and subtraction
%left '+' '-'
// Multiplication, division, modulo, exponentiation
%left '*' '/' '%' '^'

// Ternary Operator
%right TERNARY
// Unary operator expressions
%right UNARY

%%
root: program { arvore = $1; };

program:
    %empty { $$ = NULL; }
|   global_decl program 
    { 
      if ($2 != NULL) $$ = $2; else $$ = NULL; 
    }
|   func program 
    { 
      $$ = $1;
      add_children($$, 1, $2);
    }
;

global_decl:
    type global_list ';' 
    {
      // Find global scope.
      symb_table* global_scope = pop(&scope_stack);
      if (global_scope == NULL)
      {
        // Create new global scope symbol table if one doesn't already exist.
        global_scope = symbol_table(0);
      }

      add_variables_to_scope($1, $2, global_scope);

      // Stack global sb table.
      push(&scope_stack, global_scope);
    }
|   TK_PR_STATIC type global_list ';' 
    {
      // Find global scope.
      symb_table* global_scope = pop(&scope_stack);
      if (global_scope == NULL)
      {
        // Create new global scope symbol table if one doesn't already exist.
        global_scope = symbol_table(0);
      }

      add_variables_to_scope($2, $3, global_scope);

      // Stack global sb table.
      push(&scope_stack, global_scope);
    }
;

global_list:
    TK_IDENTIFICADOR 
    { 
      $$ = new_id_list($1, NOT_A_VECTOR);
    }
|   TK_IDENTIFICADOR '[' TK_LIT_INT ']' 
    { 
      $$ = new_id_list($1, $3->value.i);
    }
|   TK_IDENTIFICADOR '[' '+' TK_LIT_INT ']' 
    { 
      $$ = new_id_list($1, $4->value.i);
    }
|   TK_IDENTIFICADOR ',' global_list 
    { 
      add_id($3, $1, NOT_A_VECTOR, NOT_A_STRING, NOT_INITIALIZED); 
      $$ = $3; 
    }
|   TK_IDENTIFICADOR '[' TK_LIT_INT ']' ',' global_list 
    { 
      add_id($6, $1, $3->value.i, NOT_A_STRING, NOT_INITIALIZED); 
      $$ = $6; 
    }
|   TK_IDENTIFICADOR '[' '+' TK_LIT_INT ']' ',' global_list 
    { 
      add_id($7, $1, $4->value.i, NOT_A_STRING, NOT_INITIALIZED); 
      $$ = $7; 
    }
;

type:
    TK_PR_INT { $$ = INT; } 
|   TK_PR_FLOAT { $$ = FLOAT; }
|   TK_PR_BOOL { $$ = BOOL; }
|   TK_PR_CHAR { $$ = CHAR; }
|   TK_PR_STRING { $$ = STR; }
;

func:
    header body 
    {
      expected_return_type = $1->data_type;
      check_return_type($2);
      if (!return_type_is_correct)
      {
        syntactic_error(ERR_WRONG_PAR_RETURN, $1->label, return_line, NULL);
      } 
      $$ = $1; if ($2 != NULL) add_children($$, 1, $2); 
    }
;

header:
    type TK_IDENTIFICADOR '(' ')' 
    { 
      symb_table* scope = pop(&scope_stack);
      if (scope == NULL)
        scope = symbol_table(0);

      add_functions_to_scope($1, $2, NULL, scope);

      // Re-stack scope.
      push(&scope_stack, scope);

      $$ = lexval_node($2); $$->data_type = $1;
    }
|   type TK_IDENTIFICADOR '(' params ')' 
    { 
      symb_table* scope = pop(&scope_stack);
      if (scope == NULL)
        scope = symbol_table(0);

      add_functions_to_scope($1, $2, $4, scope);

      // Re-stack scope.
      push(&scope_stack, scope);

      $$ = lexval_node($2); $$->data_type = $1; 
    }
|   TK_PR_STATIC type TK_IDENTIFICADOR '(' ')' 
    { 
      symb_table* scope = pop(&scope_stack);
      if (scope == NULL)
        scope = symbol_table(0);

      add_functions_to_scope($2, $3, NULL, scope);

      // Re-stack scope.
      push(&scope_stack, scope);

      $$ = lexval_node($3);  $$->data_type = $2; 
    }
|   TK_PR_STATIC type TK_IDENTIFICADOR '(' params ')' 
    { 
      symb_table* scope = pop(&scope_stack);
      if (scope == NULL)
        scope = symbol_table(0);

      add_functions_to_scope($2, $3, $5, scope);

      // Re-stack scope.
      push(&scope_stack, scope);

      $$ = lexval_node($3);  $$->data_type = $2; 
    }
;

params:
    type TK_IDENTIFICADOR ',' params
    {
      add_arg($4, $2, $1);
      $$ = $4;
    }
|   type TK_IDENTIFICADOR
    {
      $$ = new_arg_list($1, $2);
    }
|   TK_PR_CONST type TK_IDENTIFICADOR ',' params
    {
      add_arg($5, $3, $2);
      $$ = $5;
    }
|   TK_PR_CONST type TK_IDENTIFICADOR 
    {
      $$ = new_arg_list($2, $3);
    }
;

body:
    block { $$ = $1; }
;

block_start: '{' { push(&scope_stack, symbol_table(0)); }
block_end: '}' { pop(&scope_stack); }

block:
  block_start cmds block_end 
  { 
    $$ = $2; 
  }
;

cmds:
    %empty    { $$ = NULL; }
|   block ';' cmds
    {
      if ($1 != NULL) {$$ = $1; add_children($$, 1, $3);} else {$$ = $3;};
    }
|   local_decl ';' cmds 
    {
      if ($1 != NULL) {$$ = $1; add_children($$, 1, $3);} else {$$ = $3;};
    }
|   attrib ';' cmds
    {
      if ($1 != NULL) {$$ = $1; add_children($$, 1, $3);} else {$$ = $3;};
    }
|   io ';' cmds
    {
      if ($1 != NULL) {$$ = $1; add_children($$, 1, $3);} else {$$ = $3;};
    }
|   func_call ';' cmds
    {
      if ($1 != NULL) {$$ = $1; add_children($$, 1, $3);} else {$$ = $3;};
    }
|   shift ';' cmds
    {
      if ($1 != NULL) {$$ = $1; add_children($$, 1, $3);} else {$$ = $3;};
    }
|   jmp_stmt ';' cmds
    {
      if ($1 != NULL) {$$ = $1; add_children($$, 1, $3);} else {$$ = $3;};
    }
|   control ';' cmds
    {
      if ($1 != NULL) {$$ = $1; add_children($$, 1, $3);} else {$$ = $3;};
    }
;

local_decl:
    type local_list 
    { 
      // Get scope
      symb_table* local_scope = pop(&scope_stack);

      if (local_scope == NULL)
      {
        printf("ERROR local scope is NULL\n");
        printf("id on top of id_list: %s\n", $2->id_list->id);
      }

      // Add locals to symbol table.
      add_variables_to_scope($1, $2->id_list, local_scope);
      push(&scope_stack, local_scope);

      $$ = $2->ast_node;
    }
|   TK_PR_CONST type local_list 
    { 
      // Get scope
      symb_table* local_scope = pop(&scope_stack);

      if (local_scope == NULL)
      {
        printf("ERROR local scope is NULL\n");
        printf("id on top of id_list: %s\n", $3->id_list->id);
      }

      // Add locals to symbol table.
      add_variables_to_scope($2, $3->id_list, local_scope);
      push(&scope_stack, local_scope);

      $$ = $3->ast_node; 
    }
|   TK_PR_STATIC TK_PR_CONST type local_list 
    { 
      // Get scope
      symb_table* local_scope = pop(&scope_stack);

      if (local_scope == NULL)
      {
        printf("ERROR local scope is NULL\n");
        printf("id on top of id_list: %s\n", $4->id_list->id);
      }

      // Add locals to symbol table.
      add_variables_to_scope($3, $4->id_list, local_scope);
      push(&scope_stack, local_scope);

      $$ = $4->ast_node; 
    }
|   TK_PR_STATIC type local_list 
    { 
      // Get scope
      symb_table* local_scope = pop(&scope_stack);

      if (local_scope == NULL)
      {
        printf("ERROR local scope is NULL\n");
        printf("id on top of id_list: %s\n", $3->id_list->id);
      }

      // Add locals to symbol table.
      add_variables_to_scope($2, $3->id_list, local_scope);
      push(&scope_stack, local_scope);

      $$ = $3->ast_node; 
    }
;

local_list:
    TK_IDENTIFICADOR
    {
      $$->id_list = new_id_list($1, NOT_A_VECTOR);

      $$->ast_node = NULL;
    }
|   TK_IDENTIFICADOR ',' local_list
    {
      add_id($3->id_list, $1, NOT_A_VECTOR, NOT_A_STRING, NOT_INITIALIZED); 
      $$->id_list = $3->id_list; 

      if ($3->ast_node != NULL ) { $$->ast_node = $3->ast_node; } else { $$->ast_node = NULL; };
    }
|   TK_IDENTIFICADOR TK_OC_LE TK_IDENTIFICADOR
    {
      symbol_entry* lookup_res = st_lookup($3->value.s, scope_stack);
      if (lookup_res == NULL)
        syntactic_error(ERR_UNDECLARED, $3->value.s, get_line_number(), NULL);
      if (lookup_res->symbol_type == VEC)
        syntactic_error(ERR_VECTOR, $3->value.s, get_line_number(), NULL);

      id_list* local_ids = malloc(sizeof(struct id_list_item));
      local_ids->id = $1->value.s;
      local_ids->line = $1->line;
      local_ids->vec_size = NOT_A_VECTOR;
      local_ids->ini_type = lookup_res->data_type;
      if (lookup_res->data_type == STR) local_ids->str_size = lookup_res->size;
      else local_ids->str_size = NOT_A_STRING;
      local_ids->next = NULL;
      $$->id_list = local_ids;

      $$->ast_node = lexval_node($2); add_children($$->ast_node, 2, lexval_node($1), lexval_node($3));
      $$->ast_node->children[0]->data_type = lookup_res->data_type;
    }
|   TK_IDENTIFICADOR TK_OC_LE literal
    {
      id_list* local_ids = malloc(sizeof(struct id_list_item));
      local_ids->id = $1->value.s;
      local_ids->line = $1->line;
      local_ids->vec_size = NOT_A_VECTOR;
      local_ids->ini_type = $3->data_type;
      if ($3->data_type == STR)
      {
        local_ids->str_size = strlen($3->label);
      }
      else local_ids->str_size = NOT_A_STRING;
      local_ids->next = NULL;
      $$->id_list = local_ids;

      $$->ast_node = lexval_node($2); add_children($$->ast_node, 2, lexval_node($1), $3);
      $$->ast_node->children[0]->data_type = $3->data_type;
    }
|   TK_IDENTIFICADOR TK_OC_LE TK_IDENTIFICADOR ',' local_list
    {
      symbol_entry* lookup_res = st_lookup($3->value.s, scope_stack);
      if (lookup_res == NULL)
        syntactic_error(ERR_UNDECLARED, $3->value.s, get_line_number(), NULL);

      if (lookup_res->data_type != STR)
        add_id($5->id_list, $1, NOT_A_VECTOR, NOT_A_STRING, lookup_res->data_type); 
      else
        add_id($5->id_list, $1, NOT_A_VECTOR, lookup_res->size, lookup_res->data_type);

      $$->id_list = $5->id_list; 

      $$->ast_node = lexval_node($2); add_children($$->ast_node, 3, lexval_node($1), lexval_node($3), $5->ast_node);
      $$->ast_node->children[0]->data_type = lookup_res->data_type;
    }
|   TK_IDENTIFICADOR TK_OC_LE literal ',' local_list
    {
      if ($3->data_type == STR)
      {
        add_id($5->id_list, $1, NOT_A_VECTOR, strlen($3->label), $3->data_type); 
      }
      else
        add_id($5->id_list, $1, NOT_A_VECTOR, NOT_A_STRING, $3->data_type);

      $$->id_list = $5->id_list; 

      $$->ast_node = lexval_node($2); add_children($$->ast_node, 3, lexval_node($1), $3, $5->ast_node);
      $$->ast_node->children[0]->data_type = $3->data_type;
    }
;

literal:
    TK_LIT_CHAR    
    { 
      $$ = lexval_node($1); 
      symbol_entry* new_lit = new_symbol_entry($$->label, get_line_number(), LIT, CHAR,
                                              1, NULL, $1, 0);
      symb_table* scope = pop(&scope_stack);
      ht_insert(new_lit, scope);
      push(&scope_stack, scope);
    }
|   TK_LIT_FALSE    
    { 
      $$ = lexval_node($1); 
      symbol_entry* new_lit = new_symbol_entry($$->label, get_line_number(), LIT, BOOL,
                                              1, NULL, $1, 0);
      symb_table* scope = pop(&scope_stack);
      ht_insert(new_lit, scope);
      push(&scope_stack, scope);
    }
|   TK_LIT_FLOAT    
    { 
      $$ = lexval_node($1); 
      symbol_entry* new_lit = new_symbol_entry($$->label, get_line_number(), LIT, FLOAT,
                                              8, NULL, $1, 0);
      symb_table* scope = pop(&scope_stack);
      ht_insert(new_lit, scope);
      push(&scope_stack, scope);
    }
|   TK_LIT_INT    
    { 
      $$ = lexval_node($1); 
      symbol_entry* new_lit = new_symbol_entry($$->label, get_line_number(), LIT, INT,
                                              4, NULL, $1, 0);
      symb_table* scope = pop(&scope_stack);
      ht_insert(new_lit, scope);
      push(&scope_stack, scope);
    }
|   TK_LIT_STRING    
    { 
      $$ = lexval_node($1); 
      symbol_entry* new_lit = new_symbol_entry($$->label, get_line_number(), LIT, STR,
                                              strlen($$->label), NULL, $1, 0);
      symb_table* scope = pop(&scope_stack);
      ht_insert(new_lit, scope);
      push(&scope_stack, scope);
    }
|   TK_LIT_TRUE    
    { 
      $$ = lexval_node($1); 
      symbol_entry* new_lit = new_symbol_entry($$->label, get_line_number(), LIT, BOOL,
                                              1, NULL, $1, 0);
      symb_table* scope = pop(&scope_stack);
      ht_insert(new_lit, scope);
      push(&scope_stack, scope);
    }
;

attrib:
    TK_IDENTIFICADOR '=' exp 
    { 
      symbol_entry* dst_lookup = st_lookup($1->value.s, scope_stack);
      generic_attrib_errors_check($1, $3, 0, scope_stack, get_line_number());

      $$ = named_node("="); add_children($$, 2, lexval_node($1), $3); 
      $$->children[0]->data_type = dst_lookup->data_type;
    }
|   TK_IDENTIFICADOR '[' exp ']' '=' exp
    { 
      symbol_entry* dst_lookup = st_lookup($1->value.s, scope_stack);
      
      generic_attrib_errors_check($1, $6, 1, scope_stack, get_line_number());

      node* vector = named_node("[]");
      add_children(vector, 2, lexval_node($1), $3);
      vector->children[0]->data_type = dst_lookup->data_type;
      $$ = named_node("="); add_children($$, 2, vector, $6); 
    }
;

io:
    TK_PR_INPUT TK_IDENTIFICADOR
    {
      symbol_entry* lookup_res = st_lookup($2->value.s, scope_stack);
      if (lookup_res == NULL)
      {
       syntactic_error(ERR_UNDECLARED, $2->value.s, get_line_number(), NULL);
      }
      if (lookup_res->data_type != INT && lookup_res->data_type != FLOAT)
      {
        syntactic_error(ERR_WRONG_PAR_INPUT, NULL, get_line_number(), NULL);
      }
      $$ = named_node("input"); add_children($$, 1, lexval_node($2));
      $$->children[0]->data_type = lookup_res->data_type;
    }
|   TK_PR_OUTPUT TK_IDENTIFICADOR
    {
      symbol_entry* lookup_res = st_lookup($2->value.s, scope_stack);
      if (lookup_res == NULL)
      {
       syntactic_error(ERR_UNDECLARED, $2->value.s, get_line_number(), NULL);
      }
      if (lookup_res->data_type != INT && lookup_res->data_type != FLOAT)
      {
        syntactic_error(ERR_WRONG_PAR_OUTPUT, NULL, get_line_number(), NULL);
      }

      $$ = named_node("output"); add_children($$, 1, lexval_node($2));
    }
|   TK_PR_OUTPUT literal
    {
      symbol_entry* lookup_res = st_lookup($2->label, scope_stack);
      if (lookup_res == NULL)
      {
       syntactic_error(ERR_UNDECLARED, $2->label, get_line_number(), NULL);
      }
      if (lookup_res->data_type != INT && lookup_res->data_type != FLOAT)
      {
        syntactic_error(ERR_WRONG_PAR_OUTPUT, NULL, get_line_number(), NULL);
      }

      $$ = named_node("output"); add_children($$, 1, $2);
    }
;

func_call:
    TK_IDENTIFICADOR '(' exp_list ')' 
    { 
      // Check if function is declared.
      symbol_entry* lookup_res = st_lookup($1->value.s, scope_stack);

      if (lookup_res == NULL)
      {
        syntactic_error(ERR_UNDECLARED, $1->value.s, get_line_number(), NULL);
      }

      // Check if symbol is a function.
      if (lookup_res->symbol_type != FUNC)
      {
        if (lookup_res->symbol_type == VAR)
          syntactic_error(ERR_VARIABLE, $1->value.s, get_line_number(), NULL);
        if (lookup_res->symbol_type == VEC)
          syntactic_error(ERR_VECTOR, $1->value.s, get_line_number(), NULL);
      }

      // Check arguments.
      if (arg_list_len($3->arg_list) < arg_list_len(lookup_res->args))
      {
        syntactic_error(ERR_MISSING_ARGS, $1->value.s, get_line_number(), NULL);
      }
      else if (arg_list_len($3->arg_list) > arg_list_len(lookup_res->args))
      {
        syntactic_error(ERR_EXCESS_ARGS, $1->value.s, get_line_number(), NULL);
      }

      if (arg_list_len($3->arg_list) != 0)
      {
        arg_list* table_entry_arg = lookup_res->args;
        arg_list* call_arg = $3->arg_list;
        do
        {
          if (table_entry_arg->type == CHAR && call_arg->type != CHAR || table_entry_arg->type == STR && call_arg->type != STR
              || table_entry_arg->type != CHAR && call_arg->type == CHAR || table_entry_arg->type != STR && call_arg->type == STR)
          {
            syntactic_error(ERR_WRONG_TYPE_ARGS, $1->value.s, get_line_number(), NULL);
          }
          table_entry_arg = table_entry_arg->next;
          call_arg = call_arg->next;
        } while (table_entry_arg != NULL && call_arg != NULL);
      }

      
      $$ = lexval_node($1); add_children($$, 1, $3->ast_node);
      $$->data_type = lookup_res->data_type;
    }
;

exp_list:
    exp 
    { 
      arg_list* exp_list = malloc(sizeof(struct arg_list_item));

      if ($1->val != NULL)
      {
        exp_list->id = $1->val->value.s;
        exp_list->line = $1->val->line;
        exp_list->type = $1->data_type;
        exp_list->next = NULL;
      }
      else if (strcmp($1->label, "[]") == 0)
      {
        exp_list->id = $1->children[0]->val->value.s;
        exp_list->line = get_line_number();
        exp_list->type = $1->data_type;
        exp_list->next = NULL;
      }
      else
      {
        exp_list->id = $1->label;
        exp_list->line = get_line_number();
        exp_list->type = $1->data_type;
        exp_list->next = NULL;
      }

      struct prod_val* head = (struct prod_val*) malloc(sizeof(struct prod_val));
      head->ast_node = (struct node*) malloc(sizeof(struct node));
      head->arg_list = (struct arg_list_item*) malloc(sizeof(struct arg_list_item));
      head->id_list = NULL;

      memcpy(head->ast_node, $1, sizeof(struct node));
      head->arg_list = exp_list;
      $$ = head;
    }
|   exp ',' exp_list 
    { 
      arg_list* exp_list_item = malloc(sizeof(struct arg_list_item));

      if ($1->val != NULL)
      {
        exp_list_item->id = $1->val->value.s;
        exp_list_item->line = $1->val->line;
        exp_list_item->type = $1->data_type;
        exp_list_item->next = NULL;
      }
      else if (strcmp($1->label, "[]") == 0)
      {
        exp_list_item->id = $1->children[0]->val->value.s;
        exp_list_item->line = get_line_number();
        exp_list_item->type = $1->data_type;
        exp_list_item->next = NULL;
      }
      else
      {
        exp_list_item->id = $1->label;
        exp_list_item->line = get_line_number();
        exp_list_item->type = $1->data_type;
        exp_list_item->next = NULL;
      }

      add_arg_call($3->arg_list, exp_list_item);

      struct prod_val* head = (struct prod_val*) malloc(sizeof(struct prod_val));
      head->ast_node = (struct node*) malloc(sizeof(struct node));
      head->arg_list = (struct arg_list_item*) malloc(sizeof(struct arg_list_item));
      head->id_list = NULL;

      memcpy(head->ast_node, $1, sizeof(struct node));
      head->arg_list = $3->arg_list;
      $$ = head;

      add_children($$->ast_node, 1, $3->ast_node);
    }
|   %empty 
    { 
      struct prod_val* head = (struct prod_val*) malloc(sizeof(struct prod_val));
      head->ast_node = (struct node*) malloc(sizeof(struct node));
      head->arg_list = (struct arg_list_item*) malloc(sizeof(struct arg_list_item));
      head->id_list = NULL;
      head->arg_list = NULL;
      head->ast_node = NULL;
      $$ = head; 
    }
;

shift:
    TK_IDENTIFICADOR TK_OC_SL TK_LIT_INT
    {
      int type = shift_val_check($1, $3, scope_stack, get_line_number());

      $$ = lexval_node($2); 
      add_children($$, 2, lexval_node($1), lexval_node($3));
      $$->children[0]->data_type = type;
    }
|   TK_IDENTIFICADOR TK_OC_SR TK_LIT_INT
    {
      int type = shift_val_check($1, $3, scope_stack, get_line_number());

      $$ = lexval_node($2); 
      add_children($$, 2, lexval_node($1), lexval_node($3));
      $$->children[0]->data_type = type;
    }
|   TK_IDENTIFICADOR TK_OC_SL '+' TK_LIT_INT
    {
      int type = shift_val_check($1, $4, scope_stack, get_line_number());

      $$ = lexval_node($2); 
      add_children($$, 2, lexval_node($1), lexval_node($4));
      $$->children[0]->data_type = type;
    }
|   TK_IDENTIFICADOR TK_OC_SR '+' TK_LIT_INT
    {
      int type = shift_val_check($1, $4, scope_stack, get_line_number());

      $$ = lexval_node($2); 
      add_children($$, 2, lexval_node($1), lexval_node($4));
      $$->children[0]->data_type = type;
    }
|   TK_IDENTIFICADOR '[' exp ']' TK_OC_SL TK_LIT_INT
    {
      int type = shift_val_check($1, $6, scope_stack, get_line_number());

      node* vector = named_node("[]");
      add_children(vector, 2, lexval_node($1), $3); vector->children[0]->data_type = type;
      $$ = lexval_node($5); add_children($$, 2, vector, lexval_node($6));
    }
|   TK_IDENTIFICADOR '[' exp ']' TK_OC_SR TK_LIT_INT
    {
      int type = shift_val_check($1, $6, scope_stack, get_line_number());

      node* vector = named_node("[]");
      add_children(vector, 2, lexval_node($1), $3); vector->children[0]->data_type = type;
      $$ = lexval_node($5); add_children($$, 2, vector, lexval_node($6));
    }
|   TK_IDENTIFICADOR '[' exp ']' TK_OC_SL '+' TK_LIT_INT
    {
      int type = shift_val_check($1, $7, scope_stack, get_line_number());

      node* vector = named_node("[]");
      add_children(vector, 2, lexval_node($1), $3); vector->children[0]->data_type = type;
      $$ = lexval_node($5); add_children($$, 2, vector, lexval_node($7));
    }
|   TK_IDENTIFICADOR '[' exp ']' TK_OC_SR '+' TK_LIT_INT
    {
      int type = shift_val_check($1, $7, scope_stack, get_line_number());

      node* vector = named_node("[]");
      add_children(vector, 2, lexval_node($1), $3); vector->children[0]->data_type = type;
      $$ = lexval_node($5); add_children($$, 2, vector, lexval_node($7));
    }
;

jmp_stmt:
    TK_PR_RETURN exp 
    {      
      $$ = named_node("return"); add_children($$, 1, $2); 
      $$->data_type = $2->data_type;
      $$->is_return = 1;
      $$->return_line = get_line_number();
    }
|   TK_PR_BREAK { $$ = named_node("break"); }
|   TK_PR_CONTINUE { $$ = named_node("continue"); }
;

control:
    if  { $$ = $1; }
|   for { $$ = $1; }
|   while { $$ = $1; }
;

if:
    TK_PR_IF '(' exp ')' block 
    {  
        $$ = named_node("if");
        add_children($$, 3, $3, $5, NULL);
    }
|   TK_PR_IF '(' exp ')' block TK_PR_ELSE block
    {  
        $$ = named_node("if");
        add_children($$, 3, $3, $5, $7);
    }
;

for:
    TK_PR_FOR '(' attrib ':' exp ':' attrib ')' block
    {  
        $$ = named_node("for");
        add_children($$, 4, $3, $5, $7, $9);
    }
;

while:
    TK_PR_WHILE '(' exp ')' TK_PR_DO block
    {  
        $$ = named_node("while");
        add_children($$, 2, $3, $6);
    }
;

exp:
    TK_IDENTIFICADOR 
    { 
      symbol_entry* lookup_result = st_lookup($1->value.s, scope_stack);
      if(lookup_result == NULL)
      {
        syntactic_error(ERR_UNDECLARED, $1->value.s, get_line_number(), NULL);
      }
      else if (lookup_result->symbol_type != VAR)
      {
        if (lookup_result->symbol_type == VEC)
          syntactic_error(ERR_VECTOR, $1->value.s, get_line_number(), NULL);
        if (lookup_result->symbol_type == FUNC)
          syntactic_error(ERR_FUNCTION, $1->value.s, get_line_number(), NULL);
      }

      $$ = lexval_node($1); $$->data_type = lookup_result->data_type;
      $$->size = lookup_result->size;
    }
|   TK_IDENTIFICADOR '[' exp ']'
    {
      symbol_entry* lookup_result = st_lookup($1->value.s, scope_stack);
      if(lookup_result == NULL)
      {
        syntactic_error(ERR_UNDECLARED, $1->value.s, get_line_number(), NULL);
      }
      else if (lookup_result->symbol_type != VEC)
      {
        if (lookup_result->symbol_type == VAR)
          syntactic_error(ERR_VARIABLE, $1->value.s, get_line_number(), NULL);
        if (lookup_result->symbol_type == FUNC)
          syntactic_error(ERR_FUNCTION, $1->value.s, get_line_number(), NULL);
      }

      if ($3->data_type == CHAR)
      {
        syntactic_error(ERR_CHAR_TO_X, $3->label, get_line_number(), NULL);
      }
      if ($3->data_type == STR)
      {
        syntactic_error(ERR_STRING_TO_X, $3->label, get_line_number(), NULL);
      }

      $$ = named_node("[]"); $$->data_type = lookup_result->data_type;
      add_children($$, 2, lexval_node($1), $3);
    }
|   lit_exp { $$ = $1; }
|   bool { $$ = $1; }
|   func_call 
    { 
      $$ = $1; 
    }
|   '(' exp ')' { $$ = $2; }
|   unary exp %prec UNARY { $$ = $1; add_children($$, 1, $2); $$->data_type = $2->data_type;}
|   exp '+' exp 
    { 
      $$ = named_node("+"); add_children($$, 2, $1, $3);
      binary_exp_type_and_error_check($$, $1, $3, get_line_number());
    }
|   exp '-' exp 
    { 
      $$ = named_node("+"); add_children($$, 2, $1, $3);
      binary_exp_type_and_error_check($$, $1, $3, get_line_number());
    }
|   exp '*' exp 
    { 
      $$ = named_node("+"); add_children($$, 2, $1, $3);
      binary_exp_type_and_error_check($$, $1, $3, get_line_number());
    }
|   exp '/' exp 
    { 
      $$ = named_node("+"); add_children($$, 2, $1, $3);
      binary_exp_type_and_error_check($$, $1, $3, get_line_number());
    }
|   exp '%' exp 
    { 
      $$ = named_node("+"); add_children($$, 2, $1, $3);
      binary_exp_type_and_error_check($$, $1, $3, get_line_number());
    }
|   exp '^' exp 
    { 
      $$ = named_node("+"); add_children($$, 2, $1, $3);
      binary_exp_type_and_error_check($$, $1, $3, get_line_number());
    }
|   exp '|' exp 
    { 
      $$ = named_node("+"); add_children($$, 2, $1, $3);
      binary_exp_type_and_error_check($$, $1, $3, get_line_number());
    }
|   exp '&' exp 
    { 
      $$ = named_node("+"); add_children($$, 2, $1, $3);
      binary_exp_type_and_error_check($$, $1, $3, get_line_number());
    }
|   exp '<' exp 
    { 
      $$ = named_node("<"); add_children($$, 2, $1, $3); 
      binary_exp_type_and_error_check($$, $1, $3, get_line_number());
      $$->data_type = BOOL;
    }
|   exp '>' exp 
    { 
      $$ = named_node(">"); add_children($$, 2, $1, $3);
      binary_exp_type_and_error_check($$, $1, $3, get_line_number());
      $$->data_type = BOOL; 
    }
|   exp TK_OC_AND exp 
    { 
      $$ = lexval_node($2); add_children($$, 2, $1, $3);
      binary_exp_type_and_error_check($$, $1, $3, get_line_number());
      $$->data_type = BOOL;
    }
|   exp TK_OC_EQ exp 
    { 
      $$ = lexval_node($2); add_children($$, 2, $1, $3);
      binary_exp_type_and_error_check($$, $1, $3, get_line_number());
      $$->data_type = BOOL;
    }
|   exp TK_OC_GE exp 
    { 
      $$ = lexval_node($2); add_children($$, 2, $1, $3);
      binary_exp_type_and_error_check($$, $1, $3, get_line_number());
      $$->data_type = BOOL;
    }
|   exp TK_OC_LE exp 
    { 
      $$ = lexval_node($2); add_children($$, 2, $1, $3);
      binary_exp_type_and_error_check($$, $1, $3, get_line_number());
      $$->data_type = BOOL;
    }
|   exp TK_OC_NE exp 
    { 
      $$ = lexval_node($2); add_children($$, 2, $1, $3);
      binary_exp_type_and_error_check($$, $1, $3, get_line_number());
      $$->data_type = BOOL;
    }
|   exp TK_OC_OR exp 
    { 
      $$ = lexval_node($2); add_children($$, 2, $1, $3);
      binary_exp_type_and_error_check($$, $1, $3, get_line_number());
      $$->data_type = BOOL;
    }
|   exp '?' exp ':' exp %prec TERNARY 
    { 
      $$ = named_node("?:");
      add_children($$, 3, $1, $3, $5);
      if ($1->data_type != BOOL && $1->data_type != INT
          && $1->data_type != FLOAT)
        syntactic_error(ERR_WRONG_TYPE, NULL, get_line_number(), NULL);
    }
;

lit_exp:
    TK_LIT_FLOAT 
    { 
      char float_to_str[7];
      gcvt($1->value.f, 4, float_to_str);
      // Check if literal already on table.
      //printf("Antes de chamar st_lookup em num.\n");
      symbol_entry* sb = st_lookup(float_to_str, scope_stack);
      if (sb == NULL)
      {
        // If not, put it.
        sb = new_symbol_entry(float_to_str, get_line_number(), LIT, FLOAT, 8, NULL, $1, 0);
        symb_table* scope = pop(&scope_stack);
        if (scope == NULL) printf("Scope is null on num.\n");
        ht_insert(sb, scope);
        push(&scope_stack, scope);
      }
      $$ = lexval_node($1); $$->data_type = FLOAT; 
    }
|   TK_LIT_INT 
    { 
      int len = snprintf(NULL, 0, "%d", $1->value.i) + 1; 
      char* int_to_str = malloc(len);
      snprintf(int_to_str, len, "%d", $1->value.i);
      // Check if literal already on table.
      symbol_entry* sb = st_lookup(int_to_str, scope_stack);
      if (sb == NULL)
      {
        // If not, put it.
        sb = new_symbol_entry(int_to_str, get_line_number(), LIT, INT, 4, NULL, $1, 0);
        symb_table* scope = pop(&scope_stack);
        if (scope == NULL) printf("Scope is null on num.\n");
        ht_insert(sb, scope);
        push(&scope_stack, scope);
      }
      
      $$ = lexval_node($1); $$->data_type = INT;
    }
| TK_LIT_CHAR
  {
    $$ = lexval_node($1); $$->data_type = CHAR;
    symbol_entry* sb = st_lookup($$->label, scope_stack);
    if (sb == NULL)
    {
      sb = new_symbol_entry($$->label, get_line_number(), LIT, CHAR, 1, NULL, $1, 0);
      symb_table* scope = pop(&scope_stack);
      if (scope == NULL) printf("Scope is null on num.\n");
      ht_insert(sb, scope);
      push(&scope_stack, scope);
    }
  }
| TK_LIT_STRING
  {
    $$ = lexval_node($1); $$->data_type = STR; $$->size = strlen($$->label);

    symbol_entry* sb = st_lookup($$->label, scope_stack);
    if (sb == NULL)
    {
      sb = new_symbol_entry($$->label, get_line_number(), LIT, STR, strlen($$->label), NULL, $1, 0);
      symb_table* scope = pop(&scope_stack);
      if (scope == NULL) printf("Scope is null on num.\n");
      ht_insert(sb, scope);
      push(&scope_stack, scope);
    }

  }
;

unary:
    '+' { $$ = named_node("+"); }
|   '-' { $$ = named_node("-"); }
|   '!' { $$ = named_node("!"); }
|   '&' { $$ = named_node("&"); }
|   '*' { $$ = named_node("*"); }
|   '?' { $$ = named_node("?"); }
|   '#' { $$ = named_node("#"); }
;

bool:
    TK_LIT_FALSE { $$ = lexval_node($1); }
|   TK_LIT_TRUE { $$ = lexval_node($1); }
;

%%

void yyerror(char const *s) {
    fprintf(stderr, "%s on line %d at column %d\n",\
            s, get_line_number(), get_col());
}

