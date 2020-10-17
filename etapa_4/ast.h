#include <stdarg.h>
#include "lexval.h"

#define INT 47
#define FLOAT 48
#define CHAR 49
#define STR 50
#define BOOL 51

// Node struct
typedef struct node {
    char* label;
    int data_type;
    lex_val* val;
    int child_num;
    struct node** children; 
} node;

// Nodes from lex objects
node* lexval_node(lex_val* val);

// Nodes from reduced labels
node* named_node(char* name);

// Add children to nodes
void add_children(node* parent, int child_num, ...);

// Free tree memory
void libera (void* arvore);

void free_node(node* node);

// Auxiliary
char* get_label(lex_val* val);

void print_csv_tree(node* tree);

void print_tree_labels(node* tree);

void free_aux(node* node);

// DEBUG
void print_children(node* parent);

int traverse(node* tree);

node* return_first_child(node* parent);





