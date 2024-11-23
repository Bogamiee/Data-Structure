#include "Huffman.h"

bool huffmanCoding(char str[]) {
    Node* huffman = NULL;
    char encoded[1024] = {'\0'}; // Output buffer for the encoded string.

    huffmanTree(&huffman, str);

    if (huffman == NULL) {
        printf("huffman is NULL\n");
        return false;
    }

    // Encoding
    huffmanEncode(str, encoded, huffman);
    if (encoded[0] == '\0') {
        deleteNode(huffman);
        return false;
    }
    printf("encoded: %s\n", encoded);

    // Decoding
    char* decoded = huffmanDecode(encoded, huffman);
    if (decoded == NULL) {
        deleteNode(huffman);
        return false;
    }
    printf("decoded: %s\n", decoded);

    // Free resources
    free(decoded);
    deleteNode(huffman);

    return true;
}

void huffmanTree(Node** huffman, char str[]) {
    int freq[256] = {0};
    for (int i = 0; str[i] != '\0'; i++)
        freq[(int)str[i]]++;

    int count = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) count++;
    }

    Node* nodes = (Node*) malloc(count * sizeof(Node));
    if (nodes == NULL) return;

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

    Queue nodeQueue;
    initQueue(&nodeQueue);
    for (int i = 0; i < count; i++)
        enqueue(&nodeQueue, createNode(nodes[i].freq, nodes[i].ch));
    
    free(nodes);

    while (queueSize(&nodeQueue) > 1) {
        Node* left = dequeue(&nodeQueue);
        Node* right = dequeue(&nodeQueue);
        Node* parent = createNode(left->freq + right->freq, '\0');
        linkNodes(parent, left, right);
        enqueue(&nodeQueue, parent);
    }

    *huffman = dequeue(&nodeQueue);

    deleteQueue(&nodeQueue);
}

void huffmanEncode(char str[], char encoded[], Node* huffman) {
    char* codeMap[256] = {NULL};
    char code[256] = {'\0'};
    createCode(huffman, codeMap, code, 0);

    encoded[0] = '\0'; // Ensure encoded starts empty.
    for (int i = 0; str[i] != '\0'; i++) {
        if (codeMap[(int)str[i]] != NULL) {
            strcat(encoded, codeMap[(int)str[i]]);
        }
    }

    // Free the codeMap memory
    for (int i = 0; i < 256; i++) {
        if (codeMap[i] != NULL) {
            free(codeMap[i]);
        }
    }
}

void createCode(Node* node, char* codeMap[], char code[], int index) {
    if (node == NULL) return;

    if (node->left == NULL && node->right == NULL) {
        code[index] = '\0';
        codeMap[(int)node->ch] = strdup(code);
        return;
    }

    code[index] = '0';
    createCode(node->left, codeMap, code, index + 1);

    code[index] = '1';
    createCode(node->right, codeMap, code, index + 1);
}

char* huffmanDecode(char encoded[], Node* huffman) {
    if (huffman == NULL) return NULL;

    char* decoded = (char*) malloc(1024 * sizeof(char)); // Adjust size as needed.
    int decodedIndex = 0;

    Node* current = huffman;
    for (int i = 0; encoded[i] != '\0'; i++) {
        if (encoded[i] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (current->left == NULL && current->right == NULL) {
            decoded[decodedIndex++] = current->ch;
            current = huffman;
        }
    }

    decoded[decodedIndex] = '\0';
    return decoded;
}
