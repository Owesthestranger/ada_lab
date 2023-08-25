#include<stdio.h>
#include<conio.h>

int n,a[20][20],q[20],f=1,r=0,i,j,visited[20];

void bfs(int v)
{
    for(i=1;i<=n;i++)
    if(a[v][i] && !visited[i])
    q[++r]=i;

    if (f<=r)
    {
        visited[q[f]]=1;
        bfs(q[f++]);
    }
    
}

void main()
{
    int i,j,v;
    printf("enter no of nodes\n");
    scanf("%d",&n);
    printf("enter adjacency matrix\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d", &a[i][j]);

    printf("enter starting vertex\n");
    scanf("%d",&v);

    bfs(v);
    printf("the nodes which are reachable\n");
    for(i=1;i<=n;i++)
    if(visited[i])
    printf("%d\t",i);
}