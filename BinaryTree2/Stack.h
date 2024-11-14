#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Tree.h"

typedef struct Stack {
    Node** data;
    int capacity;
    int top;
} Stack;

void initStack(Stack *s);
bool isStackEmpty(Stack *s);
bool isStackFull(Stack *s);
void pushStack(Stack *s, Node *n);
Node* popStack(Stack* s);
Node* peekStack(Stack* s);
void freeStack(Stack *s);

#endif
