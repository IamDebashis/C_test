//
// Created by debah on 16-06-2025.
//

#include "TreeQueue.h"
#include "TreeStack.h"

struct Node *root = NULL;

void createTree() {
    struct Node *temp, *p;
    char x;

    struct Queue q;
    createQueue(&q, 100);

    printf("Enter root value \n");
    scanf("%c", &x);

    root = (struct Node *) malloc(sizeof(struct Node));
    root->data = x;
    root->left = root->right = NULL;

    enqueue(&q, root);

    while (!isEmpty(&q)) {
        p = dequeue(&q);

        printf("Enter left child of %c", p->data);
        scanf(" %c", &x);
        if (x != 'x') {
            temp = (struct Node *) malloc(sizeof(struct Node));
            temp->data = x;
            temp->left = temp->right = NULL;
            p->left = temp;
            enqueue(&q, temp);
        }

        printf("Enter right child of %c", p->data);
        scanf(" %c", &x);
        if (x != 'x') {
            temp = (struct Node *) malloc(sizeof(struct Node));
            temp->data = x;
            temp->left = temp->right = NULL;
            p->right = temp;
            enqueue(&q, temp);
        }
    }
}


void preOrder(struct Node *p) {
    if (p) {
        printf("%c ", p->data);
        preOrder(p->left);
        preOrder(p->right);
    }
}

void inOrder(struct Node *p) {
    if (p) {
        inOrder(p->left);
        printf("%c ", p->data);
        inOrder(p->right);
    }
}

void postOrder(struct Node *p) {
    if (p) {
        postOrder(p->left);
        postOrder(p->right);
        printf("%c ", p->data);
    }
}

void iPreOrder(struct Node *p) {
    struct Stack s;
    initStack(&s, 100);

    while (p != NULL || !isEmptyStack(&s)) {
        if (p) {
            printf("%c ", p->data);
            push(&s, p);
            p = p->left;
        }else {
            p = pop(&s);
            p = p->right;
        }

    }
}

void iIneOrder(struct Node *p) {
    struct Stack s;
    initStack(&s, 100);

    while (p != NULL || !isEmptyStack(&s)) {
        if (p) {
            push(&s, p);
            p = p->left;
        }else {
            p = pop(&s);
            printf("%c ", p->data);
            p = p->right;
        }

    }
}

void main() {
    createTree();
    printf("preorder \n");
    iPreOrder(root);
    printf("preorder \n");
    preOrder(root);
    printf("\n inorder \n");
    inOrder(root);
    printf("\n postorder \n");
    postOrder(root);
}
