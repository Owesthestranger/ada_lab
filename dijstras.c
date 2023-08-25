#include <stdio.h>
int visited[10], i, dist[10], n;

void dij(int n, int v, int cost[10][10], int dist[10]) {
    int count = 1, w, min, u;
    
    for (i = 1; i <= n; i++) {
        dist[i] = cost[v][i];
    }

    while (count <= n) {
        min = 999;
        for (w = 1; w <= n; w++) {
            if (dist[w] < min && !visited[w]) {
                min = dist[w];
                u = w;
            }
        }
        count++;
        visited[u] = 1;
        
        for (w = 1; w <= n; w++) {
            if (dist[u] + cost[u][w] < dist[w] && !visited[w]) {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }
}

int main() {
    int i, j, v, cost[10][10], dist[10];
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }

    for (i = 1; i <= n; i++) {
        visited[i] = 0;
        dist[i] = 999; 
    }
    
    printf("Enter starting vertex: ");
    scanf("%d", &v);
    
    dij(n, v, cost, dist);

    printf("Shortest path is:\n");

    for (i = 1; i <= n; i++) {
        if (i != v) {
            printf("%d->%d, cost=%d\n", v, i, dist[i]); 
        }
    }

    return 0;
}
