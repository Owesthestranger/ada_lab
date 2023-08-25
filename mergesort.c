#include<stdio.h>
#include<conio.h>
#include<time.h>

void merge(int a[],int low,int mid,int high)
{
    int i,j,k,b[20];
    i=low;
    j=mid+1;
    k=low;
    while (i<=mid && j<=high)
    {
	if (a[i]<=a[j])
	{
	    b[k++]=a[i++];
	}
	else
	{
	    b[k++]=a[j++];
	}
    }
    while (i<=mid) b[k++]=a[i++];
    while (j<=high) b[k++]=a[j++];

    for (i=low;i<=high;i++)
    {
	a[i]=b[i];
    }

}

void mergesort(int a[],int low,int high)
{
    int mid;
    if (low>=high)
    {
	return;
    }
    mid=(low+high)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    merge(a,low,mid,high);
}

void main()
{
    int n,a[2000],i;
    double ts;
    clock_t st,et;
    printf("enter no of elements\n");
    scanf("%d",&n);
    printf("enter elements\n");
    for (i = 1; i <=n; i++)
    {
	scanf("%d",&a[i]);
    }
    st=clock();
    mergesort(a,1,n);
    et=clock();
    ts=(double)(et-st)/CLOCKS_PER_SEC;
    printf("sorted elements are:\n");
    for ( i = 1; i <=n; i++)
    {
	printf("%d\n",a[i]);

    }
    printf("the time taken is:%e",ts);
    getch();
}