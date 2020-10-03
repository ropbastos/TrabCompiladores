#define SPCHAR_TK 1
#define COP_TK 2
#define ID_TK 3
#define LIT_TK 4

#define INT_LT 5
#define FLOAT_LT 6
#define CHAR_LT 7
#define BOOL_LT 8

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