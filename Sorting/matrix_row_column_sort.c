#include<stdio.h>
int main()
{
	int a[100][100],i,j,n,t,k;
	printf("Enter the order of the square matrix: ");
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			printf("\nEnter the element at location [%d][%d]:",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	
	printf("\nOriginal maxtrix:\n");
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	
	for(k=0;k<n;++k)
	{
	  for(i=0;i<n-1;++i)
	  {
		for(j=0;j<n-i-1;++j)
		{
		   if(a[k][j]>a[k][j+1])
		   {
		   	t=a[k][j];
		   	a[k][j]=a[k][j+1];
		   	a[k][j+1]=t;
		   }	
		}
	  }  
    }
    
	printf("\nMaxtrix after row wise sorting:\n");
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	
    for(k=0;k<n;++k)
	{
	  for(i=0;i<n-1;++i)
	  {
		for(j=0;j<n-i-1;++j)
		{
		   if(a[j][k]>a[j+1][k])
		   {
		   	t=a[j][k];
		   	a[j][k]=a[j+1][k];
		   	a[j+1][k]=t;
		   }	
		}
	  }  
    }
	
	printf("\nMaxtrix after column wise sorting:\n");
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
