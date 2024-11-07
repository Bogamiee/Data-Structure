#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BinaryTree.h"

typedef struct Queue {
    Node** data;
    int capacity;
    int front;
    int rear;
} Queue;

void initQueue(Queue *q);
void enqueue(Queue *q, Node* item);
Node* dequeue(Queue *q);
Node* peekQueue(Queue *q);
bool isQueueEmpty(Queue *q);
bool isQueueFull(Queue *q);
void deleteQueue(Queue *q);

#endif
