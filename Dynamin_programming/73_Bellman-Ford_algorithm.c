//Name:Aniket Sinha Roy
//CSE 4th sem
//Roll: 73
//Assignment:9
#include<stdio.h>
int main()
{
	int cost_matrix[21][21];
	int min_cost_matrix[21][21];
	int no_of_vertices;
	int min,current_min;
	int i,j,k,i1,j1;
	printf("Enter number of vertices: ");
	scanf("%d",&no_of_vertices);
	for(i=0;i<no_of_vertices;++i)
	{
		for(j=0;j<no_of_vertices;++j)
		{
			if(i==j)
			{
				cost_matrix[i][j]=0;
				min_cost_matrix[i][j]=0;
			}
			else
			{
			printf("\nEnter cost of edge from V%d to V%d (if no edge enter cost as 9999): ",i,j);
			scanf("%d",&cost_matrix[i][j]);
		    }
		}
	}
	printf("\nCOST MATRIX:\n");
	printf("\n\t");
	for(i=0;i<no_of_vertices;++i)
	{
		printf("V%d\t",i);
	}
	printf("\n----------------------------------------------------------\n");
	for(i=0;i<no_of_vertices;++i)
	{
		printf("V%d   |  ",i);
		for(j=0;j<no_of_vertices;++j)
		{
			printf("%d\t",cost_matrix[i][j]);
		    
		}
		printf("\n");
	}
    for(i=0;i<no_of_vertices;++i)
    {
    	min_cost_matrix[0][i]=cost_matrix[0][i];
	}
    for(k=1;k<no_of_vertices-1;++k)
    {
    	for(i=0;i<no_of_vertices;++i)
    	{
    		if(i==0)
    		{
    			min_cost_matrix[k][i]=0;
			}
		    else
		    {
			
			    current_min=min_cost_matrix[k-1][1]+cost_matrix[1][i];
    		    for(j=2;j<no_of_vertices;++j)
    		    {
    		    	if(i!=j)
    		    	{
    		    		min=min_cost_matrix[k-1][j]+cost_matrix[j][i];
    		    		if(min<current_min)
    		    		{
    		    			current_min=min;
						}
					}
				}
				if(min_cost_matrix[k-1][i]>current_min)
				{
					min_cost_matrix[k][i]=current_min;
				}
				else
				{
					min_cost_matrix[k][i]=min_cost_matrix[k-1][i];
				}
		    }
		}
	}
	printf("\nNO OF EDGES VS VERTICES MATRIX:\n");
	printf("\n\t");
	for(i=0;i<no_of_vertices;++i)
	{
		printf("V%d\t",i);
	}
	printf("\n----------------------------------------------------------\n");
	for(i=0;i<no_of_vertices-1;++i)
	{
		printf("E%d   |  ",i+1);
		for(j=0;j<no_of_vertices;++j)
		{
			printf("%d\t",min_cost_matrix[i][j]);
		    
		}
		printf("\n");
	}
	return 0;
}
/*
4
5
9999
4
9999
6
9999
2
9999
9999
9999
3
1
*/
/*
7
6
5
5
9999
9999
9999
9999
9999
9999
-1
9999
9999
9999
-2
9999
1
9999
9999
9999
9999
-2
9999
-1
9999
9999
9999
9999
9999
9999
3
9999
9999
9999
9999
9999
3
9999
9999
9999
9999
9999
9999
*/

