// Stack.c

#include "Stack.h"

void initStack(Stack *s) {
    s->top = -1;
    s->capacity = 1;
    s->data = (void**)malloc(sizeof(void*) * s->capacity);
    if (s->data == NULL) {
        printf("Memory allocation failed in initStack()\n");
        exit(1);
    }
}

void push(Stack *s, void* item) {
    if (isFull(s)) {
        s->capacity *= 2;
        s->data = (void**)realloc(s->data, sizeof(void*) * s->capacity);
        if (s->data == NULL) {
            printf("Memory allocation failed in push()\n");
            exit(1);
        }
    }
    s->data[++s->top] = item;
}

void pushChar(Stack *s, char c) {
    char *cPtr = (char *)malloc(sizeof(char));
    if (cPtr == NULL) {
        printf("Memory allocation failed in pushChar()\n");
        exit(1);
    }
    *cPtr = c;
    push(s, cPtr);
}

void pushNode(Stack *s, Node* n) {
    push(s, (void*)n);
}

void* pop(Stack* s) {
    if(isEmpty(s)) {
        fprintf(stderr, "Stack is empty in pop()\n");
        exit(1);
    }
    else return s->data[s->top--];
}

void* peek(Stack* s) {
    if(isEmpty(s)) {
        fprintf(stderr, "Stack is empty in peek()\n");
        exit(1);
    }
    else return s->data[s->top];
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

bool isFull(Stack *s) {
    return s->top == s->capacity - 1;
}

void deleteStack(Stack *s) {
    for (int i = 0; i <= s->top; i++) {
        free(s->data[i]);
    }
    free(s->data);
    s->top = NULL;
}
