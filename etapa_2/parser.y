%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror (char const *s);
int get_line_number();
int get_col();
%}

%define parse.error verbose

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
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR
%token TK_OC_SL
%token TK_OC_SR
%token TK_OC_FORWARD_PIPE
%token TK_OC_BASH_PIPE
%token TK_LIT_INT
%token TK_LIT_FLOAT
%token TK_LIT_FALSE
%token TK_LIT_TRUE
%token TK_LIT_CHAR
%token TK_LIT_STRING
%token TK_IDENTIFICADOR
%token TOKEN_ERRO

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
    TK_IDENTIFICADOR ',' global_list
|   TK_IDENTIFICADOR
|   TK_IDENTIFICADOR '[' TK_LIT_INT ']' ',' global_list
|   TK_IDENTIFICADOR '[' TK_LIT_INT ']'
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
    %empty                 // NOT COMPLETE
|   block ';' cmds
|   local_decl ';' cmds
|   attrib ';' cmds
|   exp ';' cmds
|   io ';' cmds
|   func_call ';' cmds
|   shift ';' cmds
|   jmp_stmt ';' cmds
|   if cmds
|   for cmds
|   while cmds
;



local_decl:
    type local_list
|   TK_PR_CONST type local_list
|   TK_PR_STATIC TK_PR_CONST type local_list
|   TK_PR_STATIC type local_list
;

local_list:
    TK_IDENTIFICADOR
|   TK_IDENTIFICADOR TK_OC_LE TK_IDENTIFICADOR
|   TK_IDENTIFICADOR TK_OC_LE TK_LIT_CHAR
|   TK_IDENTIFICADOR TK_OC_LE TK_LIT_FALSE
|   TK_IDENTIFICADOR TK_OC_LE TK_LIT_FLOAT
|   TK_IDENTIFICADOR TK_OC_LE TK_LIT_INT
|   TK_IDENTIFICADOR TK_OC_LE TK_LIT_STRING
|   TK_IDENTIFICADOR TK_OC_LE TK_LIT_TRUE
|   TK_IDENTIFICADOR ',' local_list
|   TK_IDENTIFICADOR TK_OC_LE TK_IDENTIFICADOR ',' local_list
|   TK_IDENTIFICADOR TK_OC_LE TK_LIT_CHAR ',' local_list
|   TK_IDENTIFICADOR TK_OC_LE TK_LIT_FALSE ',' local_list
|   TK_IDENTIFICADOR TK_OC_LE TK_LIT_FLOAT ',' local_list
|   TK_IDENTIFICADOR TK_OC_LE TK_LIT_INT ',' local_list
|   TK_IDENTIFICADOR TK_OC_LE TK_LIT_STRING ',' local_list
|   TK_IDENTIFICADOR TK_OC_LE TK_LIT_TRUE ',' local_list
;

attrib:
    TK_IDENTIFICADOR '=' exp
|   TK_IDENTIFICADOR '[' exp ']' '=' exp
;

io:
    TK_PR_INPUT TK_IDENTIFICADOR
|   TK_PR_OUTPUT TK_IDENTIFICADOR
|   TK_PR_OUTPUT TK_LIT_CHAR
|   TK_PR_OUTPUT TK_LIT_FALSE
|   TK_PR_OUTPUT TK_LIT_FLOAT
|   TK_PR_OUTPUT TK_LIT_INT
|   TK_PR_OUTPUT TK_LIT_STRING
|   TK_PR_OUTPUT TK_LIT_TRUE
;

func_call:
    TK_IDENTIFICADOR '(' exp ')'
;

shift:
    TK_IDENTIFICADOR TK_OC_SL TK_LIT_INT
|   TK_IDENTIFICADOR TK_OC_SR TK_LIT_INT
|   TK_IDENTIFICADOR '[' exp ']' TK_OC_SL TK_LIT_INT
|   TK_IDENTIFICADOR '[' exp ']' TK_OC_SR TK_LIT_INT
;

jmp_stmt:
    TK_PR_RETURN exp
|   TK_PR_BREAK
|   TK_PR_CONTINUE
;

// BLOCKS BELOW MUST HAVE NO SEMICOLONS

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
    arithOperand
|   arithOperand arithSimbol arithOperand
|   '(' exp ')'
;

arithSimbol:
    '+'
|   '-'
|   '*'
|   '/'
|   '%'
|   '^'
;

arithOperand:
    TK_IDENTIFICADOR
|   TK_LIT_INT
|   TK_LIT_FLOAT
;

%%

void yyerror(char const *s) {
    fprintf(stderr, "%s on line %d at column %d\n",\
            s, get_line_number(), get_col());
}

int main() {
    return yyparse();
}
