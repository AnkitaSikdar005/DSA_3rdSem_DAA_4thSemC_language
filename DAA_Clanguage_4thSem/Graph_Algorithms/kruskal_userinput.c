#include <stdio.h>

#define MAX 10

typedef struct {
    int u, v, w;
} Edge;

typedef struct {
    int parent[MAX];
    int rank[MAX];
} DisjointSets;

void makeSet(DisjointSets* ds, int n) {
    for (int i = 0; i < n; i++) {
        ds->parent[i] = i;
        ds->rank[i] = 0;
    }
}

int find(DisjointSets* ds, int i) {
    if (ds->parent[i] != i)
        ds->parent[i] = find(ds, ds->parent[i]);
    return ds->parent[i];
}

void unionSets(DisjointSets* ds, int u, int v) {
    int rootU = find(ds, u);
    int rootV = find(ds, v);

    if (rootU != rootV) {
        if (ds->rank[rootU] < ds->rank[rootV])
            ds->parent[rootU] = rootV;
        else if (ds->rank[rootU] > ds->rank[rootV])
            ds->parent[rootV] = rootU;
        else {
            ds->parent[rootV] = rootU;
            ds->rank[rootU]++;
        }
    }
}

void kruskal(int n, Edge edges[], int e) {
    DisjointSets ds;
    makeSet(&ds, n);

    Edge mst[MAX];
    int mstEdges = 0;

    // Sort edges by weight
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < e; i++) {
        int u = find(&ds, edges[i].u);
        int v = find(&ds, edges[i].v);

        if (u != v) {
            mst[mstEdges++] = edges[i];
            unionSets(&ds, u, v);
        }
    }

    printf("Edge \tWeight\n");
    for (int i = 0; i < mstEdges; i++)
        printf("%d - %d \t%d\n", mst[i].u, mst[i].v, mst[i].w);
}

int main() {
    int n, e;
    Edge edges[MAX];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter the edges (u v w):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    kruskal(n, edges, e);

    return 0;
}
