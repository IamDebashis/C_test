//
// Created by debah on 17-06-2025.
//
#include <stddef.h>
#include <stdlib.h>

struct Node {
    struct Node *left, *right;
    int data;
    int height;
};

struct Node *p = NULL;

struct Node* RInsert(struct Node* p,int key);





struct Node* RInsert(struct Node* p,int key) {
    struct Node* temp;
    if (p == NULL) {
        temp =(struct Node *) malloc(sizeof(struct Node));
        temp->data = key;
        temp->left = temp->right = NULL;
        temp->height = 1;
    }
    if (key < p->data) {
        p->left = RInsert(p->left,key);
    } else if (key > p->data) {
        p->right = RInsert(p->right,key);
    }
    return p;
}