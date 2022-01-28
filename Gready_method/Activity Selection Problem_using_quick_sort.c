#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b) 
{
  int t = *a;
  *a = *b;
  *b = t;
}
int partition(int a[], int l, int h, int s[], int o[]) 
{
	int pivot = a[h];
  	int i = (l-1);
  	for (int j=l;j<h;j++)
	{
    	if (a[j]<pivot) 
		{
      		i++;
      		swap(&a[i],&a[j]);
      		swap(&s[i],&s[j]);
      		swap(&o[i],&o[j]);
    	}
  	}
  	swap(&a[i+1],&a[h]);
  	swap(&s[i+1],&s[h]);
  	swap(&o[i+1],&o[h]);
  	return (i+1);
}
void quickSort(int a[], int l, int h, int s[], int o[]) 
{
  	if (l<h) 
  	{
    	int p = partition(a,l,h,s,o);
    	quickSort(a,l,p-1,s,o);
    	quickSort(a,p+1,h,s,o);
  	}
}
void activity_selector(int s[], int f[], int o[], int n)
{
	int a[n];
	a[0]=o[0];
	int i=0;
	int x=1;
	for(int m=1;m<n;m++)
	{
		if(s[m]>f[i])
		{
			a[x++]=o[m];
			i=m;
		}
	}
	printf("\nThe activities selected are:\t");
	for(int j=0;j<x;j++)
		printf("%d\t",a[j]);
}
int main()
{
	int n,i;
	printf("\nEnter number of activities: ");
	scanf("%d",&n);
	int start[n];
	int finish[n];
	int order[n];
	for(i=0;i<n;i++)
	{
		printf("\nActivity %d:\n",(i+1));
		printf("\nEnter starting time:\n");
		scanf("%d",&start[i]);
		printf("\nEnter finishing time:\n");
		scanf("%d",&finish[i]);
		order[i]=i+1;
	}
	quickSort(finish,0,n-1,start,order);
	activity_selector(start,finish,order,n);
	return 0;
}
