#ifndef CAL_H
#define CAL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Stack.h"
#include "Queue.h"
#include "Tree.h"

Node* infixToBinaryTree(char* infix);
bool compare(char op1, char op2);
bool isOperator(char c);
void printInfix(Node* root);
void printPostfix(Node* root);
void printPrefix(Node* root);
void printLevel(Node* root);
int evaluateInfix(Node* root);
int evaluatePrefix(Node* root);
int evaluatePostfix(Node* root);
int evaluateLevel(Node* root);


#endif
