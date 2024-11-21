#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int freq;
    char ch;
    struct Node *left, *right;
} Node;

Node* createNode(int freq, char ch);
void linkNodes(Node* parent, Node* left, Node* right);
void deleteNode(Node* node);

#endif
