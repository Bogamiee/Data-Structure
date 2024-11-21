#include "QuickSort.h"

void quickSort(Node nodes[], int low, int high) {
    if (low < high) {
        int pi = partition(nodes, low, high);
        quickSort(nodes, low, pi - 1);
        quickSort(nodes, pi + 1, high);
    }
}

int partition(Node nodes[], int low, int high) {
    int pivot = nodes[high].freq;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (nodes[j].freq < pivot) {
            i++;
            swap(&nodes[i], &nodes[j]);
        }
    }
    swap(&nodes[i + 1], &nodes[high]);
    return i + 1;
}

void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}
