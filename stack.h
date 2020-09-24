//
// Created by Martin Alemajoh on 9/24/2020.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

/*
 * Node structure
*/
typedef struct _node{

    void *data;
    struct _node *next;
}Node;

/*
Stack structure
*/
typedef struct _stack{

    Node *head;
    Node *tail;
}Stack;


/*
DEF: Initialize stack structure
PARAM: Stack *stack - stack structure to be initialize
RETURN: returns void
*/
void initStack(Stack *stack);


/*
DEF: frees a node inside a stack
PARAM: void **node - pointer to node
RETURN: returns void
*/
void freeNode(void **node);


/*
DEF: Destroys the stacks by deallocating all nodes
PARAM: Stack *stack - stack structure to be destroyed
RETURN: returns void
*/
void clearStack(Stack *stack);



/*
DEF: Push a node onto the stack
PARAM1: Stack *stack - stack structure.
PARAM2: void data - data to be store inside node.
RETURN: returns 1 if push was successful otherwise -1
*/
int push(Stack *stack, void *data);


/*
DEF: Pops off a node from the top of the stack
PARAM: Stack *stack - stack structure.
RETURN: returns void
*/
void pop(Stack *stack);


/*
DEF: Retrieves data stored at the top of the stack
PARAM: Stack *stack - stack structure
RETURN: returns pointer to void
*/
void *peek(Stack *stack);


/*
DEF: Gets the size of the stack
PARAM: Stack *stack - stack structure
RETURN: returns the size of the stack otherwise 0
*/
unsigned int getSize(Stack *stack);


#endif //STACK_STACK_H
