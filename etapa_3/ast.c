#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"


node* lexval_node(lex_val* val) {
    
    // Allocate memory.
    node *nodeptr = (struct node*) malloc(sizeof(struct node));

    // Write label.
    nodeptr->label = get_label(val);

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

    // Write value.
    nodeptr->val = NULL;

    // Write children.
    nodeptr->child_num = 0;
    nodeptr->children = NULL;

    return nodeptr;
}

void add_children(node* parent, int child_num, ...) {
    if ( parent == NULL || child_num == 0) return;

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

    node* tree = (node*) arvore;

    // Print CSV structure
    print_csv_tree(tree);

    // Print labeled nodes.
    print_tree_labels(tree);

}

// Auxiliary
char* get_label(lex_val* val) {

    char* label;

    switch ( val->lit_type ) {
        case INT_LT:
            label = (char*) malloc(2);
            label = (char*) &(val->value.i);
            *label += '0';
            label[1] = '\0';

            break;
        case FLOAT_LT:
            label = (char*) malloc(5);
            gcvt(val->value.f, 4, label);

            break;
        case CHAR_LT:
            label = (char*) malloc(2);
            label = (char*) &(val->value.c);
            label[1] = '\0';

            break;
        case BOOL_LT:
            if (val->value.b == 1) {
                label = "True";
            } else {
                label = "False";
            };

            break;
        case STR_LT:
            label = strdup(val->value.s);

            break;
        case NA:
            label = strdup(val->value.s);

            break;
    }

    return label;
}

void print_csv_tree(node* tree) {
     // Print CSV structure
    if ( tree->child_num ) {
        for (int i = 0; i < tree->child_num; i++) {
            if ( ((tree->children)[i])->label ) {
                printf("%p, %p\n", tree, (tree->children)[i]);
                
                if ( ((tree->children)[i])->children ) {
                    print_csv_tree( tree->children[i] );
                };
            }
            else
            {
                return;
            }       
        };
    };
}

void print_tree_labels(node* tree) {

    printf("%p [label=\"%s\"];\n", tree, tree->label);
    if (tree->child_num) {
        for (int i = 0; i < tree->child_num; i++) {
            if ( ((tree->children)[i])->label ) {
                print_tree_labels( tree->children[i] );
            }
            else
            {
                return;
            }       
        };
    };
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