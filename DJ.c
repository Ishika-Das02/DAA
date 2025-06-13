#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int n; // Number of vertices
int graph[MAX][MAX]; // Adjacency matrix
int dist[MAX]; // Distance from source
int parent[MAX]; // Parent array to store path
int visited[MAX]; // Visited set

void initializeSingleSource(int src) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
        visited[i] = 0;
    }
    dist[src] = 0;
}

void relax(int u, int v) {
    if (graph[u][v] && dist[v] > dist[u] + graph[u][v]) {
        dist[v] = dist[u] + graph[u][v];
        parent[v] = u;
        printf("Relaxed edge (%d -> %d), updated dist[%d] = %d\n", u, v, v, dist[v]);
    }
}

int extractMin() {
    int min = INF, u = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            u = i;
        }
    }
    return u;
}

void dijkstra(int src) {
    initializeSingleSource(src);
    printf("Initialized source %d\n", src);

    for (int i = 0; i < n; i++) {
        int u = extractMin();
        if (u == -1) break;
        visited[u] = 1;

        printf("Extracted vertex %d with current shortest distance %d\n", u, dist[u]);

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v]) {
                relax(u, v);
            }
        }

        printf("Current distance array: ");
        for (int k = 0; k < n; k++) {
            if (dist[k] == INF)
                printf("INF ");
            else
                printf("%d ", dist[k]);
        }
        printf("\n---------------------------\n");
    }
}

void printPath(int v) {
    if (v == -1) return;
    printPath(parent[v]);
    printf("%d ", v);
}

int main() {
    FILE *fp = fopen("dj.txt", "r");
    if (!fp) {
        printf("Error opening file.\n");
        return 1;
    }

    int src;
    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fscanf(fp, "%d", &graph[i][j]);
    fscanf(fp, "%d", &src);

    fclose(fp);

    printf("Running Dijkstra's Algorithm from source vertex %d\n\n", src);
    dijkstra(src);

    printf("\nFinal shortest paths from source %d:\n", src);
    for (int i = 0; i < n; i++) {
        printf("To %d (Distance: %d): Path: ", i, dist[i]);
        if (dist[i] == INF)
            printf("No path");
        else
            printPath(i);
        printf("\n");
    }

    return 0;
}
