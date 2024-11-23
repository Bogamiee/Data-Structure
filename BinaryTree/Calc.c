#include "Cal.h"

Node* infixToBinaryTree(char* infix) {
    char c;
    Stack nodeStack;    // Stack to store the nodes
    Stack opStack;      // Stack to store the operators( 뿰 궛 옄)
    initStack(&nodeStack);
    initStack(&opStack);
    
    for (int i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        if (c == '(') { // If the character is an opening parenthesis, push it to the operator stack
            pushStack(&opStack, createNode(c));
        }
        else if (c == ')') { // If the character is a closing parenthesis, pop the operator stack until the opening parenthesis is found
            while (peekStack(&opStack)->data != '(') {
                Node *op = popStack(&opStack);
                Node *right = popStack(&nodeStack);
                Node *left = popStack(&nodeStack);
                linkNodes(op, left, right); // Link the operator to the left and right children
                pushStack(&nodeStack, op); // Push the linked operator to the node stack
            }
            freeNode(popStack(&opStack)); // Pop the opening parenthesis
        }
        else if (isOperator(c)) { // If the character is an operator
            while (!isStackEmpty(&opStack) && compare(peekStack(&opStack)->data, c)) { // Pop the operator stack until the top of the stack has a lower precedence
                Node *op = popStack(&opStack);
                Node *right = popStack(&nodeStack);
                Node *left = popStack(&nodeStack);
                linkNodes(op, left, right);
                pushStack(&nodeStack, op); // Push the linked operator to the node stack
            }
            pushStack(&opStack, createNode(c)); // Push the current operator to the operator stack
        }
        else { // If the character is an operand( 뵾 뿰 궛 옄), push it to the node stack
            pushStack(&nodeStack, createNode(c));
        }
    }

    while (!isStackEmpty(&opStack)) { // Pop the remaining operators in the operator stack
        Node *op = popStack(&opStack);
        Node *right = popStack(&nodeStack);
        Node *left = popStack(&nodeStack);
        linkNodes(op, left, right);
        pushStack(&nodeStack, op);
    }

    Node *root = popStack(&nodeStack);
    freeStack(&nodeStack);
    freeStack(&opStack);
    return root;
}

bool compare(char op1, char op2) { // Compare the precedence of two operators
    int precedence1 = (op1 == '+' || op1 == '-') ? 1 :
                      (op1 == '*' || op1 == '/') ? 2 : 0;
    int precedence2 = (op2 == '+' || op2 == '-') ? 1 :
                      (op2 == '*' || op2 == '/') ? 2 : 0;

    return precedence1 >= precedence2;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void printInfix(Node* root) {
    if (root != NULL) {
        if (isOperator(root->data)) {
            printf("(");
        }
        printInfix(root->left);
        printf("%c", root->data);
        printInfix(root->right);
        if (isOperator(root->data)) {
            printf(")");
        }
    }
}

void printPostfix(Node* root) {
    if (root != NULL) {
        printPostfix(root->left);
        printPostfix(root->right);
        printf("%c", root->data);
    }
}

void printPrefix(Node* root) {
    if (root != NULL) {
        printf("%c", root->data);
        printPrefix(root->left);
        printPrefix(root->right);
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

int evaluateInfix(Node* root) {
    if (root == NULL) return 0;

    if (!isOperator(root->data)) {
        return root->data - '0'; // 피연산자를 정수로 변환
    }

    int leftValue = evaluateInfix(root->left);
    int rightValue = evaluateInfix(root->right);

    switch (root->data) {
        case '+': return leftValue + rightValue;
        case '-': return leftValue - rightValue;
        case '*': return leftValue * rightValue;
        case '/': return leftValue / rightValue;
        default: return 0;
    }
}

int evaluatePrefix(Node* root) {
    if (root == NULL) return 0;

    if (!isOperator(root->data)) {
        return root->data - '0';
    }

    int leftValue = evaluatePrefix(root->left);
    int rightValue = evaluatePrefix(root->right);

    switch (root->data) {
        case '+': return leftValue + rightValue;
        case '-': return leftValue - rightValue;
        case '*': return leftValue * rightValue;
        case '/': return leftValue / rightValue;
        default: return 0;
    }
}

int evaluatePostfix(Node* root) {
    if (root == NULL) return 0;

    if (!isOperator(root->data)) {
        return root->data - '0';
    }

    int leftValue = evaluatePostfix(root->left);
    int rightValue = evaluatePostfix(root->right);

    switch (root->data) {
        case '+': return leftValue + rightValue;
        case '-': return leftValue - rightValue;
        case '*': return leftValue * rightValue;
        case '/': return leftValue / rightValue;
        default: return 0;
    }
}

int evaluateLevel(Node* root) {
    if (root == NULL) return 0;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isQueueEmpty(&q)) {
        Node* node = dequeue(&q);

        // 숫자 노드는 정수로 변환
        if (!isOperator(node->data)) {
            node->data = node->data - '0';  // 문자형 숫자를 정수로 변환
        } else {
            // 연산자 노드가 두 자식(피연산자)을 모두 가질 때만 처리
            if (node->left && node->right &&
                !isOperator(node->left->data) && !isOperator(node->right->data)) {

                int leftValue = node->left->data;
                int rightValue = node->right->data;

                // 연산자에 따라 계산
                switch (node->data) {
                    case '+': node->data = leftValue + rightValue; break;
                    case '-': node->data = leftValue - rightValue; break;
                    case '*': node->data = leftValue * rightValue; break;
                    case '/': node->data = leftValue / rightValue; break;
                    default: break;
                }
            }
        }

        // 자식 노드를 큐에 삽입
        if (node->left) enqueue(&q, node->left);
        if (node->right) enqueue(&q, node->right);
    }

    // 최종 결과는 루트 노드에 저장되므로 루트 값을 반환
    return root->data;
}

