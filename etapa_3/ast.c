#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

node* create_node(lex_val* val, int child_num, ...) {

    // Allocate memory for new node.
    node *nodeptr;
    nodeptr = (struct node*) malloc(sizeof(struct node));

    // Literal nodes
    if ( val->lex_type == LIT_TK ) {
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
                printf("not impl.");
        }
        
    }

    return nodeptr;
}