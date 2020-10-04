#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"


node* lexval_node(lex_val* val, int child_num, ...) {
    
    // Allocate memory.
    node *nodeptr = (struct node*) malloc(sizeof(struct node));

    // Write label.
    nodeptr->label = get_label(val);

    // Write value.
    nodeptr->val = val;

    // Write children.
    if (child_num) {
        node** children = malloc(child_num * sizeof(struct node*));

        va_list valist;

        va_start(valist, child_num);

        for (int i = 0; i < child_num; i++) {
            children[i] = va_arg(valist, node*);
        }

        nodeptr->child_num = child_num;
        nodeptr->children = children;
    };

    return nodeptr;
}

node* named_node(char* name, int child_num, ...) {
    
    // Allocate memory.
    node *nodeptr = (struct node*) malloc(sizeof(struct node));

    // Write label.
    nodeptr->label = strdup(name);

    // Write value.
    nodeptr->val = NULL;

    // Write children.
    if (child_num) {
        node** children = malloc(child_num * sizeof(struct node*));

        va_list valist;

        va_start(valist, child_num);

        for (int i = 0; i < child_num; i++) {
            children[i] = va_arg(valist, node*);
        }

        nodeptr->child_num = child_num;
        nodeptr->children = children;
    };

    return nodeptr;
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
            // Write label
            label = strdup(val->value.s);

            break;
        case NA:
            label = strdup(val->value.s);

            break;
    }

    return label;
}

// DEBUG

void print_children(node* parent){
    printf("Parent label: %s\n", parent->label);
    printf("Number of children: %d\n", parent->child_num);
    for (int i = 0; i < parent->child_num; i++) {
        if ( ((parent->children)[i])->label )
            printf("child label: %s\n", ((parent->children)[i])->label);
        else
        {
            printf("child label: NULL\n");
        }       
    };
    printf("\n");
}