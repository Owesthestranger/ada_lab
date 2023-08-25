#include<stdio.h>
#include<conio.h>
int i,j,n,visited[20],a[20][20],count=0;

void dfs(int v)
{
    visited[v]=1;
    for ( i = 1; i <=n; i++)
    {
        if (a[v][i]&&!visited[i])
        {
            printf("%d->%d\n",v,i);
            dfs(i);
        }
        
    }
    
}

void main()
{
    printf("enter no of nodes:\n");
    scanf("%d",&n);
    printf("enter adjacency matrix:\n");
    for ( i = 1; i<=n; i++)
    {
        for ( j = 1; j<=n; j++)
        {
            scanf("%d",&a[i][j]);
        }
        
    }
    dfs(1);
    for (i = 1; i<=n; i++)
    {
       if (visited[i])
    {
        count++;
    }
    }
    if (count==n)
    {
        printf("the graph is connected");
    }
    else
    {
        printf("not connected");
    }
    
    
}