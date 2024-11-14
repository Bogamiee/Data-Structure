// BinaryTree.c

#include "Stack.h"
#include "Queue.h"
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
    parent->left = left;
    parent->right = right;
}

void deleteNode(Node* node) {
    free(node);
}

Node* expressionTree(char* postfix) {
    Stack s;
    char c;
    Node *parent, *left, *right;
    initStack(&s);

    for (int i = 0; postfix[i] != '\0'; i++) {
        c = postfix[i];

        if (!isOperator(c)) {
            pushNode(&s, createNode(c));
        }
        else {
            parent = createNode(c);
            right = (Node*)pop(&s);
            left = (Node*)pop(&s);
            insertNode(parent, right, left);
            pushNode(&s, parent);
        }
    }

    Node* root = (Node*)pop(&s);
    deleteStack(&s);
    return root;
}

Node* expressionTreeV2(char* infix) {
    char c;
    Node *parent, *left, *right;
    Stack operator; // 연산자 저장
    Stack operand;  // 피연산자 저장
    initStack(&operator);
    initStack(&operand);

    for (int i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        if (!isOperator(c) && c != '(' && c != ')') { // 피연산자인 경우
            pushNode(&operand, createNode(c));
        }
        else if (c == '(') { // 여는 괄호인 경우
            pushNode(&operator, createNode(c));
        }
        else if (c == ')') { // 닫는 괄호인 경우
            parent = (Node*)peek(&operator);
            while (!isEmpty(&operator) && parent->data != '(') {
                parent = (Node*)pop(&operator);
                right = (Node*)pop(&operand);
                left = (Node*)pop(&operand);
                insertNode(parent, right, left);
                pushNode(&operator, parent);
            }
            free(pop(&operator));
        }
        else { // 연산자인 경우
            if (!isEmpty(&operator)) {
                parent = (Node*)peek(&operator);
                while (!isEmpty(&operator) && precedence(parent->data) >= precedence(c)) {
                    parent = (Node*)pop(&operator);
                    right = (Node*)pop(&operand);
                    left = (Node*)pop(&operand);
                    insertNode(parent, right, left);
                    pushNode(&operator, parent);
                }
            }
            pushNode(&operator, createNode(c));
        }
    }

    while (!isEmpty(&operator)) {
        parent = (Node*)pop(&operator);
        right = (Node*)pop(&operand);
        left = (Node*)pop(&operand);
        insertNode(parent, right, left);
        pushNode(&operator, parent);
    }

    Node* root = (Node*)pop(&operand);
    deleteStack(&operator);
    deleteStack(&operand);
    return root;
}

void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    int j = 0;
    char c;
    char* cPtr;
    initStack(&s);

    for (int i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        if (isOperator(c)) {
            while (!isEmpty(&s) && precedence(*(char*)peek(&s)) >= precedence(c)) {
                cPtr = (char*)pop(&s);
                postfix[j++] = *cPtr;
                free(cPtr);
            }
            pushChar(&s, c);
        }
        else if (c == '(') {
            pushChar(&s, c);
        }
        else if (c == ')') {
            while (*(char*)peek(&s) != '(') {
                cPtr = (char*)pop(&s);
                postfix[j++] = *cPtr;
                free(cPtr);
            }
            free(pop(&s));
        }
        else {
            postfix[j++] = c;
        }
    }
    while (!isEmpty(&s)) {
        cPtr = (char*)pop(&s);
        postfix[j++] = *cPtr;
        free(cPtr);
    }
    deleteStack(&s);
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

// 괄호를 포함한 중위 표기법 출력
void infixOrder(Node* root) {
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

void prefixOrder(Node* root) {
    if (root != NULL) {
        printf("%c", root->data);
        prefixOrder(root->left);
        prefixOrder(root->right);
    }
}

void postfixOrder(Node* root) {
    if (root != NULL) {
        postfixOrder(root->left);
        postfixOrder(root->right);
        printf("%c", root->data);
    }
}

void levelOrder(Node* root) {
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

void deleteTree(Node* root) {
    if (root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        deleteNode(root);
    }
}
