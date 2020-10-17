%{
#include <stdio.h>
#include <stdlib.h>
//#include "lexval.h"
#include "ast.h"
int yylex(void);
void yyerror (char const *s);
int get_line_number();
int get_col();

extern void* arvore;
%}

%define parse.error verbose

/* Define union types */
%union {
    struct lex_val* lex_val;
    struct node* node;
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
%type<node> exp_list
%type<node> num
%type<node> unary
%type<node> bool
%type<node> program

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
|   global_decl program { if ($2 != NULL) $$ = $2; else $$ = NULL; }
|   func program 
    { 
      $$ = $1;
      add_children($$, 1, $2);
    }
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
    header body { $$ = $1; if ($2 != NULL) add_children($$, 1, $2); }
;

header:
    type TK_IDENTIFICADOR '(' ')' { $$ = lexval_node($2); }
|   type TK_IDENTIFICADOR '(' params ')' { $$ = lexval_node($2); }
|   TK_PR_STATIC type TK_IDENTIFICADOR '(' ')' { $$ = lexval_node($3); }
|   TK_PR_STATIC type TK_IDENTIFICADOR '(' params ')' { $$ = lexval_node($3); }
;

params:
    type TK_IDENTIFICADOR ',' params
|   type TK_IDENTIFICADOR
|   TK_PR_CONST type TK_IDENTIFICADOR ',' params
|   TK_PR_CONST type TK_IDENTIFICADOR
;

body:
    block { $$ = $1; }
;

block:
   '{' cmds '}' { $$ = $2; }
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
    type local_list { $$ = $2; }
|   TK_PR_CONST type local_list { $$ = $3; }
|   TK_PR_STATIC TK_PR_CONST type local_list { $$ = $4; }
|   TK_PR_STATIC type local_list { $$ = $3; }
;

local_list:
    TK_IDENTIFICADOR
    {
        $$ = NULL;
    }
|   TK_IDENTIFICADOR ',' local_list
    {
        if ($3 != NULL ) { $$ = $3; } else { $$ = NULL; };
    }
|   TK_IDENTIFICADOR TK_OC_LE TK_IDENTIFICADOR
    {
        $$ = lexval_node($2); add_children($$, 2, lexval_node($1), lexval_node($3));
    }
|   TK_IDENTIFICADOR TK_OC_LE literal
    {
        $$ = lexval_node($2); add_children($$, 2, lexval_node($1), $3);
    }
|   TK_IDENTIFICADOR TK_OC_LE TK_IDENTIFICADOR ',' local_list
    {
        $$ = lexval_node($2); add_children($$, 3, lexval_node($1), lexval_node($3), $5);
    }
|   TK_IDENTIFICADOR TK_OC_LE literal ',' local_list
    {
        $$ = lexval_node($2); add_children($$, 3, lexval_node($1), $3, $5);
    }
;

literal:
    TK_LIT_CHAR    { $$ = lexval_node($1); }
|   TK_LIT_FALSE   { $$ = lexval_node($1); }
|   TK_LIT_FLOAT   { $$ = lexval_node($1); }
|   TK_LIT_INT     { $$ = lexval_node($1); }
|   TK_LIT_STRING  { $$ = lexval_node($1); }
|   TK_LIT_TRUE    { $$ = lexval_node($1); }
;

attrib:
    TK_IDENTIFICADOR '=' exp 
    { 
        $$ = named_node("="); add_children($$, 2, lexval_node($1), $3); 
    }
|   TK_IDENTIFICADOR '[' exp ']' '=' exp
    { 
        node* vector = named_node("[]");
        add_children(vector, 2, lexval_node($1), $3);
        $$ = named_node("="); add_children($$, 2, vector, $6); 
    }
;

io:
    TK_PR_INPUT TK_IDENTIFICADOR
    {
        $$ = named_node("input"); add_children($$, 1, lexval_node($2));
    }
|   TK_PR_OUTPUT TK_IDENTIFICADOR
    {
        $$ = named_node("output"); add_children($$, 1, lexval_node($2));
    }
|   TK_PR_OUTPUT literal
    {
        $$ = named_node("output"); add_children($$, 1, $2);
    }
;

func_call:
    TK_IDENTIFICADOR '(' exp_list ')' 
    { 
        $$ = lexval_node($1); add_children($$, 1, $3); 
    }
;

exp_list:
    exp { $$ = $1; };
|   exp ',' exp_list { $$ = $1; add_children($$, 1, $3); }
;

shift:
    TK_IDENTIFICADOR TK_OC_SL TK_LIT_INT
    {
        $$ = lexval_node($2); 
        add_children($$, 2, lexval_node($1), lexval_node($3));
    }
|   TK_IDENTIFICADOR TK_OC_SR TK_LIT_INT
    {
        $$ = lexval_node($2); 
        add_children($$, 2, lexval_node($1), lexval_node($3));
    }
|   TK_IDENTIFICADOR TK_OC_SL '+' TK_LIT_INT
    {
        $$ = lexval_node($2); 
        add_children($$, 2, lexval_node($1), lexval_node($4));
    }
|   TK_IDENTIFICADOR TK_OC_SR '+' TK_LIT_INT
    {
        $$ = lexval_node($2); 
        add_children($$, 2, lexval_node($1), lexval_node($4));
    }
|   TK_IDENTIFICADOR '[' exp ']' TK_OC_SL TK_LIT_INT
    {
        node* vector = named_node("[]");
        add_children(vector, 2, lexval_node($1), $3);
        $$ = lexval_node($5); add_children($$, 2, vector, lexval_node($6));
    }
|   TK_IDENTIFICADOR '[' exp ']' TK_OC_SR TK_LIT_INT
    {
        node* vector = named_node("[]");
        add_children(vector, 2, lexval_node($1), $3);
        $$ = lexval_node($5); add_children($$, 2, vector, lexval_node($6));
    }
|   TK_IDENTIFICADOR '[' exp ']' TK_OC_SL '+' TK_LIT_INT
    {
        node* vector = named_node("[]");
        add_children(vector, 2, lexval_node($1), $3);
        $$ = lexval_node($5); add_children($$, 2, vector, lexval_node($7));
    }
|   TK_IDENTIFICADOR '[' exp ']' TK_OC_SR '+' TK_LIT_INT
    {
        node* vector = named_node("[]");
        add_children(vector, 2, lexval_node($1), $3);
        $$ = lexval_node($5); add_children($$, 2, vector, lexval_node($7));
    }
;

jmp_stmt:
    TK_PR_RETURN exp { $$ = named_node("return"); add_children($$, 1, $2); }
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
    TK_IDENTIFICADOR { $$ = lexval_node($1); }
|   TK_IDENTIFICADOR '[' exp ']'
    {
        $$ = named_node("[]");
        add_children($$, 2, lexval_node($1), $3);
    }
|   num { $$ = $1; }
|   bool { $$ = $1; }
|   func_call { $$ = $1; }
|   '(' exp ')' { $$ = $2; }
|   unary exp %prec UNARY { $$ = $1; add_children($$, 1, $2); }
|   exp '+' exp { $$ = named_node("+"); add_children($$, 2, $1, $3); }
|   exp '-' exp { $$ = named_node("-"); add_children($$, 2, $1, $3); }
|   exp '*' exp { $$ = named_node("*"); add_children($$, 2, $1, $3); }
|   exp '/' exp { $$ = named_node("/"); add_children($$, 2, $1, $3); }
|   exp '%' exp { $$ = named_node("%"); add_children($$, 2, $1, $3); }
|   exp '^' exp { $$ = named_node("^"); add_children($$, 2, $1, $3); }
|   exp '|' exp { $$ = named_node("|"); add_children($$, 2, $1, $3); }
|   exp '&' exp { $$ = named_node("&"); add_children($$, 2, $1, $3); }
|   exp '<' exp { $$ = named_node("<"); add_children($$, 2, $1, $3); }
|   exp '>' exp { $$ = named_node(">"); add_children($$, 2, $1, $3); }
|   exp TK_OC_AND exp { $$ = lexval_node($2); add_children($$, 2, $1, $3); }
|   exp TK_OC_EQ exp { $$ = lexval_node($2); add_children($$, 2, $1, $3); }
|   exp TK_OC_GE exp { $$ = lexval_node($2); add_children($$, 2, $1, $3); }
|   exp TK_OC_LE exp { $$ = lexval_node($2); add_children($$, 2, $1, $3); }
|   exp TK_OC_NE exp { $$ = lexval_node($2); add_children($$, 2, $1, $3); }
|   exp TK_OC_OR exp { $$ = lexval_node($2); add_children($$, 2, $1, $3); }
|   exp '?' exp ':' exp %prec TERNARY 
    { 
        $$ = named_node("?:");
        add_children($$, 3, $1, $3, $5);
    }
;

num:
    TK_LIT_FLOAT { $$ = lexval_node($1); }
|   TK_LIT_INT { $$ = lexval_node($1); }
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

