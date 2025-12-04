#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

void push_front(Node **head, int x){
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = x; n->prev = NULL; n->next = *head;
    if (*head) (*head)->prev = n;
    *head = n;
}

void push_back(Node **head, int x){
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = x; n->next = NULL;
    if (!*head){ n->prev = NULL; *head = n; return; }
    Node *t = *head; while (t->next) t = t->next;
    t->next = n; n->prev = t;
}

int delete_first(Node **head, int x){
    for (Node *t = *head; t; t = t->next){
        if (t->data == x){
            if (t->prev) t->prev->next = t->next; else *head = t->next;
            if (t->next) t->next->prev = t->prev;
            free(t); return 1;
        }
    }
    return 0;
}

void print_forward(Node *h){ for (; h; h=h->next) printf("%d ", h->data); printf("\n"); }
void print_backward(Node *h){
    if (!h){ printf("\n"); return; }
    while (h->next) h = h->next;
    for (; h; h=h->prev) printf("%d ", h->data); printf("\n");
}

void free_all(Node *h){ while (h){ Node *t=h; h=h->next; free(t);} }

int main(void){
    Node *head = NULL;
    push_front(&head, 20);
    push_front(&head, 10);
    push_back (&head, 30);
    push_back (&head, 40);

    printf("Forward : ");  print_forward(head);
    printf("Backward: ");  print_backward(head);

    delete_first(&head, 20);
    printf("After deleting 20\nForward : "); print_forward(head);
    printf("Backward: ");  print_backward(head);

    free_all(head);
    return 0;
}
