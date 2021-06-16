//Name:Aniket Sinha Roy
//CSE 4th sem
//Roll: 73
//Assignment:9
#include<stdio.h>
int main()
{
	int adj_matrix[21][21];
	int visited[21];
	int queue[21];
	int no_of_vertices;
	int rear=-1,front=-1,start;
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
	printf("TRAVERSAL OF GRAPH IN BFS: ");
    queue[++rear] = start;
    visited[start] = 1;
    while(rear != front)
       {
           start = queue[++front];
           printf("V%d\t",start);
	 	    for(i=0;i<no_of_vertices;++i)
              {
	 	 	     if(adj_matrix[start][i]==1 && visited[i]==0)
                    {
                         queue[++rear]=i;
                         visited[i]=1;
                    }
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

