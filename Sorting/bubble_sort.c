#include<stdio.h>
int main()
{
	int i,j,n,a[100],t;
	printf("how many element do u want to enter: ");
	scanf("%d",&n);
	printf("\nenter the numbers: ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
		   if(a[j]>a[j+1])
		   {
		   	t=a[j];
		   	a[j]=a[j+1];
		   	a[j+1]=t;
		   }	
		}
	}
	printf("\n after shorting: ");
	for(i=0;i<n;i++)
	{
		printf("\n %d",a[i]);
	}
	return 0;
}
