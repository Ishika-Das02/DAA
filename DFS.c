// dfs_file.c
#include <stdio.h>
#define MAX 100

void dfsUtil(int graph[MAX][MAX], int n, int v, int visited[MAX]) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            dfsUtil(graph, n, i, visited);
        }
    }
}

void dfs(int graph[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    printf("DFS Traversal: ");
    dfsUtil(graph, n, start, visited);
    printf("\n");
}

int main() {
    int graph[MAX][MAX], n;
    char filename[50];
    FILE *fp;

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (!fp) {
        printf("File not found.\n");
        return 1;
    }

    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fscanf(fp, "%d", &graph[i][j]);

    fclose(fp);

    int start;
    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);

    dfs(graph, n, start);

    return 0;
}
