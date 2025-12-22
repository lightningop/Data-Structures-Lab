#include <stdio.h>

int a[10][10], vis[10], n;

void dfs(int v) {
    int i;
    vis[v] = 1;
    printf("%d ", v);
    for (i = 1; i <= n; i++)
        if (a[v][i] && !vis[i])
            dfs(i);
}

void bfs(int s) {
    int q[10], f = 0, r = 0, i;
    q[r++] = s;
    vis[s] = 1;
    while (f < r) {
        int v = q[f++];
        printf("%d ", v);
        for (i = 1; i <= n; i++)
            if (a[v][i] && !vis[i]) {
                vis[i] = 1;
                q[r++] = i;
            }
    }
}

int main() {
    int i, j, src;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    scanf("%d", &src);
    dfs(src);
    for (i = 1; i <= n; i++) vis[i] = 0;
    bfs(src);
    return 0;
}
