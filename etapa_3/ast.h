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
node* lexval_node(lex_val* val);

// Nodes from reduced labels
node* named_node(char* name);

void add_children(node* parent, int child_num, ...);

void free_node(node* node);

void free_aux(node* node);

// Auxiliary
char* get_label(lex_val* val);

void print_csv_tree(node* tree);

void print_tree_labels(node* tree);

// DEBUG
void print_children(node* parent);

int traverse(node* tree);





