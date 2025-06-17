//
// Created by debah on 16-06-2025.
//

#ifndef TREE_H
#define TREE_H
#include <stdio.h>
#include <stdlib.h>
#include "TreeNode.h"




struct Queue {
    int size;
    int front;
    int rear;
    struct Node **nodes;
};

void createQueue(struct Queue *q, int size) {
    q->size = size;
    q->front = q->rear = -1;
    q->nodes = (struct Node **) malloc(q->size * sizeof(struct Node *));
}

int isFull(struct Queue *q) {
    return q->rear == q->size - 1;
}

int isEmpty(struct Queue *q) {
    return q->front == -1;
}

void enqueue(struct Queue *q, struct Node *node) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) { q->front = 0; }

    q->nodes[++q->rear] = node;
}

struct Node *dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return NULL;
    }

    struct Node *node = q->nodes[q->front];
    if (q->front == q->rear) {
        // Reset queue after last element
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return node;
}


#endif //TREE_H
