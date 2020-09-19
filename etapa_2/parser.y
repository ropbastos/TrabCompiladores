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
    header

header:
    type TK_IDENTIFICADOR '(' ')'
|   type TK_IDENTIFICADOR '(' params ')'
|   TK_PR_STATIC type TK_IDENTIFICADOR '(' ')'
|   TK_PR_STATIC type TK_IDENTIFICADOR '(' params ')'

params:
    type TK_IDENTIFICADOR ',' params 
|   type TK_IDENTIFICADOR
|   TK_PR_CONST type TK_IDENTIFICADOR ',' params
|   TK_PR_CONST type TK_IDENTIFICADOR  


%%

void yyerror(char const *s) {
    fprintf(stderr, "%s on line %d at column %d\n",\
            s, get_line_number(), get_col());
}

int main() {
    return yyparse();
}