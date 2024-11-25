#include "Queue.h"

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
    q->capacity = 16;
    q->data = (Node**)malloc(q->capacity * sizeof(Node*));
    if (q->data == NULL) {
        fprintf(stderr, "Memory allocation failed in initQueue()\n");
        exit(1);
    }
}

bool isQueueEmpty(Queue *q) {
    return q->front == q->rear;
}

bool isQueueFull(Queue *q) {
    return (q->rear + 1) % q->capacity == q->front;
}

void enqueue(Queue *q, Node *n) {
    if (isQueueFull(q)) {
        q->capacity *= 2;
        q->data = (Node**)realloc(q->data, q->capacity * sizeof(Node*));
        if (q->data == NULL) {
            fprintf(stderr, "Memory allocation failed in enqueue()\n");
            exit(1);
        }
    }
    q->data[q->rear] = n;
    q->rear = (q->rear + 1) % q->capacity;
}

Node* dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        fprintf(stderr, "Queue is empty in dequeue()\n");
        exit(1);
    }
    Node* n = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    return n;
}

Node* peekQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        fprintf(stderr, "Queue is empty in peekQueue()\n");
        exit(1);
    }
    return q->data[q->front];
}

void freeQueue(Queue *q) {
    free(q->data);
    q->front = 0;
    q->rear = 0;
    q->capacity = 0;
}
