#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

Node* createNode(char data);
void linkNodes(Node* parent, Node* left, Node* right);
void freeNode(Node* n);
void freeTree(Node* root);

#endif
