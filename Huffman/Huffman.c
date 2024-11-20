#include "Huffman.h"

Node* huffmanTree(const char *str) {
    Queue q;
    int freq[256] = {0};
    int size = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        freq[(int)str[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        if (freq[i]) {
            size++;
        }
    }

    printf("Size: %d\n", size);
    Node nodeArray[size];

    for (int i = 0, j = 0; i < 256; i++) {
        if (freq[i]) {
            nodeArray[j].symbol = (char)i;
            nodeArray[j].frequency = freq[i];
            nodeArray[j].left = NULL;
            nodeArray[j].right = NULL;
            j++;
        }
    }

    qsortArray(nodeArray, 0, size - 1);
    initQueue(&q);
    
    for (int i = 0; i < size; i++) {
        enqueue(&q, &nodeArray[i]);
    }

    while (queueSize(&q) > 1) {
        Node* left = dequeue(&q);
        Node* right = dequeue(&q);
        Node* parent = createNode('\0', left->frequency + right->frequency);
        linkNodes(parent, left, right);
        enqueue(&q, parent);
    }
    
    Node* root = dequeue(&q);
    freeQueue(&q);
    freeTree(root);

    return NULL;
}

void qsortArray(Node nodeArray[], int p, int r) {
    int q;

    if (p < r) {
        q = partition(nodeArray, p, r);
        qsortArray(nodeArray, p, q - 1);
        qsortArray(nodeArray, q + 1, r);
    }
}

int partition(Node nodeArray[], int p, int r) {
    int x = nodeArray[r].frequency;
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (nodeArray[j].frequency <= x) {
            i++;
            swap(&nodeArray[i], &nodeArray[j]);
        }
    }

    swap(&nodeArray[i + 1], &nodeArray[r]);

    return i + 1;
}

void swap(Node* a, Node* b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void encoding(Node* root, char* code, const char *str) {
}
