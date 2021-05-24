//Name: Aniket Sinha Roy
//CSE 4th sem
//Roll: 73
//Assignment: 6
#include<stdio.h>
int main()
{
	int given_job[3][100];
	int n,i,j,t,l,p=0;
	int process[3][100]={};
	printf("Enter number of jobs: ");
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		given_job[0][i]=i+1;
		for(j=1;j<=2;++j)
		{
			if(j==1)
			{
				printf("\nEnter the due time of the %d job: ",i+1);
				scanf("%d",&given_job[j][i]);
			}
			else
			{
				printf("\nEnter the profit of the %d job: ",i+1);
				scanf("%d",&given_job[j][i]);
			}
		}
	}
	
	for(i=0;i<3;++i)
	{
		if(i==0)
			{
			    printf("JOB:    ");
		    }
		    if(i==1)
		    {
		    	printf("DUE:    ");
			}
			if(i==2)
			{
				printf("PROFIT: ");
			}
		for(j=0;j<n;++j)
		{
			printf("%d\t\t",given_job[i][j]);
		}
		printf("\n");
	}  
	
	
	for(i=0;i<n-1;++i)
	{
		for(j=0;j<n-i-1;++j)
		{
		   if(given_job[2][j]<given_job[2][j+1])
		   {
		   	t=given_job[2][j];
		   	given_job[2][j]=given_job[2][j+1];
		   	given_job[2][j+1]=t;
		   	
		   	t=given_job[0][j];
		   	given_job[0][j]=given_job[0][j+1];
		   	given_job[0][j+1]=t;
		   	
		   	t=given_job[1][j];
		   	given_job[1][j]=given_job[1][j+1];
		   	given_job[1][j+1]=t;
		   	
		   }	
		}
	}
	
	l=given_job[1][0];
	for(i=1;i<n;++i)
	{
		if(l<given_job[1][i])
		{
			l=given_job[1][i];
		}
	}

	
	
	for(i=0;i<l;++i)
	{
		if(process[1][(given_job[1][i])-1]==0)
		{
			process[1][(given_job[1][i])-1]=given_job[1][i];
			process[0][(given_job[1][i])-1]=given_job[0][i];
			process[2][(given_job[1][i])-1]=given_job[2][i];
		}
		else
		{
			for(j=(given_job[1][i])-2;j>=0;--j)
			{
				if(process[1][j]==0)
				{
					process[1][j]=given_job[1][i];
					process[0][j]=given_job[0][i];
					process[2][j]=given_job[2][i];
					break;
				}
			}
		}
	} 
    
    printf("\nJOB SEQUENCE: ");
	    for(j=0;j<l;++j)
		{
			printf(" %d  ",process[0][j]);
			p=p+process[2][j];
		}
		printf("\n");
		
	
	printf("\nPROFIT: %d",p);
   return 0;
}
