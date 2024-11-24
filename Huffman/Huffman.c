#include "Huffman.h"

bool huffmanCoding(char str[]) {
    Node* huffman = NULL;
    char* encoded = NULL; // Output buffer for the encoded string.

    huffmanTree(&huffman, str);

    if (huffman == NULL) {
        printf("huffman is NULL\n");
        return false;
    }

    // Encoding
    huffmanEncode(str, &encoded, huffman);
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
    free(encoded);
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

// Malloc
void huffmanEncode(char str[], char** encoded, Node* huffman) {
    char* codeMap[256] = {NULL}; // 최대 256개의 문자
    char code[256] = {'\0'};
    createCode(huffman, codeMap, code, 0);

    // 모든 문자의 인코딩 정보 출력
    printf("Character Encodings:\n");
    for (int i = 0; i < 256; i++) {
        if (codeMap[i] != NULL) {
            printf("'%c': %s\n", (char)i, codeMap[i]);
        }
    }

    size_t capacity = 32;  // 초기 용량
    size_t length = 0;     // 인코딩된 문자열의 현재 길이
    *encoded = (char*)malloc(capacity * sizeof(char));
    if (*encoded == NULL) return;

    (*encoded)[0] = '\0'; // 인코딩 결과를 빈 문자열로 초기화

    for (int i = 0; str[i] != '\0'; i++) {
        if (codeMap[(int)str[i]] != NULL) {
            size_t codeLength = strlen(codeMap[(int)str[i]]);
            if (length + codeLength + 1 > capacity) {
                // 용량 초과 시 두 배로 증가
                capacity *= 2;
                *encoded = (char*)realloc(*encoded, capacity * sizeof(char));
                if (*encoded == NULL) return;
            }
            strcat(*encoded, codeMap[(int)str[i]]);
            length += codeLength;
        }
    }

    // 메모리 해제
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
        codeMap[(int)node->ch] = (char*) malloc((strlen(code) + 1) * sizeof(char));
        strcpy(codeMap[(int)node->ch], code);
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
