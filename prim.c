#include <stdio.h>

#define V 5
#define INF 99999

int min_key(int key[], int in_mst[]) {
    int min = INF, idx = -1;
    for (int v = 0; v < V; v++)
        if (!in_mst[v] && key[v] < min) {
            min = key[v];
            idx = v;
        }
    return idx;
}

void prim_mst(int g[V][V]) {
    int parent[V], key[V], in_mst[V] = {0};

    for (int i = 0; i < V; i++) key[i] = INF;
    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < V - 1; i++) {
        int u = min_key(key, in_mst);
        in_mst[u] = 1;

        for (int v = 0; v < V; v++)
            if (g[u][v] && !in_mst[v] && g[u][v] < key[v]) {
                parent[v] = u;
                key[v] = g[u][v];
            }
    }

    int cost = 0;
    printf("Edges in MST (u v w):\n");
    for (int v = 1; v < V; v++) {
        printf("%d %d %d\n", parent[v], v, g[v][parent[v]]);
        cost += g[v][parent[v]];
    }
    printf("Total cost of MST = %d\n", cost);
}

int main(void) {
    int g[V][V] = {
        { 0, 2, 0, 6, 0},
        { 2, 0, 3, 8, 5},
        { 0, 3, 0, 0, 7},
        { 6, 8, 0, 0, 9},
        { 0, 5, 7, 9, 0}
    };

    prim_mst(g);
    return 0;
}