#include <stdarg.h>
#include "lexval.h"

#define INT INT_LT
#define FLOAT FLOAT_LT
#define CHAR CHAR_LT
#define STR STR_LT
#define BOOL BOOL_LT

#define UDEF_TYPE 78
#define UDEF_SIZE -79

// Node struct
typedef struct node {
    char* label;
    int is_return, return_line;
    int data_type;
    int size;
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

void check_return_type(node* tree);

// DEBUG
void print_children(node* parent);

int traverse(node* tree);

node* return_first_child(node* parent);





