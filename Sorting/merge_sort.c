#include<stdio.h>
void merge(int a[],int l,int m,int h)
{
	int i,j,k;
	int b[100];
	i=l;
	j=m+1;
	k=l;
	while(i<=m && j<=h)
	{
		if(a[i]>=a[j])
		{
            b[k]=a[j];
            ++j;
            ++k;
		}
		if(a[i]<a[j])
		{
		   b[k]=a[i];
		   ++i;
		   ++k;
		}
	}
	if(i>m)
	{
		while(j<=h)
		{
			b[k]=a[j];
			++j;
			++k;
		}
	}
	if(j>h)
	{
		while(i<=m)
		{
			b[k]=a[i];
			++i;
			++k;
		}
	}
	for(k=l;k<=h;++k)
	{
		a[k]=b[k];
	}
}
void mergesort(int a[],int l,int h)
{
	int m;
	m=(l+h)/2;
	if(l<h)
	{
		mergesort(a,l,m);
		mergesort(a,m+1,h);
		merge(a,l,m,h);
	}
}
int main()
{
	int i,j,n,a[100],l=0;
	printf("how many element do u want to enter: ");
	scanf("%d",&n);
	printf("\nenter the numbers: ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
    mergesort(a,l,n-1);
	printf("\n after shorting: ");
	for(i=0;i<n;i++)
	{
		
		printf("\n %d",a[i]);
	}
	return 0;
}
