#include "Stack.h"
#include "Queue.h"
#include "Tree.h"
#include "Cal.h"

int main() {
    char infix[100] = "";

    printf("중위 표기식을 입력하세요: ");
    scanf("%s", infix);

    Node* root = infixToBinaryTree(infix);

    printf("중위 표기: ");
    printInfix(root);
    printf(" = %d\n", evaluateInfix(root));

    printf("전위 표기: ");
    printPrefix(root);
    printf(" = %d\n", evaluatePrefix(root));

    printf("후위 표기: ");
    printPostfix(root);
    printf(" = %d\n", evaluatePostfix(root));

    printf("레벨 순회: ");
    printLevel(root);
    

    freeTree(root);

    return 0;
}
