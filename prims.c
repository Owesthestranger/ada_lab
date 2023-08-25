#include <stdio.h>

int n, cost[10][10], visited[10], mincost = 0, ne = 1, min, a, b, u, v;

int main()
{
    int i, j;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);

    for (i = 1; i <= n; i++)
        visited[i] = 0; // Initialize visited array

    visited[1] = 1;
    while (ne < n)
    {
        min = 999; // Initialize min to a large value
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min && visited[i] != 0)
                {
                    min = cost[i][j];
                    u = a = i;
                    v = b = j;
                }
            }
        }
        if (visited[u] == 0 || visited[v] == 0)
        {
            printf("Edge %d: cost(%d->%d) = %d\n", ne, a, b, min);
            ne++;
            mincost += min;
            visited[v] = 1;
        }
        cost[a][b] = cost[b][a] = 999; // Mark the edge as visited
    }

    printf("Minimum cost = %d\n", mincost);

    return 0;
}
