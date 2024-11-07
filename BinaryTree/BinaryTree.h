// BinaryTree.h

#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

Node* createNode(char data);
void insertNode(Node* parent, Node* right, Node* left);
void deleteNode(Node* node);
Node* expressionTree(char* postfix);
void infixToPostfix(char* infix, char* postfix);
int precedence(char c);
bool isOperator(char c);
void infixOrder(Node* root);
void prefixOrder(Node* root);
void postfixOrder(Node* root);
void levelOrder(Node* root);
void deleteTree(Node* root);

#endif
