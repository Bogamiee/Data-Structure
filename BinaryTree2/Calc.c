#include "Calc.h"

Node* infixToBinaryTree(char* infix) {
    
}

int precedence(char op) {
    switch (op) {
        case '(':
        case ')':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1;
    }
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void printInfix(Node* root) {
    if (root != NULL) {
        if (isOperator(root->data)) {
            printf("(");
        }
        infixOrder(root->left);
        printf("%c", root->data);
        infixOrder(root->right);
        if (isOperator(root->data)) {
            printf(")");
        }
    }
}

void printPostfix(Node* root) {
    if (root != NULL) {
        postfixOrder(root->left);
        postfixOrder(root->right);
        printf("%c", root->data);
    }
}

void printPrefix(Node* root) {
    if (root != NULL) {
        printf("%c", root->data);
        prefixOrder(root->left);
        prefixOrder(root->right);
    }
}

void printLevel(Node* root) {
    if (root != NULL) {
        Queue q;
        Node* node;
        initQueue(&q);
        enqueue(&q, root);

        while (!isQueueEmpty(&q)) {
            node = dequeue(&q);
            printf("%c", node->data);
            if (node->left != NULL) {
                enqueue(&q, node->left);
            }
            if (node->right != NULL) {
                enqueue(&q, node->right);
            }
        }
    }
}
