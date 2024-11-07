#include "Queue.h"

void initQueue(Queue *q) {
    q->capacity = 16;
    q->front = 0;
    q->rear = 0;
    q->data = (Node**)malloc(sizeof(Node*) * q->capacity);
    if (q->data == NULL) {
        fprintf(stderr, "Memory allocation failed in initQueue()\n");
        exit(1);
    }
}

void enqueue(Queue *q, Node* item) {
    if (isQueueFull(q)) {
        q->capacity *= 2;
        q->data = (Node**)realloc(q->data, sizeof(Node*) * q->capacity);
        if (q->data == NULL) {
            fprintf(stderr, "Memory allocation failed in enqueue()\n");
            exit(1);
        }
    }
    q->data[q->rear] = item;
    q->rear = (q->rear + 1) % q->capacity;
}

Node* dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        fprintf(stderr, "Queue is empty in dequeue()\n");
        exit(1);
    }
    Node* item = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    return item;
}

Node* peekQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        fprintf(stderr, "Queue is empty in peek()\n");
        exit(1);
    }
    return q->data[q->front];
}

bool isQueueEmpty(Queue *q) {
    return q->front == q->rear;
}

bool isQueueFull(Queue *q) {
    return (q->rear + 1) % q->capacity == q->front;
}

void deleteQueue(Queue *q) {
    free(q->data);
}
