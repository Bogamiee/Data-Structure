#include "Node.h"
#include "Huffman.h"
#include "Queue.h"
#include "QuickSort.h"

int main() {
    char str[] = "ABBCCCDDDDEEEEEFFFFFF";
    //char str[] = "AAAAAAABBCCCDEEEEFFFFFFG";
    huffmanCoding(str);

    return 0;
}
