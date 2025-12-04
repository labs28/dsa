#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insert_end(Node **tail, int x) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = x;
    if (*tail == NULL) {
        n->next = n;
        *tail = n;
    } else {
        n->next = (*tail)->next;
        (*tail)->next = n;
        *tail = n;
    }
}

int delete_value(Node **tail, int x) {
    if (*tail == NULL) return 0;
    Node *cur = (*tail)->next;
    Node *prev = *tail;
    do {
        if (cur->data == x) {
            if (cur == prev) {
                *tail = NULL;
            } else {
                prev->next = cur->next;
                if (cur == *tail) *tail = prev;
            }
            free(cur);
            return 1;
        }
        prev = cur;
        cur = cur->next;
    } while (cur != (*tail)->next);
    return 0;
}

void display(Node *tail) {
    if (!tail) { printf("(empty)\n"); return; }
    Node *p = tail->next;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != tail->next);
    printf("\n");
}

void free_all(Node **tail) {
    if (!*tail) return;
    Node *head = (*tail)->next, *p = head;
    do {
        Node *t = p;
        p = p->next;
        free(t);
    } while (p != head);
    *tail = NULL;
}

int main(void) {
    Node *tail = NULL;

    insert_end(&tail, 10);
    insert_end(&tail, 20);
    insert_end(&tail, 30);
    printf("List: ");
    display(tail);

    delete_value(&tail, 20);
    printf("After deleting 20: ");
    display(tail);

    delete_value(&tail, 10);
    delete_value(&tail, 30);
    printf("After deleting all: ");
    display(tail);

    free_all(&tail);
    return 0;
}
