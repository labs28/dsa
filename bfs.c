#include <stdio.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

// Enqueue function
void enqueue(int v) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}

// Dequeue function
int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

int main() {
    int graph[MAX][MAX];
    int visited[MAX];
    int n, start;

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // Choose starting vertex
    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    // BFS Algorithm
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front != -1 && front <= rear) {
        int node = dequeue();
        printf("%d ", node);

        // Visit adjacent nodes
        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    printf("\n");
    return 0;
}
