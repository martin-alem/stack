//
// Created by Martin Alemajoh on 9/24/2020.
//
#include <stdlib.h>
#include "stack.h"


void initStack(Stack *stack){

    stack->head = NULL;
    stack->tail = NULL;
}


void freeNode(void **node){

    if(node != NULL && *node != NULL){
        free(*node);
        *node = NULL;
    }
}

void clearStack(Stack *stack){

    if(stack->head != NULL) {
        Node *node = stack->head, *nextNode;

        while (node != NULL) {
            nextNode = node->next;
            freeNode((void **) &node);
            node = nextNode;
        }
        stack->head = NULL;
        stack->tail = NULL;
    }
}


int push(Stack *stack, void *data){

    Node *node = (Node *)malloc(sizeof(Node));
    if(node == NULL){
        return -1;
    }
    node->data = data;

    if(stack->head == NULL){
        node->next = NULL;
        stack->tail = node;
    }
    else{
        node->next = stack->head;
    }
    stack->head = node;
    return 1;
}

void pop(Stack *stack){

    if(stack->head != NULL) {

        if(stack->head == stack->tail){
            freeNode((void *)&stack->head);
            stack->head = NULL;
            stack->tail = NULL;
        }
        else {
            Node *nextNode = stack->head->next;
            freeNode((void **) &stack->head);
            stack->head = nextNode;
        }
    }
}

void *peek(Stack *stack){
    if(stack->head != NULL) {
        Node *node = stack->head;
        return node->data;
    }
    return NULL;
}


unsigned int getSize(Stack *stack){

    unsigned int len = 0;
    if(stack->head != NULL){
        Node *node = stack->head;
        while(node != NULL){
            node = node->next;
            len += 1;
        }
        return len;
    }
    return len;
}

