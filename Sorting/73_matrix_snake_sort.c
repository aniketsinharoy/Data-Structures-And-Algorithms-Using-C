//Name:Aniket Sinha Roy
//CSE 4th sem
//Roll:73
//Assignment: 5
#include<stdio.h>
int main()
{
	int a[100][100],i,j,n,t,k,z,m;
	printf("Enter the order of the square matrix (maximum 7): ");
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
	
for(m=0;m<4;++m)
  {
	for(k=0;k<n;++k)
	{
	  for(i=0;i<n-1;++i)
	  {
		for(j=0;j<n-i-1;++j)
		{
			if(k%2==0)
			{
		      if(a[k][j]>a[k][j+1])
		        {
		   	      t=a[k][j];
		   	      a[k][j]=a[k][j+1];
		   	      a[k][j+1]=t;
		        }
	       }
	       else
	       {
	       	   if(a[k][j]<a[k][j+1])
		        {
		   	      t=a[k][j];
		   	      a[k][j]=a[k][j+1];
		   	      a[k][j+1]=t;
		        }
		   }
		}
	  } 
    }
	  for(z=0;z<n;++z)
	  {
	     for(i=0;i<n-1;++i)
	       {
		      for(j=0;j<n-i-1;++j)
		        {
		          if(a[j][z]>a[j+1][z])
		            {
		   	           t=a[j][z];
		   	           a[j][z]=a[j+1][z];
		               a[j+1][z]=t;
		            }	
		        }
	       }    
       } 
    
  }
	printf("\nFinal Maxtrix after sorting in snake like order:\n");
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
