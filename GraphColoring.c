#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int G[MAX][MAX];   // Adjacency matrix
int x[MAX];        // Color assignment array
int n, m;          // n = number of vertices, m = number of colors

// Assign next possible color to vertex k
void NextValue(int k) {
    while (1) {
        x[k] = (x[k] + 1) % (m + 1);  // Next color from 1 to m

        if (x[k] == 0)
            return; // All colors tried, backtrack

        int j;
        for (j = 1; j <= n; j++) {
            if (G[k][j] && x[k] == x[j])
                break; // Conflict: adjacent vertex has same color
        }

        if (j == n + 1)
            return; // Valid color found
    }
}

// Recursive backtracking function
void mColoring(int k) {
    while (1) {
        NextValue(k);
        if (x[k] == 0)
            return; // No valid color

        if (k == n) {
            printf("Solution: ");
            for (int i = 1; i <= n; i++)
                printf("%d ", x[i]);
            printf("\n");
        } else {
            mColoring(k + 1); // Try next vertex
        }
    }
}

int main() {
    FILE *fp = fopen("color.txt", "r");
    if (!fp) {
        printf("Error opening file.\n");
        return 1;
    }

    fscanf(fp, "%d %d", &n, &m); // Read number of vertices and colors

    // Read adjacency matrix
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            fscanf(fp, "%d", &G[i][j]);

    fclose(fp);

    // Initialize color assignments
    for (int i = 1; i <= n; i++)
        x[i] = 0;

    printf("All valid colorings using %d colors:\n", m);
    mColoring(1);

    return 0;
}
