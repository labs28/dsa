#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void enqueue(Node **front, Node **rear, int x) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = x;
    n->next = NULL;

    if (*rear == NULL) {
        *front = *rear = n;
    } else {
        (*rear)->next = n;
        *rear = n;
    }
}

int dequeue(Node **front, Node **rear, int *out) {
    if (*front == NULL) return 0;
    Node *t = *front;
    *out = t->data;
    *front = t->next;
    if (*front == NULL) *rear = NULL;
    free(t);
    return 1;
}

void display(Node *front) {
    printf("Queue (front->rear): ");
    for (; front; front = front->next) printf("%d ", front->data);
    printf("\n");
}

int main(void) {
    Node *front = NULL, *rear = NULL;
    int x;

    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    display(front);

    if (dequeue(&front, &rear, &x)) printf("Dequeued: %d\n", x);
    display(front);

    while (dequeue(&front, &rear, &x)) { }
    return 0;
}