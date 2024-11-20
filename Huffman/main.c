#include "Queue.h"
#include "Tree.h"
#include "Huffman.h"

int main() {
    char str[] = "helloworldmynamesjeff";
    //char str[] = "thisisanexampleofahuffmancodetestwherewewanttocompressacharacterstringefficientlywithminimalspace";

    //char str[] = "a";
    printf("Original string: %s\n", str);

    Node* root = huffmanTree(str);

    return 0;
}
