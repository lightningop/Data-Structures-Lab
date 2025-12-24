#include <stdio.h>
#define MAX 20
int queue[MAX], front = -1, rear = -1;
int visited[MAX];

void enqueue(int vertex) {
    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = vertex;
}

int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    }
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void BFS(int adj[MAX][MAX], int n, int start) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    enqueue(start);
    visited[start] = 1;
    printf("BFS Traversal starting from vertex %d: ", start);

    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, adj[MAX][MAX], start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);
    BFS(adj, n, start);
    return 0;
}
