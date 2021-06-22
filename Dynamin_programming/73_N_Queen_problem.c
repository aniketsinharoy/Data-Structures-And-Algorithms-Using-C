//Name: Aniket Sinha Roy
//CSE 4th sem
//Roll no: 73
//Assignment: 10 (N_Queen problem)
#include<stdio.h>
int p=0;
int place(int queen_placement[],int k,int i)
{
	
	int j,a,b;
	for(j=1;j<=k-1;++j)
	{
		a=queen_placement[j]-i;
		b=j-k;
		if(a<0)
		{
			a=a*(-1);
		}
		if(b<0)
		{
			b=b*(-1);
		}
		if((queen_placement[j]==i)||(a==b))
		{
			return 0;
		}
	}
	return 1;
}
void n_queen(int queen_placement[],int k,int n)
{
	int i,j;
	int i1,j1,k1;
	for(i=1;i<=n;++i)
	{
		if(place(queen_placement,k,i)==1)
		{
			queen_placement[k]=i;
			if(k==n)
			{
				    ++p;
					printf("\n N QUEEN SOLUTION SET %d: ",p);
					for(i1=1;i1<=n;++i1)
					{
						if(i1==1)
						{
							printf("{ %d, ",queen_placement[i1]);
						}
						else if(i1==n)
						{
							printf("%d }",queen_placement[i1]);
						}
						else
						{
							printf("%d, ",queen_placement[i1]);
						}
						
					}
					printf("\n");
	                printf("\n\t");
	                for(i1=1;i1<=n;++i1)
	                    {
		                    printf(" %d  ",i1);
	                    }
	                printf("\n____________________________________________________________\n");
		                   
                    		for(j1=1;j1<=n;++j1)
		                        {
		                        	printf("     %d|",j1);
			                       for(k1=1;k1<=n;++k1)
			                       {
			                       	  if(queen_placement[j1]==k1)
			                       	     {
			                       	     	if(k==1)
			                       	     	{
			                       	     			printf(" Q |");
											}
											else
											{
													printf(" Q |");
											}
			                       	     
										 }
										 else
										 {
										 	if(k1==1)
										 	 {
										 		printf("   |");
											 }
											 else if(k1==n)
											 {
											 	printf("   |");
											 }
											 else
											 {
											 	printf("   |");
											 }
										 	
										 }
								   }
								   printf("\n------------------------------------------------------------\n");
	                         }
			}
			else
			{
				n_queen(queen_placement,k+1,n);
			}
		}
	}
}
int main()
{
	int dimension_of_board;
	int queen_placement[10];
	int i,j;
	printf("Enter dimension of (NXN) chess board: ");
	scanf("%d",&dimension_of_board);
	n_queen(queen_placement,1,dimension_of_board);
	return 0;
}
