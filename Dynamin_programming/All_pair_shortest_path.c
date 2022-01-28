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
			min_cost_matrix[i][j]=cost_matrix[i][j];
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
			printf("%d\t",min_cost_matrix[i][j]);
		    
		}
		printf("\n");
	}
	for(k=0;k<no_of_vertices;++k)
	{
		for(i=0;i<no_of_vertices;++i)
		{
			for(j=0;j<no_of_vertices;++j)
			{
				min=min_cost_matrix[i][k]+min_cost_matrix[k][j];
				if(min<min_cost_matrix[i][j])
				{
					min_cost_matrix[i][j]=min;
				}		
			}
		}
	
		printf("\nWhen V%d is treated as intermediate vertex:\n",k);
		printf("\n\t");
	    for(i1=0;i1<no_of_vertices;++i1)
	      {
		    printf("V%d\t",i1);
	      }
	    printf("\n----------------------------------------------------------\n");
	    for(i1=0;i1<no_of_vertices;++i1)
	      {
		    printf("V%d   |  ",i1);
		    for(j1=0;j1<no_of_vertices;++j1)
		      {
			    printf("%d\t",min_cost_matrix[i1][j1]);
		       }
		    printf("\n");
	       }
	}
	printf("\nMinimum cost path:\n");
	printf("\n\t");
	    for(i1=0;i1<no_of_vertices;++i1)
	      {
		    printf("V%d\t",i1);
	      }
	    printf("\n----------------------------------------------------------\n");
	    for(i1=0;i1<no_of_vertices;++i1)
	      {
		    printf("V%d   |  ",i1);
		    for(j1=0;j1<no_of_vertices;++j1)
		      {
			    printf("%d\t",min_cost_matrix[i1][j1]);
		       }
		    printf("\n");
	       }
	return 0;
}
/*4
11
6
2
3
9999 
*/
