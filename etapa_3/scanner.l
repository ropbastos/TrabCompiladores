%{
    #include "parser.tab.h"
    #include "lexval.h"

    static void count_col();
    #define YY_USER_ACTION count_col();
    int col = 1;
    int get_line_number();
    int line_number = 1;

    struct lex_val* get_int_val();
    struct lex_val* get_float_val();
    struct lex_val* get_char_val();
    struct lex_val* get_str_val();
    struct lex_val* get_true_val();
    struct lex_val* get_false_val();

    struct lex_val* get_spchar_val();
    struct lex_val* get_cop_val();
    struct lex_val* get_id_val();

%}

alfa    [a-zA-Z_]
dig     [0-9]
sign   (\-|\+)
ws	    [ \t]
invisible [ \n\t\r\f]
operator [\+\-\*\%\^\&\<\>\<<\>>\.]
special_char [\,\;\:\(\)\[\]\{\}\+\-\|\*\/\<\>\=\!\&\%\#\^\.\$\\\?]
any_char [\,\t\r\f\;\:\(\)\[\]\{\}\+\-\|\*\/\<\>\=\!\&\%\#\^\.\$\@\?\/\~\`\\]

%x MULTILINE_COMMENT

%%

    /* Line counter */

\n  {line_number++; col = 1; }

    /* Reserved Words */

"int"           { return TK_PR_INT;      }
"float"         { return TK_PR_FLOAT;    }
"bool"          { return TK_PR_BOOL;     }
"char"          { return TK_PR_CHAR;     }
"string"        { return TK_PR_STRING;   }
"if"            { return TK_PR_IF;       }
"then"          { return TK_PR_THEN;     }
"else"          { return TK_PR_ELSE;     }
"while"         { return TK_PR_WHILE;    }
"do"            { return TK_PR_DO;       }
"input"         { return TK_PR_INPUT;    }
"output"        { return TK_PR_OUTPUT;   }
"return"        { return TK_PR_RETURN;   }
"const"         { return TK_PR_CONST;    }
"static"        { return TK_PR_STATIC;   }
"foreach"       { return TK_PR_FOREACH;  }
"for"           { return TK_PR_FOR;      }
"switch"        { return TK_PR_SWITCH;   }
"case"          { return TK_PR_CASE;     }
"break"         { return TK_PR_BREAK;    }
"continue"      { return TK_PR_CONTINUE; }
"class"         { return TK_PR_CLASS;    }
"private"       { return TK_PR_PRIVATE;  }
"public"        { return TK_PR_PUBLIC;   }
"protected"     { return TK_PR_PROTECTED;}
"end"           { return TK_PR_END;      }
"default"       { return TK_PR_DEFAULT;  }

    /* Special Characters */ 

{special_char}  { yylval.lex_val = get_spchar_val(); return yytext[0];      }

    /* Composite Operators */

"<="             { yylval.lex_val = get_cop_val(); return TK_OC_LE;      }
">="             { yylval.lex_val = get_cop_val(); return TK_OC_GE;      }
"=="             { yylval.lex_val = get_cop_val(); return TK_OC_EQ;      }
"!="             { yylval.lex_val = get_cop_val(); return TK_OC_NE;      }
"&&"             { yylval.lex_val = get_cop_val(); return TK_OC_AND;     }
"||"             { yylval.lex_val = get_cop_val(); return TK_OC_OR;      }
">>"             { yylval.lex_val = get_cop_val(); return TK_OC_SR;      }
"<<"             { yylval.lex_val = get_cop_val(); return TK_OC_SL;      }

    /* Literals */

{sign}*{dig}+\.{dig}+((e|E){sign}*{dig}+)*/({invisible}|{operator}+|\;|\,|\)) { 
    yylval.lex_val = get_float_val();
    return TK_LIT_FLOAT; 
    }

{dig}+/({invisible}|{operator}+|\]|\;|\,|\))  { 
    yylval.lex_val = get_int_val();
    return TK_LIT_INT; 
    }

"false" { yylval.lex_val = get_false_val(); return TK_LIT_FALSE; } 
"true"  { yylval.lex_val = get_true_val(); return TK_LIT_TRUE; } 

'(({alfa}{1})|({dig}{1})|({ws}{1})|({any_char}))'/({invisible}|{operator}+|\;) { 
    yylval.lex_val = get_char_val();
    return TK_LIT_CHAR; 
    }

\"[^\n"]+\" { yylval.lex_val = get_str_val(); return TK_LIT_STRING; }

    /* Identifiers */

{alfa}+({dig}|{alfa})*  { yylval.lex_val = get_id_val(); return TK_IDENTIFICADOR; }

    /* Eat up spaces and comments */

{ws}            { }
\/\/[^\n]*      { }

\/\* { BEGIN(MULTILINE_COMMENT); }
<MULTILINE_COMMENT>{
"*/"      BEGIN(INITIAL);
[^*\n]+   // eat comment in chunks
"*"       // eat the lone star
\n        { line_number++; col = 1; } 
}

    /* Errors */

. { return TOKEN_ERRO; }

%%


/* Bookkeeping */
int get_line_number() {
    return line_number;
}

int get_col() {
    return col - yyleng;
}

static void count_col() {
    for(int i = 0; yytext[i] != '\0'; i++) {
        col++;
    }
}


/* Token formation */

// Literals
struct lex_val* get_int_val() {
    struct lex_val *lvptr;
    lvptr = (struct lex_val*) malloc(sizeof(struct lex_val));

    lvptr->line = get_line_number();

    lvptr->lex_type = LIT_TK;

    lvptr->lit_type = INT_LT;
    lvptr->value.i = atoi(yytext);

    return lvptr;
}

struct lex_val* get_float_val() {
    struct lex_val *lvptr;
    lvptr = (struct lex_val*) malloc(sizeof(struct lex_val));

    lvptr->line = get_line_number();

    lvptr->lex_type = LIT_TK;

    lvptr->lit_type = FLOAT_LT;
    lvptr->value.f = atof(yytext);
    
    return lvptr;
}

struct lex_val* get_char_val() {
    struct lex_val *lvptr;
    lvptr = (struct lex_val*) malloc(sizeof(struct lex_val));

    lvptr->line = get_line_number();

    lvptr->lex_type = LIT_TK;

    lvptr->lit_type = CHAR_LT;

    lvptr->value.c = yytext[1];

    return lvptr;
}

struct lex_val* get_str_val() {
    struct lex_val *lvptr;
    lvptr = (struct lex_val*) malloc(sizeof(struct lex_val));

    lvptr->line = get_line_number();

    lvptr->lex_type = LIT_TK;

    lvptr->lit_type = STR_LT;
    lvptr->value.s = strdup(yytext);

    return lvptr;
}

struct lex_val* get_true_val() {
    struct lex_val *lvptr;
    lvptr = (struct lex_val*) malloc(sizeof(struct lex_val));

    lvptr->line = get_line_number();

    lvptr->lex_type = LIT_TK;

    lvptr->lit_type = BOOL_LT;
    lvptr->value.b = 1;

    return lvptr;
}

struct lex_val* get_false_val() {
    struct lex_val *lvptr;
    lvptr = (struct lex_val*) malloc(sizeof(struct lex_val));

    lvptr->line = get_line_number();

    lvptr->lex_type = LIT_TK;

    lvptr->lit_type = BOOL_LT;
    lvptr->value.b = 0;

    return lvptr;
}

// Others
struct lex_val* get_spchar_val() {
    struct lex_val *lvptr;
    lvptr = (struct lex_val*) malloc(sizeof(struct lex_val));

    lvptr->line = get_line_number();

    lvptr->lex_type = SPCHAR_TK;

    lvptr->lit_type = NA;
    lvptr->value.s = strdup(yytext);

    return lvptr;
}

struct lex_val* get_cop_val() {
    struct lex_val *lvptr;
    lvptr = (struct lex_val*) malloc(sizeof(struct lex_val));

    lvptr->line = get_line_number();

    lvptr->lex_type = COP_TK;

    lvptr->lit_type = NA;
    lvptr->value.s = strdup(yytext);

    return lvptr;
}

struct lex_val* get_id_val() {
    struct lex_val *lvptr;
    lvptr = (struct lex_val*) malloc(sizeof(struct lex_val));

    lvptr->line = get_line_number();

    lvptr->lex_type = ID_TK;

    lvptr->lit_type = NA;
    lvptr->value.s = strdup(yytext);

    return lvptr;
}
