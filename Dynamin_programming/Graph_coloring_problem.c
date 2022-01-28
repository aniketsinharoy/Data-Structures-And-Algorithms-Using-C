#include<stdio.h>
const int M=21;
const int N=21;
int p=0;
int isSafe(int adj_matrix[M][N], int color_sol[], int k, int c, int n)
{
	int i;
	for(i=0;i<=n;++i)
	{
		if(adj_matrix[k][i]==1 && c==color_sol[i])
		{
			return 0;
		}
	}
	return 1;
}
void graph_color(int adj_matrix[M][N], int color_sol[], int k, int m, int n)
{
	int c;
	int i;
	for(c=1;c<=m;++c)
	{
		if(isSafe(adj_matrix, color_sol, k, c, n)==1)
		{
			color_sol[k]=c;
			if(k==n)
			{
				++p;
				printf("\nSolution set %d : { ",p);
				for(i=0;i<=n;++i)
				{
					if(i==n)
					{
						printf("C%d }\n",color_sol[i]);
					}
					else
					{
						printf("C%d, ",color_sol[i]);
					}
				}
			}
			else
			{
				graph_color(adj_matrix, color_sol, k+1, m, n);
				color_sol[k+1]=0;
			}
		}
	}
}
int main()
{
	int adj_matrix[21][21];
	int color_sol[21];
	int no_of_vertices,no_of_color;
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
		color_sol[i]=0;
	}
	printf("\nEnter number of colors: ");
	scanf("%d",&no_of_color);
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
	graph_color(adj_matrix, color_sol, 0, no_of_color, no_of_vertices-1);
	return 0;
}
/*
4
1
1
1
1
1
1
1
1
0
1
1
0
3
*/



/*
5
1
1
1
0
1
0
1
1
1
0
1
1
1
1
1
1
0
1
1
1
4
*/
