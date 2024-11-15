#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    char symbol;
    int frequency;
    struct Node *left, *right;
} Node;

Node* createNode(char data, int freq);
void linkNodes(Node* parent, Node* left, Node* right);
void freeTree(Node* root);

#endif
