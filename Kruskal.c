#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct Edge {
    int src, dest, weight;
} Edge;

typedef struct Graph {
    int V, E;
    Edge edges[MAX];
} Graph;

int parent[MAX];

void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

int findSet(int v) {
    if (parent[v] != v)
        parent[v] = findSet(parent[v]);
    return parent[v];
}

void unionSets(int u, int v) {
    int set1 = findSet(u);
    int set2 = findSet(v);
    if (set1 != set2)
        parent[set2] = set1;
}

int compareEdges(const void *a, const void *b) {
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->weight - edgeB->weight;
}

void krMST(Graph *graph) {
    makeSet(graph->V);
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);

    Edge result[MAX];
    int e = 0;

    for (int i = 0; i < graph->E && e < graph->V - 1; i++) {
        int u = graph->edges[i].src;
        int v = graph->edges[i].dest;
        int w = graph->edges[i].weight;

        if (findSet(u) != findSet(v)) {
            result[e++] = graph->edges[i];
            unionSets(u, v);
        }
    }

    printf("Edges in MST:\n");
    for (int i = 0; i < e; i++) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
    }
}

int main() {
    Graph graph;
    char filename[100];
    FILE *file;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (!file) {
        printf("Error: Unable to open file %s\n", filename);
        return 1;
    }

    fscanf(file, "%d %d", &graph.V, &graph.E);
    for (int i = 0; i < graph.E; i++) {
        fscanf(file, "%d %d %d", &graph.edges[i].src, &graph.edges[i].dest, &graph.edges[i].weight);
    }
    fclose(file);

    krMST(&graph);
    return 0;
}