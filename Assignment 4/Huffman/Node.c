#include "Node.h"

Node* createNode(int freq, char ch) {
    Node* newNode = (Node*) malloc(sizeof(Node));

    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed in createNode()\n");
        exit(1);
    }

    newNode->freq = freq;
    newNode->ch = ch;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void linkNodes(Node* parent, Node* left, Node* right) {
    parent->left = left;
    parent->right = right;
}

void deleteNode(Node* node) {
    if (node == NULL) {
        return;
    }

    deleteNode(node->left);
    deleteNode(node->right);
    free(node);
}
