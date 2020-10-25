#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

int return_line = -1;
int expected_return_type = 0;
int return_type_is_correct = 1;


node* lexval_node(lex_val* val) {
    
    // Allocate memory.
    node *nodeptr = (struct node*) malloc(sizeof(struct node));

    // Write label.
    nodeptr->label = get_label(val);

    // Write type.
    nodeptr->data_type = val->lit_type;
    nodeptr->is_return = 0;
    nodeptr->return_line = -1;

    // Write value.
    nodeptr->val = val;

    // Write children.
    nodeptr->child_num = 0;
    nodeptr->children = NULL;

    return nodeptr;
}

node* named_node(char* name) {
    
    // Allocate memory.
    node *nodeptr = (struct node*) malloc(sizeof(struct node));

    // Write label.
    nodeptr->label = strdup(name);

    // Write type.
    nodeptr->data_type = UDEF_TYPE;
    nodeptr->is_return = 0;
    nodeptr->return_line = -1;

    // Write value.
    nodeptr->val = NULL;

    // Write children.
    nodeptr->child_num = 0;
    nodeptr->children = NULL;

    return nodeptr;
}

void add_children(node* parent, int child_num, ...) {
    if ( parent == NULL || child_num == 0) {
        fprintf(stderr, "%s", "ERROR: NULL parent or zero children\n");
    }

    // Get new children.
    node* children[child_num];

    va_list valist;

    va_start(valist, child_num);

    for (int i = 0; i < child_num; i++) {
        children[i] = va_arg(valist, node*);
    }

    parent->child_num = parent->child_num + child_num;

    parent->children = realloc(parent->children, parent->child_num * sizeof(node*));

    for (int i = 0; i < child_num; i++) {
        parent->children[parent->child_num-child_num + i] = children[i];
    }

}

void exporta (void* arvore) {
    if (arvore == NULL) return;

    node* tree = (node*) arvore;

    // Print CSV structure
    print_csv_tree(tree);

    // Print labeled nodes.
    print_tree_labels(tree);

}

void free_node(node* node) {
    if (node->val != NULL) {
        if (node->val->lit_type == STR_LT
            || node->val->lit_type == NA) 
            free(node->val->value.s); 

        free(node->val);  
    }

    if (node->label != NULL) free(node->label);
    if (node->children != NULL) free(node->children);
    free(node);
}

void free_aux(node* node) {
    if(node == NULL) return;

    for (int i = 0; i < node->child_num; i++) {
        free_aux(node->children[i]);
    }

    free_node(node);
}

void libera (void* arvore) {
    if (arvore == NULL) return;
    node* tree = (node*) arvore;
    free_aux(tree);
}


// Auxiliary
char* get_label(lex_val* val) {

    char* label;
    char aux[12];

    switch ( val->lit_type ) {
        case INT_LT:
            sprintf(aux, "%d", val->value.i);
            label = strdup(aux);
            break;
        case FLOAT_LT:
            gcvt(val->value.f, 4, aux);
            label = strdup(aux);
            break;
        case CHAR_LT:
            aux[0] = val->value.c;
            aux[1] = '\0';
            label = strdup(aux);
            break;
        case BOOL_LT:
            if (val->value.b == 1) {
                label = strdup("True");
            } else {
                label = strdup("False");
            };
            break;
        default: // STR_LT and NA(non-literals, ID, COP, SPCHAR) 
            label = strdup(val->value.s); 
    }

    return label;
}

void print_csv_tree(node* tree) {
     // Print CSV structure
    if ( tree->child_num ) {
        for (int i = 0; i < tree->child_num; i++) {
            if ( tree->children[i] != NULL ) {
                printf("%p, %p\n", tree, (tree->children)[i]);
                
                if ( ((tree->children)[i])->children ) {
                    print_csv_tree( tree->children[i] );
                };
            }    
        };
    };
}

void print_tree_labels(node* tree) {

    printf("%p [label=\"%s\" type=\"%d\"];\n", tree, tree->label, tree->data_type);
    if (tree->child_num) {
        for (int i = 0; i < tree->child_num; i++) {
            if ( tree->children[i] != NULL ) {
                print_tree_labels( tree->children[i] );
            };    
        };
    };
}

void check_return_type(node* tree)
{
  if (tree == NULL) return;
  //printf("Current node data type: %d\n", tree->data_type);
  if (tree->is_return == 1)
  {
    //printf("Current node data type dentro do if: %d\n", tree->data_type);
    if (expected_return_type != tree->data_type)
    {
     return_type_is_correct = 0;
     return_line = tree->return_line;
     return;
    }
  }

  if (tree->child_num)
  {
    for (int i = 0; i < tree->child_num; i++)
    {
      check_return_type(tree->children[i]);
    }
  }
}

// DEBUG

void print_children(node* parent){

    printf("\nParent label: %s\n", parent->label);
    printf("Number of children: %d\n", parent->child_num);
    for (int i = 0; i < parent->child_num; i++) {
        if ( ((parent->children)[i])->label ) {
            printf("child label: %s\n", ((parent->children)[i])->label);
            
            if ( ((parent->children)[i])->children ) {

                print_children( parent->children[i] );
            };
        }
        else
        {
            printf("child label: NULL\n");
        }       
    };
}

node* return_first_child(node* parent){
    return parent->children[0];
}