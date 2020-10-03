#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

node* create_node(lex_val* val, int child_num, ...) {

    // Allocate memory for new node.
    node *nodeptr;
    nodeptr = (struct node*) malloc(sizeof(struct node));

    // Literal nodes
    if ( val->lex_type == LIT_TK ) {
        switch ( val->lit_type) {
            case INT_LT:
                printf("VALOR INTEIRO DO LIT: %d\n", val->value.i);
                printf("VALOR CHAR DO LIT: %c\n", val->value.i + '0');
                nodeptr->label = (char*) &(val->value.i); 
                *(nodeptr->label) += '0';
                break;
            case FLOAT_LT:
            case CHAR_LT:
            case BOOL_LT:
                printf("not impl.");
        }
        
    }

    return nodeptr;
}