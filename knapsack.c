#include<stdio.h>
#include<conio.h>
int n,m,i,w[10],p[10];

int knapsack(int i,int m)
{
    if (i==n)
    {
        return (w[n]>m)?0:p[n];
    }
    if (w[i]>m)
    {
        return knapsack(i+1,m);
    }
    return max(knapsack(i+1,m),knapsack(i+1,m-w[i])+p[i]);
    
}

int max(int a,int b)
{
    if (a>b)
    {
        return a;
    }
    else
    return b;
}

void main()
{
    int optsoln;
    printf("enter no of objects:\n");
    scanf("%d",&n);
    printf("enter the capacity:\n");
    scanf("%d",&m);
    printf("enter weigts:\n");
    for ( i = 1; i <=n; i++)
    {
        scanf("%d",&w[i]);
    }
    printf("enter profits:\n");
    for ( i = 1; i <=n; i++)
    {
        scanf("%d",&p[i]);
    }
    optsoln=knapsack(1,m);
    printf("the solution is:%d",optsoln);
    getch();
}


