#include "Huffman.h"

bool huffmanCoding(char str[]) {
    Node* huffman = NULL;
    huffmanTree(&huffman, str);

    if (huffman == NULL) {
        printf("huffman is NULL\n");
        return false;
    }
/*
    char* encoded = huffmanEncode(str, huffman);

    if (encoded == NULL) {
        return false;
    }
    printf("encoded: %s\n", encoded);

    char* decoded = huffmanDecode(encoded, huffman);

    if (decoded == NULL) {
        return false;
    }
    printf("decoded: %s\n", decoded);
*/
    deleteNode(huffman);

    return true;
}

void huffmanTree(Node** huffman, char str[]) {
    // count frequency of each character
    int freq[256] = {0};
    for (int i = 0; str[i] != '\0'; i++)
        freq[(int)str[i]]++;

    // count number of unique characters
    int count = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) count++;
    }

    // create a node array
    Node* nodes = (Node*) malloc(count * sizeof(Node));
    if (nodes == NULL) return;

    // create a node for each character
    int j = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            nodes[j].ch = i;
            nodes[j].freq = freq[i];
            nodes[j].left = NULL;
            nodes[j].right = NULL;
            j++;
        }
    }

    // create queue and enqueue nodes
    Queue nodeQueue;
    initQueue(&nodeQueue);
    for (int i = 0; i < count; i++)
        enqueue(&nodeQueue, createNode(nodes[i].freq, nodes[i].ch));
    
    // free nodes array
    free(nodes);

    // build huffman tree
    while (queueSize(&nodeQueue) > 1) {
        Node* left = dequeue(&nodeQueue);
        Node* right = dequeue(&nodeQueue);
        Node* parent = createNode(left->freq + right->freq, '\0');
        linkNodes(parent, left, right);
        enqueue(&nodeQueue, parent);
    }

    *huffman = dequeue(&nodeQueue);

    // delete nodes queue
    deleteQueue(&nodeQueue);
}

char* huffmanEncode(char str[], Node *huffman) {
    return NULL;
}

char* huffmanDecode(char encoded[], Node *huffman) {
    return NULL;
}
