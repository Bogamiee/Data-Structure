#include "Stack.h"
#include "Queue.h"
#include "Tree.h"
#include "Calc.h"

int main() {
    char infix[100] = "";

    printf("Enter infix expression: ");
    scanf("%s", infix);

    printf("Original Infix: %s\n\n", infix);

    Node* root = infixToBinaryTree(infix);

    printf("Infix: ");
    printInfix(root);

    printf("\nPrefix: ");
    printPrefix(root);

    printf("\nPostfix: ");
    printPostfix(root);
    
    printf("\nLevel: ");
    printLevel(root);

    printf("\n");

    freeTree(root);
    
    return 0;
}
