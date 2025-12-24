#include <stdio.h>
#define MAX 20
int visited[MAX];

void DFS(int adj[MAX][MAX], int n, int start) {
    visited[start] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[start][i] == 1 && !visited[i]) {
            DFS(adj, n, i);
        }
    }
}

int main() {
    int n, adj[MAX][MAX], start = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    for (int i = 0; i < n; i++) visited[i] = 0;
    DFS(adj, n, start);
    int connected = 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }
    if (connected)
        printf("The graph is connected.\n");
    else
        printf("The graph is NOT connected.\n");
    return 0;
}
