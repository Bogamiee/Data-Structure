// Stack.h

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "BinaryTree.h"

typedef struct Stack {
    void** data;
    int capacity;
    int top;
} Stack;

void initStack(Stack *s);
void push(Stack *s, void* item);
void pushChar(Stack *s, char c);
void pushNode(Stack *s, Node *n);
void* pop(Stack* s);
void* peek(Stack* s);
bool isEmpty(Stack *s);
bool isFull(Stack *s);
void deleteStack(Stack *s);

#endif
