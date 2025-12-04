#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void push(Node **top, int x) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = x;
    n->next = *top;
    *top = n;
}

int pop(Node **top, int *out) {
    if (*top == NULL) return 0;
    Node *t = *top;
    *out = t->data;
    *top = t->next;
    free(t);
    return 1;
}

void display(Node *top) {
    printf("Stack (top->bottom): ");
    for (; top; top = top->next) printf("%d ", top->data);
    printf("\n");
}

int main(void) {
    Node *top = NULL;
    int x;

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    display(top);

    if (pop(&top, &x)) printf("Popped: %d\n", x);
    display(top);

    while (pop(&top, &x)) { }
    return 0;
}