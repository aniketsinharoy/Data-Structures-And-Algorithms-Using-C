#include<stdio.h>
void swap(int *m,int *n)
{
	int t;
	t=*m;
	*m=*n;
	*n=t;
}
void permutation(int a[],int cid,int n)
{
	int i,j;
	if(cid==n-1)
	{
		for(j=0;j<n;++j)
		{
			printf("%d  ",a[j]);
		}
		printf("\n");
	}
	else
	{
		for(i=cid;i<n;++i)
		{
		    swap(&a[i],&a[cid]);
			permutation(a,cid+1,n);
			swap(&a[i],&a[cid]);
		}
	}
}
int main()
{
	int a[10],i,n;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	printf("\nEnter the numbers: ");
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	permutation(a,0,n);
	return 0;
}
