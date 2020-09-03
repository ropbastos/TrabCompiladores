%{
    #include "tokens.h"
    int num_linha = 1;
%}

alfa    [a-zA-Z_]
dig     [0-9]
sinal   (\-|\+)
ws	    [ \t]
caractere_especial [,!;:\(\)\[\]\{\}\+\-\|\?\@\*\/\<\>\=\&\%\#\.\$^~`]

%%

    /* Conta linhas */

\n  num_linha++;

    /* Palavras Reservadas */

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

    /* Caracteres Especiais */ 

","             { return yytext[0];      }
";"             { return yytext[0];      }
":"             { return yytext[0];      }
"("             { return yytext[0];      }
")"             { return yytext[0];      }
"["             { return yytext[0];      }
"]"             { return yytext[0];      }
"{"             { return yytext[0];      }
"}"             { return yytext[0];      }
"+"             { return yytext[0];      }
"-"             { return yytext[0];      }
"|"             { return yytext[0];      }
"*"             { return yytext[0];      }
"/"             { return yytext[0];      }
"<"             { return yytext[0];      }
">"             { return yytext[0];      }
"="             { return yytext[0];      }
"!"             { return yytext[0];      }
"&"             { return yytext[0];      }
"%"             { return yytext[0];      }
"#"             { return yytext[0];      }
"^"             { return yytext[0];      }
"."             { return yytext[0];      }
"$"             { return yytext[0];      }

    /* Operadores Compostos */

"<="             { return TK_OC_LE;      }
">="             { return TK_OC_GE;      }
"=="             { return TK_OC_EQ;      }
"!="             { return TK_OC_NE;      }
"&&"             { return TK_OC_AND;     }
"||"             { return TK_OC_OR;      }
">>"             { return TK_OC_SR;      }
"<<"             { return TK_OC_SL;      }

    /* Literais */

{sinal}*{dig}+\.{dig}+((e|E){sinal}*{dig}+)* { return TK_LIT_FLOAT; }

{sinal}*{dig}+ { return TK_LIT_INT; }

"false" { return TK_LIT_FALSE; } 
"true"  { return TK_LIT_TRUE; } 

'(({alfa}{1})|({dig}{1})|({ws}{1})|({caracter_especial}))' { return TK_LIT_CHAR; }

\"[^\n"]+\" { return TK_LIT_STRING; }

    /* Identificadores */

{alfa}+{dig}*  { return TK_IDENTIFICADOR; }

    /* Coisas Ignoradas */

{ws}            { }
\/\/[^\n]*      { }
"/*"		    {
                    int c;

                    while((c = input()) != 0) {
                        if(c == '\n')
                            ++num_linha;
                        else if(c == '*') {
                            if((c = input()) == '/')
                                break;
                            else
                                unput(c);
                        }
                    }
		        }

    /* Erros */

{dig}+{alfa}+ { return TOKEN_ERRO; }
. { return TOKEN_ERRO; }

%%

int get_line_number() {
    return num_linha;
}