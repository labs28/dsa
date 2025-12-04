#include <stdio.h>

#define V 5

int adj[V][V];

void add_edge(int u, int v) {
    adj[u][v] = adj[v][u] = 1;
}

void bfs(int start) {
    int visited[V] = {0};
    int q[V], front = 0, rear = -1;

    visited[start] = 1;
    q[++rear] = start;

    printf("BFS: ");
    while (front <= rear) {
        int u = q[front++];
        printf("%d ", u);
        for (int v = 0; v < V; v++)
            if (adj[u][v] && !visited[v]) {
                visited[v] = 1;
                q[++rear] = v;
            }
    }
    printf("\n");
}

void dfs_util(int u, int visited[]) {
    visited[u] = 1;
    printf("%d ", u);
    for (int v = 0; v < V; v++)
        if (adj[u][v] && !visited[v])
            dfs_util(v, visited);
}

void dfs(int start) {
    int visited[V] = {0};
    printf("DFS: ");
    dfs_util(start, visited);
    printf("\n");
}

int main(void) {
    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(1, 3);
    add_edge(2, 3);
    add_edge(3, 4);

    bfs(0);
    dfs(0);

    return 0;
}