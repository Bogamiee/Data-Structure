#include "Queue.h"

void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

bool isQueueEmpty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, Node *n) {
    QueueNode* queueNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (queueNode == NULL) {
        fprintf(stderr, "Memory allocation failed in enqueue()\n");
        exit(1);
    }

    queueNode->node = n;
    queueNode->next = NULL;

    if (isQueueEmpty(q)) {
        q->front = queueNode;
        q->rear = queueNode;
        return;
    }

    QueueNode *prev = NULL;
    QueueNode *curr = q->front;

    // locate the node at right position, based on frequency
    while (curr != NULL && curr->node->freq < n->freq) {
        prev = curr;
        curr = curr->next;
    }

    if (prev == NULL) {
        queueNode->next = q->front;
        q->front = queueNode;
    }
    else {
        prev->next = queueNode;
        queueNode->next = curr;
        if (curr == NULL) {
            q->rear = queueNode;
        }
    }
}

Node* dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        return NULL;
    }

    QueueNode* temp = q->front;
    Node* n = temp->node;
    q->front = q->front->next;
    free(temp);

    return n;
}

Node* peekQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        return NULL;
    }

    return q->front->node;
}

int queueSize(Queue *q) {
    int size = 0;
    QueueNode* curr = q->front;
    while (curr != NULL) {
        size++;
        curr = curr->next;
    }

    return size;
}

void deleteQueue(Queue *q) {
    while (!isQueueEmpty(q)) {
        Node* n = dequeue(q);
        deleteNode(n);
    }
}
