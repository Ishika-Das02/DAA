#include <stdio.h>
#define MAX 100
#define INF 99999

int u[MAX], v[MAX], w[MAX];  // Edge lists
int dist[MAX];               // Distance from source
int parent[MAX];             // To reconstruct paths
int V, E;                    // Vertices and Edges

// Function to initialize distances and parents
void initialize_single_source(int source) {
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[source] = 0;
}

// Function to relax an edge
void relax(int src, int dest, int weight) {
    if (dist[src] != INF && dist[src] + weight < dist[dest]) {
        dist[dest] = dist[src] + weight;
        parent[dest] = src;
    }
}

// Bellman-Ford algorithm
int bellman_ford(int source) {
    initialize_single_source(source);

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            relax(u[j], v[j], w[j]);
        }
    }

    // Check for negative weight cycle
    for (int j = 0; j < E; j++) {
        if (dist[u[j]] != INF && dist[u[j]] + w[j] < dist[v[j]]) {
            return 0; // Negative cycle found
        }
    }
    return 1; // Success
}

// Recursive function to print path
void print_path(int vertex) {
    if (vertex == -1) return;
    print_path(parent[vertex]);
    printf("%d ", vertex);
}

// Print distances and paths
void print_result(int source) {
    printf("Vertex\tDistance\tPath\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t", i);
        if (dist[i] == INF) {
            printf("INF\t\tNo path\n");
        } else {
            printf("%d\t\t", dist[i]);
            print_path(i);
            printf("\n");
        }
    }
}

int main() {
    FILE *fp;
    char filename[50];

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (!fp) {
        printf("File not found.\n");
        return 1;
    }

    fscanf(fp, "%d %d", &V, &E);
    for (int i = 0; i < E; i++) {
        fscanf(fp, "%d %d %d", &u[i], &v[i], &w[i]);
    }
    fclose(fp);

    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    if (bellman_ford(source)) {
        print_result(source);
    } else {
        printf("Graph contains a negative weight cycle.\n");
    }

    return 0;
}
