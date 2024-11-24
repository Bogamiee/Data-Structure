#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "Node.h"
#include "Queue.h"

// Main Huffman coding function that builds the tree, encodes, and decodes a string.
bool huffmanCoding(char str[]);

// Builds the Huffman tree from the input string.
void huffmanTree(Node** huffman, char str[]);

// Encodes the input string using the provided Huffman tree.
void huffmanEncode(char str[], char* encoded[], Node* huffman);

// Recursively creates Huffman codes for all characters and stores them in the codeMap.
void createCode(Node* node, char* codeMap[], char code[], int index);

void printCodeMap(char* codeMap[]);

// Decodes the encoded string using the provided Huffman tree.
char* huffmanDecode(char encoded[], Node* huffman);


#endif // HUFFMAN_H
