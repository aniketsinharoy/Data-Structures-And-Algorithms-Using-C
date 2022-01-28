#include<stdio.h>
int main()
{
	int adj_matrix[21][21];
	int visited[21];
	int stack[21];
	int no_of_vertices;
	int top=-1,start=0;
	int i,j;
	printf("Enter number of vertices: ");
	scanf("%d",&no_of_vertices);
	for(i=0;i<no_of_vertices;++i)
	{
		for(j=0;j<no_of_vertices;++j)
		{
			if(i==j)
			{
				adj_matrix[i][j]=0;
			}
			else
			{
			    printf("\nEnter 1 if V%d and V%d are connected by an edge or else enter 0: ",i,j);
			    scanf("%d",&adj_matrix[i][j]);   
		    }
		}
		visited[i]=0;
	}
	printf("\nADJACENCY MATRIX:\n");
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
			printf("%d\t",adj_matrix[i][j]);
		    
		}
		printf("\n");
	}
	printf("\nTRAVERSAL OF GRAPH IN DFS: V%d  ",start);
    visited[start]=1;
    stack[++top]=start;
    while(top!=-1)
    {
    	start=stack[top];
    	for(i=0;i<no_of_vertices;++i)
    	{
    		if(adj_matrix[start][i]==1 && visited[i]==0)
    		{
    			stack[++top]=i;
    			printf("V%d  ",i);
    			visited[i]=1;
    			break;
			}
		}
		if(i==no_of_vertices)
		{
			top=top-1;
		}
	}
	return 0;
}
/*
8
1
1
0
0
0
0
0
1
0
1
1
0
0
0
1
0
0
0
1
1
0
0
1
0
0
0
0
1
0
1
0
0
0
0
1
0
0
1
0
0
0
1
0
0
1
0
0
0
1
0
0
0
1
1
1
1
*/

