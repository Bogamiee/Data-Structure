#include "Stack.h"

void initStack(Stack *s) {
    s->top = -1;
    s->capacity = 16;
    s->data = (Node**)malloc(s->capacity * sizeof(Node*));
}

bool isStackEmpty(Stack *s) {
    return s->top == -1;
}

bool isStackFull(Stack *s) {
    return s->top == s->capacity - 1;
}

void pushStack(Stack *s, Node *n) {
    if (isStackFull(s)) {
        s->capacity *= 2;
        s->data = (Node**)realloc(s->data, s->capacity * sizeof(Node*));
    }
    s->data[++s->top] = n;
}

Node* popStack(Stack* s) {
    if (isStackEmpty(s)) {
        fprintf(stderr, "Stack is empty in popStack()\n");
        exit(1);
    }
    return s->data[s->top--];
}

Node* peekStack(Stack* s) {
    if (isStackEmpty(s)) {
        fprintf(stderr, "Stack is empty in peekStack()\n");
        exit(1);
    }
    return s->data[s->top];
}

void freeStack(Stack *s) {
    for (int i = 0; i <= s->top; i++) {
        free(s->data[i]);
    }
    free(s->data);
    s->top = -1;
    s->capacity = 0;
}
