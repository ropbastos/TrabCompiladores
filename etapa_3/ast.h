#include "lexval.h"

// Node struct
typedef struct node {
    char* label;
    lex_val* val;
    int child_num;
    struct node** children; 
} node;

enum node_type{lit, id};

node* create_node(lex_val* val, int child_num, ...);
int traverse(node* tree);





