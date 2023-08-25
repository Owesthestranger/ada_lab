#include<stdio.h>
#include<conio.h>

void swap(int *a,int *b)
{
    int temp=*a;
        *a=*b;
        *b=temp;
}

void quicksort(int a[],int low,int high)
{
    int i,j,key;
    if(low>=high)
    return;
    key=low;i=low+1;j=high;

    while (i<=j)
    {
        while(a[i]<=a[key])
        i++;
        while(a[j]>a[key])
        j--;
        if (i<j)
        swap(&a[i],&a[j]);
    }

    swap(&a[key],&a[j]);
    quicksort(a,low,j-1);
    quicksort(a,j+1,high);
    
}

void main()
{
    int n,k,a[1000];
    printf("enter no of elements\n");
    scanf("%d",&n);
    printf("enter elements\n");
    for(k=1;k<=n;k++)
    scanf("%d",&a[k]);
    quicksort(a,1,n);
    printf("elements are:\n");
    for ( k = 1; k<=n; k++)
    {
        printf("%d",a[k]);
    }
    getch();

}