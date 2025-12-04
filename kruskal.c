#include <stdio.h>

#define V 4
#define E 5

typedef struct {
    int u, v, w;
} Edge;

Edge edges[E] = {
    {0, 1, 10},
    {0, 2, 6},
    {0, 3, 5},
    {1, 3, 15},
    {2, 3, 4}
};

int parent[V];

int find(int x) {
    while (parent[x] != x) x = parent[x];
    return x;
}

void union_set(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}

void sort_edges() {
    for (int i = 0; i < E - 1; i++)
        for (int j = 0; j < E - 1 - i; j++)
            if (edges[j].w > edges[j+1].w) {
                Edge tmp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = tmp;
            }
}

void kruskal_mst() {
    int cost = 0, count = 0;

    for (int i = 0; i < V; i++) parent[i] = i;
    sort_edges();

    printf("Edges in MST (u v w):\n");
    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (find(u) != find(v)) {
            union_set(u, v);
            printf("%d %d %d\n", u, v, w);
            cost += w;
            count++;
        }
    }
    printf("Total cost of MST = %d\n", cost);
}

int main(void) {
    kruskal_mst();
    return 0;
}