#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define INF 99999

int dist[MAX][MAX];     // Distance matrix
int next[MAX][MAX];     // Next vertex in the path
int V;                  // Number of vertices

// Initialize distance and path
void initialize() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j)
                next[i][j] = i;
            else if (dist[i][j] != INF)
                next[i][j] = j;
            else
                next[i][j] = -1;
        }
    }
}

// Floyd-Warshall algorithm
void floyd_warshall() {
    initialize();

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k]; // path reconstruction
                }
            }
        }
    }
}

// Print path from i to j using next matrix
void print_path(int i, int j) {
    if (next[i][j] == -1) {
        printf("No path");
        return;
    }
    printf("%d ", i);
    while (i != j) {
        i = next[i][j];
        printf("%d ", i);
    }
}

// Print the final distance and path matrices
void print_result() {
    printf("\nShortest Distances and Paths:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("From %d to %d: ", i, j);
            if (dist[i][j] == INF)
                printf("INF\tPath: No path\n");
            else {
                printf("%d\tPath: ", dist[i][j]);
                print_path(i, j);
                printf("\n");
            }
        }
    }
}

int main() {
    FILE *fp;
    char filename[50];
    char temp[10];

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (!fp) {
        printf("File not found.\n");
        return 1;
    }

    fscanf(fp, "%d", &V);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            fscanf(fp, "%s", temp);
            if (strcmp(temp, "INF") == 0)
                dist[i][j] = INF;
            else
                dist[i][j] = atoi(temp);
        }
    }

    fclose(fp);

    floyd_warshall();
    print_result();

    return 0;
}
