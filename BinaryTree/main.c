// main.c

#include "Stack.h"
#include "BinaryTree.h"

int main() {
    char infix[] = "(2+3)*4+9";
    char postfix[100];
    
    infixToPostfix(infix, postfix);

    expressionTree(postfix);
    return 0;
}
