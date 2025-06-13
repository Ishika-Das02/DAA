#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int u[MAX], v[MAX], w[MAX]; // Parallel arrays for edges
int parent[MAX];
int n, e; // Number of vertices and edges

// Find root
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Union of two sets
void unionSets(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

// Swap elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Simple bubble sort by weight
void sortEdges() {
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (w[j] > w[j + 1]) {
                swap(&w[j], &w[j + 1]);
                swap(&u[j], &u[j + 1]);
                swap(&v[j], &v[j + 1]);
            }
        }
    }
}

void kruskalMST() {
    for (int i = 0; i < n; i++)
        parent[i] = i;

    sortEdges();

    int count = 0;
    int total = 0;
    printf("Edges in MST:\n");
    for (int i = 0; i < e && count < n - 1; i++) {
        int a = find(u[i]);
        int b = find(v[i]);

        if (a != b) {
            printf("%d - %d : %d\n", u[i], v[i], w[i]);
            unionSets(a, b);
            total += w[i];
            count++;
        }
    }

    printf("Total weight of MST: %d\n", total);
}

int main() {
    FILE *fp = fopen("kruskals.txt", "r");
    if (!fp) {
        printf("Error opening file.\n");
        return 1;
    }

    fscanf(fp, "%d %d", &n, &e);

    for (int i = 0; i < e; i++) {
        fscanf(fp, "%d %d %d", &u[i], &v[i], &w[i]);
    }

    fclose(fp);

    kruskalMST();

    return 0;
}
