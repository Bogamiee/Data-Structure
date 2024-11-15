#include "Tree.h"

Node* createNode(char data, int freq) { // Create a new node with the given data
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed in createNode()\n");
        exit(1);
    }
    newNode->symbol = data;
    newNode->frequency = freq;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void linkNodes(Node* parent, Node* left, Node* right) { // Link the parent node to the left and right children
    parent->left = left;
    parent->right = right;
}

void freeTree(Node* root) { // Free the memory allocated for the tree
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
