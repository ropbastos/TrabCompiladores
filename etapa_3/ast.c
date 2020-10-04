#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

node* create_node(lex_val* val, int child_num, ...) {
    
    // Write children.
    node** children;
    if (child_num) {
        va_list valist;

        va_start(valist, child_num);

        children = malloc(child_num * sizeof(struct node*));

        for (int i = 0; i < child_num; i++) {
            children[i] = va_arg(valist, node*);
        }
    };
 
    switch ( val->lex_type ) {
        case LIT_TK:
            return create_literal_node(val);
        case ID_TK:
            return create_id_node(val);
        case COP_TK:
            printf("vai criar cop node\n");
            return create_cop_node(val, child_num, children);
    };

    return NULL;
}

node* create_cop_node(lex_val* val, int child_num, node** children) {
    // Allocate memory.
    node *nodeptr;
    nodeptr = (struct node*) malloc(sizeof(struct node));

    // Write label
    nodeptr->label = strdup(val->value.s); // hidden malloc
    printf("cop_node: escreveu label\n");
    // Write value
    nodeptr->val = val;
    printf("cop_node: escreveu valor\n");
    // Write children
    nodeptr->child_num = child_num + 1;
    nodeptr->children = children;
    printf("cop_node: escreveu filhos\n");
    return nodeptr;
}

node* create_id_node(lex_val* val) {

    // Allocate memory
    node *nodeptr;
    nodeptr = (struct node*) malloc(sizeof(struct node));

    // Write label
    nodeptr->label = strdup(val->value.s); // hidden malloc

    // Write value
    nodeptr->val = val;

    // Write children
    nodeptr->child_num = 0;
    nodeptr->children = NULL;

    return nodeptr;
}

node*  create_literal_node(lex_val* val) {
    node *nodeptr;
    nodeptr = (struct node*) malloc(sizeof(struct node));

    switch ( val->lit_type ) {
        case INT_LT:
            // Write label
            nodeptr->label = (char*) malloc(2);
            nodeptr->label = (char*) &(val->value.i);
            *(nodeptr->label) += '0';
            nodeptr->label[1] = '\0';

            // Write value
            nodeptr->val = val;

            // Write children
            nodeptr->child_num = 0;
            nodeptr->children = NULL;

            break;
        case FLOAT_LT:
            // Write label
            nodeptr->label = (char*) malloc(5);
            gcvt(val->value.f, 4, nodeptr->label);

            // Write value
            nodeptr->val = val;

            // Write children
            nodeptr->child_num = 0;
            nodeptr->children = NULL;

            break;
        case CHAR_LT:
            // Write label
            nodeptr->label = (char*) malloc(2);

            nodeptr->label = (char*) &(val->value.c);
            nodeptr->label[1] = '\0';

            // Write value
            nodeptr->val = val;

            // Write children
            nodeptr->child_num = 0;
            nodeptr->children = NULL;

            break;
        case BOOL_LT:
            // Write label
            if (val->value.b == 1) {
                nodeptr->label = malloc(5);

                strcpy(nodeptr->label, "True");
            } else {
                nodeptr->label = malloc(6);

                strcpy(nodeptr->label, "False");
            };

            // Write value
            nodeptr->val = val;

            // Write children
            nodeptr->child_num = 0;
            nodeptr->children = NULL;

            break;
        case STR_LT:
            // Write label
            nodeptr->label = (char*) malloc(sizeof(val->value.s));
            strcpy(nodeptr->label, val->value.s);

            // Write value
            nodeptr->val = val;

            // Write children
            nodeptr->child_num = 0;
            nodeptr->children = NULL;

            break;
    }

    return nodeptr;
}

// DEBUG

void print_children(node* parent){
    printf("Vai imprimir as criancas\n");
    for (int i = 0; i < parent->child_num - 1; i++) {
        printf("child label: %s\n", ((parent->children)[i])->label);
    };
}