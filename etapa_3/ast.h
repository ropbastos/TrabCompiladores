#include <stdarg.h>
#include "lexval.h"

// Node struct
typedef struct node {
    char* label;
    lex_val* val;
    int child_num;
    struct node** children; 
} node;

// Nodes from lex objects
node* create_lv_node(lex_val* val, int child_num, ...);

// Nodes from reduced labels
node* create_node(lex_val* val, int child_num, ...);


// Auxiliary
char* get_label(lex_val* val);

// DEBUG
void print_children(node* parent);

int traverse(node* tree);





