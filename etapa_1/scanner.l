%{
    #include "tokens.h"
    int line_number = 1;
%}

alfa    [a-zA-Z_]
dig     [0-9]
sign   (\-|\+)
ws	    [ \t]
invisible [ \n\t\r\f]
operator [\+\-\*\%\^\&\<\>\<<\>>\.]
special_char [\,\;\:\(\)\[\]\{\}\+\-\|\*\/\<\>\=\!\&\%\#\^\.\$]

%%

    /* Line counter */

\n  line_number++;

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

{special_char}  { return yytext[0];      }

    /* Composite Operators */

"<="             { return TK_OC_LE;      }
">="             { return TK_OC_GE;      }
"=="             { return TK_OC_EQ;      }
"!="             { return TK_OC_NE;      }
"&&"             { return TK_OC_AND;     }
"||"             { return TK_OC_OR;      }
">>"             { return TK_OC_SR;      }
"<<"             { return TK_OC_SL;      }

    /* Literals */

{sign}*{dig}+\.{dig}+((e|E){sign}*{dig}+)*/({invisible}|{operator}+) { return TK_LIT_FLOAT; }

{sign}*{dig}+/({invisible}|{operator}+)  { return TK_LIT_INT; }

"false" { return TK_LIT_FALSE; } 
"true"  { return TK_LIT_TRUE; } 

'(({alfa}{1})|({dig}{1})|({ws}{1})|({special_char}))' { return TK_LIT_CHAR; }

\"[^\n"]+\" { return TK_LIT_STRING; }

    /* Identifiers */

{alfa}+({dig}|{alfa})*  { return TK_IDENTIFICADOR; }

    /* Eat up spaces and comments */

{ws}            { }
\/\/[^\n]*      { }
"/*"		    {
                    int c;

                    while((c = input()) != 0) {
                        if(c == '\n')
                            ++line_number;
                        else if(c == '*') {
                            if((c = input()) == '/')
                                break;
                            else
                                unput(c);
                        }
                    }
		        }

    /* Errors */

. { return TOKEN_ERRO; }

%%

int get_line_number() {
    return line_number;
}