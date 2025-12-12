#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node n1, n2, n3, n4;
    struct Node *top = NULL;   // stack top

    // Assign values
    n1.data = 10;
    n2.data = 20;
    n3.data = 30;
    n4.data = 40;

    // PUSH operations (insert at beginning)
    n1.next = top;   // first push
    top = &n1;

    n2.next = top;   // second push
    top = &n2;

    n3.next = top;   // third push
    top = &n3;

    n4.next = top;   // fourth push
    top = &n4;

    // DISPLAY USING FOR LOOP
    printf("Stack: ");
    struct Node *t;
    for (t = top; t != NULL; t = t->next) {
        printf("%d ", t->data);
    }


    return 0;
}
