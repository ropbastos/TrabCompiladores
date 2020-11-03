#ifndef LEXVAL_H
#define LEXVAL_H

// LEX TYPES
#define SPCHAR_TK 1
#define COP_TK 2
#define ID_TK 3
#define LIT_TK 4
//

// LIT TYPES
#define INT_LT 5
#define FLOAT_LT 6
#define CHAR_LT 7
#define STR_LT 8
#define BOOL_LT 9

#define NA 0

#define TRUE 1
#define FALSE 0
//

typedef union {
    int i;
    float f;
    int b;
    char c;
    char* s;
} TOKEN_VAL;

typedef struct lex_val {
    int line;
    int lex_type;
    int lit_type;
    TOKEN_VAL value;
} lex_val;

#endif
