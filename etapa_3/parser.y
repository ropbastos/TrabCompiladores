%{
#include <stdio.h>
#include <stdlib.h>
//#include "lexval.h"
#include "ast.h"
int yylex(void);
void yyerror (char const *s);
int get_line_number();
int get_col();
%}

%define parse.error verbose

/* Define union types */
%union {
    struct lex_val* lex_val;
    struct node* node;
    char* label;
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
%type<node> local_list

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

%%

program:
    %empty
|   global_decl program
|   func program
;

global_decl:
    type global_list ';'
|   TK_PR_STATIC type global_list ';'
;

global_list:
    TK_IDENTIFICADOR 
|   TK_IDENTIFICADOR ',' global_list
|   TK_IDENTIFICADOR '[' TK_LIT_INT ']' ',' global_list
|   TK_IDENTIFICADOR '[' TK_LIT_INT ']' 
|   TK_IDENTIFICADOR '[' '+' TK_LIT_INT ']' ',' global_list
|   TK_IDENTIFICADOR '[' '+' TK_LIT_INT ']'
;

type:
    TK_PR_INT
|   TK_PR_FLOAT
|   TK_PR_BOOL
|   TK_PR_CHAR
|   TK_PR_STRING
;

func: 
    header body
;

header:
    type TK_IDENTIFICADOR '(' ')'
|   type TK_IDENTIFICADOR '(' params ')'
|   TK_PR_STATIC type TK_IDENTIFICADOR '(' ')'
|   TK_PR_STATIC type TK_IDENTIFICADOR '(' params ')'
;

params:
    type TK_IDENTIFICADOR ',' params 
|   type TK_IDENTIFICADOR
|   TK_PR_CONST type TK_IDENTIFICADOR ',' params
|   TK_PR_CONST type TK_IDENTIFICADOR  
;

body:
    block 
;

block:
   '{' cmds '}'
;

cmds: 
    %empty                 
|   block ';' cmds
|   local_decl ';' cmds
|   attrib ';' cmds
|   io ';' cmds
|   func_call ';' cmds
|   shift ';' cmds
|   jmp_stmt ';' cmds
|   control ';' cmds
;

local_decl:
    type local_list { printf("Reduziu local_decl\n\n"); print_children($2); }
|   TK_PR_CONST type local_list 
|   TK_PR_STATIC TK_PR_CONST type local_list 
|   TK_PR_STATIC type local_list 
;

local_list:
    TK_IDENTIFICADOR 
        { 
        $$ = create_lv_node($1, 0); 
        }
|   TK_IDENTIFICADOR ',' local_list 
        { 
        $$ = create_lv_node($1, 3, $1); 
        }
|   TK_IDENTIFICADOR TK_OC_LE TK_IDENTIFICADOR 
        { 
        $$ = create_lv_node($2, 2, create_lv_node($3, 0), create_lv_node($1, 0)); 
        } 
|   TK_IDENTIFICADOR TK_OC_LE literal 
        { 
        $$ = create_lv_node($2, 2, create_lv_node($1, 0), $3); 
        }
|   TK_IDENTIFICADOR TK_OC_LE TK_IDENTIFICADOR ',' local_list 
        { 
        $$ = create_lv_node($2, 3, $1); 
        }
|   TK_IDENTIFICADOR TK_OC_LE literal ',' local_list 
    { 
    $$ = create_lv_node($2, 3, $1); 
    }
;

literal:
    TK_LIT_CHAR    { $$ = create_lv_node($1, 0); }
|   TK_LIT_FALSE   { $$ = create_lv_node($1, 0); }
|   TK_LIT_FLOAT   { $$ = create_lv_node($1, 0); }
|   TK_LIT_INT     { $$ = create_lv_node($1, 0); }
|   TK_LIT_STRING  { $$ = create_lv_node($1, 0); }
|   TK_LIT_TRUE    { $$ = create_lv_node($1, 0); }
;

attrib:
    TK_IDENTIFICADOR '=' exp
|   TK_IDENTIFICADOR '[' exp ']' '=' exp
;

io:
    TK_PR_INPUT TK_IDENTIFICADOR 
|   TK_PR_OUTPUT TK_IDENTIFICADOR 
|   TK_PR_OUTPUT literal 
;

func_call:
    TK_IDENTIFICADOR '(' ')'
|   TK_IDENTIFICADOR '(' exp_list ')'
;

exp_list:
    exp
|   exp ',' exp_list
;

shift:
    TK_IDENTIFICADOR TK_OC_SL TK_LIT_INT
|   TK_IDENTIFICADOR TK_OC_SR TK_LIT_INT
|   TK_IDENTIFICADOR TK_OC_SL '+' TK_LIT_INT
|   TK_IDENTIFICADOR TK_OC_SR '+' TK_LIT_INT
|   TK_IDENTIFICADOR '[' exp ']' TK_OC_SL TK_LIT_INT
|   TK_IDENTIFICADOR '[' exp ']' TK_OC_SR TK_LIT_INT
|   TK_IDENTIFICADOR '[' exp ']' TK_OC_SL '+' TK_LIT_INT
|   TK_IDENTIFICADOR '[' exp ']' TK_OC_SR '+' TK_LIT_INT
;

jmp_stmt:
    TK_PR_RETURN exp
|   TK_PR_BREAK
|   TK_PR_CONTINUE
;

control:
    if
|   for
|   while
;

if:
    TK_PR_IF '(' exp ')' block
|   TK_PR_IF '(' exp ')' block TK_PR_ELSE block
;

for:
    TK_PR_FOR '(' attrib ':' exp ':' attrib ')' block 
;

while:
    TK_PR_WHILE '(' exp ')' TK_PR_DO block
;

exp:
    operand
|   exp boperator operand 
|   exp '?' exp ':' exp   %prec TERNARY
;

operand:
    num
|   unary
;

num:
    TK_LIT_FLOAT
|   TK_LIT_INT    
;

unary:
    '+' unary
|   '-' unary
|   '!' unary
|   '&' unary
|   '*' unary
|   '?' unary
|   '#' unary
|   laoperand
;

laoperand:
    TK_IDENTIFICADOR
|   TK_IDENTIFICADOR '[' exp ']'
|   bool
|   func_call
|   '(' exp ')'
;

bool:
    TK_LIT_FALSE
|   TK_LIT_TRUE
;

boperator:
    aoperator
|   loperator
;

aoperator:
    '+' 
|   '-' 
|   '*' 
|   '/' 
|   '%' 
|   '^'
;

loperator:   
    '|'
|   '&'
|   '<'
|   '>'
|   TK_OC_AND
|   TK_OC_EQ
|   TK_OC_GE
|   TK_OC_LE
|   TK_OC_NE
|   TK_OC_OR
;
 
%%

void yyerror(char const *s) {
    fprintf(stderr, "%s on line %d at column %d\n",\
            s, get_line_number(), get_col());
}

