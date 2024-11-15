#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Tree.h"

typedef struct Queue {
    Node** data;
    int capacity;
    int front;
    int rear;
} Queue;

void initQueue(Queue *q);
bool isQueueEmpty(Queue *q);
bool isQueueFull(Queue *q);
void enqueue(Queue *q, Node *n);
Node* dequeue(Queue *q);
Node* peekQueue(Queue *q);
int queueSize(Queue *q);
void freeQueue(Queue *q);

#endif
