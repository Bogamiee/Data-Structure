#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "Node.h"
#include "Queue.h"

bool huffmanCoding(char str[]);
void huffmanTree(Node** node, char str[]);
void huffmanEncode(char str[], char encoded[], Node *huffman);
void createCode(Node* node, char* codeMap[], char code[], int index);
char* huffmanDecode(char encoded[], Node *huffman);

#endif
