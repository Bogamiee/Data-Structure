// BinaryTree.c

#include "Stack.h"
#include "BinaryTree.h"

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed in createNode()\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(Node* parent, Node* right, Node* left) {
    if (parent->left == NULL) {
        parent->left = left;
    }
    if (parent->right == NULL) {
        parent->right = right;
    }
}

void deleteNode(Node* node) {
    free(node);
}

Node* expressionTree(char* postfix) {
    Stack s;
    char c;
    Node *parent, *left, *right;
    initStack(&s);

    printf("%s", postfix);
    for (int i = 0; postfix[i] != '\0'; i++) {
        c = postfix[i];

        if (!isOperator(c)) {
            pushChar(&s, c);
        }
        else {
            parent = createNode(c);
            right = createNode(*(char*)pop(&s));
            left = createNode(*(char*)pop(&s));
            insertNode(parent, right, left);
            pushNode(&s, parent);
        }
    }
}

void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    int j = 0;
    char c;
    initStack(&s);

    for (int i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        if (isOperator(c)) {
            while (!isEmpty(&s) && precedence(*(char*)peek(&s)) >= precedence(c)) {
                postfix[j++] = *(char*)pop(&s);
            }
            pushChar(&s, c);
        }
        else if (c == '(') {
            pushChar(&s, c);
        }
        else if (c == ')') {
            while (*(char*)peek(&s) != '(') {
                postfix[j++] = *(char*)pop(&s);
            }
            pop(&s);
        }
        else {
            postfix[j++] = c;
        }
    }
    while (!isEmpty(&s)) {
        postfix[j++] = *(char*)pop(&s);
    }
    delete(&s);
}

int precedence(char c) {
    switch (c) {
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

bool isOperator(char c) { // 연산자인지 확인
    return c == '+' || c == '-' || c == '*' || c == '/';
}
