#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

typedef struct queueNode {
    Node* node;
    struct queueNode* next;
} QueueNode;

typedef struct queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

void initQueue(Queue *q);
bool isQueueEmpty(Queue *q);
void enqueue(Queue *q, Node *n);
Node* dequeue(Queue *q);
Node* peekQueue(Queue *q);
int queueSize(Queue *q);
void deleteQueue(Queue *q);

#endif
