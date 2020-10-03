#include "lexval.h"

// Node struct
typedef struct node {
    char* label;
    lex_val* val;
    int child_num;
    node** children; 
} node;

enum node_type{lit, id};

int create_node(lex_val* val, int child_num, ...);
int traverse(node* tree);





