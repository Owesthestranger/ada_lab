#include<stdio.h>
#include<conio.h>

int n,a[10][10],indegree[10];

int main()
{
    
    int i,j;
    printf("enter no of nodes\n");
    scanf("%d",&n);
    printf("enter adjacency matrix\n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d", &a[i][j]);

    topology();
    return 0;
}

void find_indegree()
{
    int i,j,sum;
    for ( j = 0; j < n; j++)
    {
        sum=0;
        for ( i = 0; i < n; i++)
        {
            sum+=a[i][j];
        }
        indegree[j]=sum;
        
    }
    
}

void topology()
{
    int i,j,top=-1,s[10],t[10],k,u,v;
    find_indegree();
    for ( i = 0; i < n; i++)
    {
        if (indegree[i]==0)
            s[++top]=i;
    }

while(top!=-1)
{
    u=s[top--];
    
    t[k++]=u;

    for ( v = 0; v < n; v++)
    {
        if (a[u][v]==1)
        {
            indegree[v]--;
            if (indegree[v]==0)
                s[++top]=v;
        }
        
    }
    
}
printf("the sequence is\n");
    for ( i = 0; i < n; i++)
         printf("%d",t[i]);
         printf("\n");

}


