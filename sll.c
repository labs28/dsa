#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void insert_front(Node **head, int x) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = x;
    n->next = *head;
    *head = n;
}

void insert_back(Node **head, int x) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = x;
    n->next = NULL;
    if (*head == NULL) { *head = n; return; }
    Node *p = *head;
    while (p->next) p = p->next;
    p->next = n;
}

int delete_value(Node **head, int x) {
    Node *p = *head, *prev = NULL;
    while (p) {
        if (p->data == x) {
            if (prev) prev->next = p->next;
            else      *head = p->next;
            free(p);
            return 1;
        }
        prev = p;
        p = p->next;
    }
    return 0;
}

void display(Node *head) {
    printf("List: ");
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(void) {
    Node *head = NULL;

    insert_front(&head, 20);
    insert_front(&head, 10);
    insert_back(&head, 30);
    insert_back(&head, 40);
    display(head);

    delete_value(&head, 20);
    display(head);

    delete_value(&head, 10);
    display(head);

    while (head) {
        Node *t = head;
        head = head->next;
        free(t);
    }
    return 0;
}
