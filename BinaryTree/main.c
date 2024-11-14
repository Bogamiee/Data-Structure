// main.c

#include "Stack.h"
#include "BinaryTree.h"

int main() {
    char infix[100] = "(1+2)*(3+4)";
    char postfix[100] = "";
    Node *root;
/*
    printf("Enter an infix expression: ");
    scanf("%s", infix);
*/  
    infixToPostfix(infix, postfix);

    printf("Infix: %s\n", infix);
    printf("Postfix: %s\n", postfix);

    //root = expressionTree(postfix);
    root = expressionTreeV2(infix);

    printf("Infix order: ");
    infixOrder(root);
    printf("\n");

    printf("Prefix order: ");
    prefixOrder(root);
    printf("\n");

    printf("Postfix order: ");
    postfixOrder(root);
    printf("\n");

    printf("Level order: ");
    levelOrder(root);
    printf("\n");

    deleteTree(root);

    return 0;
}
