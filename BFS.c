// bfs_file.c
#include <stdio.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void bfs(int graph[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");
    while (front <= rear) {
        int v = dequeue();
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (graph[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
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
    printf("Enter starting vertex for BFS: ");
    scanf("%d", &start);

    bfs(graph, n, start);

    return 0;
}
