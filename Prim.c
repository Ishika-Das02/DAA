#include <stdio.h>
#include <limits.h>
#define MAX 100

int graph[MAX][MAX];
int n; // Number of vertices

// Function to find the vertex with minimum key value
int minKey(int key[], int mstSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

// Function to print the constructed MST
void printMST(int parent[])
{
    int totalCost = 0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++){
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }
    printf("Total weight of MST: %d\n", totalCost);
}


// Function to implement Prim's algorithm
void primMST()
{
    int parent[MAX];
    int key[MAX];
    int mstSet[MAX];

    for (int i = 0; i < n; i++)
        key[i] = INT_MAX, mstSet[i] = 0;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        for (int v = 0; v < n; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent);
}

// Main function to read from file and execute Prim's algorithm
int main()
{
    FILE *file;
    char filename[100];

    printf("Enter the filename containing the adjacency matrix: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    fscanf(file, "%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fscanf(file, "%d", &graph[i][j]);

    fclose(file);

    primMST();
    return 0;
}