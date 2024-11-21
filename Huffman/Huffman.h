#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "Node.h"
#include "Queue.h"

bool huffmanCoding(char str[]);
void huffmanTree(Node** node, char str[]);
char* huffmanEncode(char str[], Node *huffman);
char* huffmanDecode(char encoded[], Node *huffman);

#endif
