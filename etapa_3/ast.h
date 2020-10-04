#include <stdarg.h>
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

// Nodes with no children.
node* create_literal_node(lex_val* val);
node* create_id_node(lex_val* val);

// Special char nodes
node* create_cop_node(lex_val* val, int child_num, node** children);

// DEBUG
void print_children(node* parent);

int traverse(node* tree);





