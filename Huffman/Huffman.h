#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Queue.h"
#include "Tree.h"

Node* huffmanTree(const char *str);
void qsortArray(Node nodeArray[], int p, int r);
int partition(Node nodeArray[], int p, int r);
void swap(Node* a, Node* b);
void encoding(Node* root, char* code, const char *str);

#endif
