#include <stdio.h>

struct Node {
	int data;
	struct Node *next;
};

int main() {
	struct Node n1, n2, n3, n4;
	struct Node *front = NULL;
	struct Node *rear = NULL;

	// Assign values and ENQUEUE
	n1.data = 10;
	n1.next = NULL;
	front = rear = &n1;
	n2.data = 20;
	n2.next = NULL;
	rear->next = &n2;
	rear = &n2;
	n3.data = 30;
	n3.next = NULL;
	rear->next = &n3;
	rear = &n3;
	n4.data = 40;
	n4.next = NULL;
	rear->next = &n4;
	rear = &n4;

	// DISPLAY
	printf("Queue: ");
	for (struct Node *t = front; t; t = t->next)
		printf("%d ", t->data);

	return 0;
}
