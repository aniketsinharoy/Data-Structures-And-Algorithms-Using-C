//Name: Aniket Sinha Roy
//CSE 4th sem
//Roll: 73
//Assignment: 12 (prim's problem)
#include<stdio.h>
int min_weight_node(int min_weight[],int visited[],int n)
{
	int min=9999;
	int i;
	int min_node;
	for(i=0;i<n;++i)
	{
		if(visited[i]==0 && min_weight[i]<min)
		{
			min=min_weight[i];
			min_node=i;
		}
	}
	return min_node;
}
int main()
{
	int weight[21][21]={ };
	int weight_mst[21][21]={ };
	int parent_node[21];
	int min_weight[21];
	int visited[21];
	int i,j,u,v;
	int no_of_vertex,sum=0;
	printf("Enter the total number of vertex:");
	scanf("%d",&no_of_vertex);
	for(i=0;i<no_of_vertex;++i)
	{
		for(j=0;j<no_of_vertex;++j)
		{
			if(i!=j && weight[i][j]==0)
			{
			printf("\nEnter the weight of edge between vertex V%d and V%d (if edge does not exit enter -1): ",i,j);
			scanf("%d",&weight[i][j]);
			weight[j][i]=weight[i][j];
		    }
		    if(i==j)
		    {
		    	weight[i][j]=-1;
			}
		}
	}
	printf("\nWEIGHT MATRIX:\n");
	printf("\n\t   ");
	for(i=0;i<no_of_vertex;++i)
	{
		printf("V%d\t",i);
	}
	printf("\n-----------------------------------------------------------------\n");
	for(i=0;i<no_of_vertex;++i)
	{
		printf("V%d\t|  ",i);
		for(j=0;j<no_of_vertex;++j)
		{
			printf("%d\t",weight[i][j]);
		}
		printf("\n");
	}
    for(i=0;i<no_of_vertex;++i)
    {
    	visited[i]=0;
    	min_weight[i]=9999;
	}
	parent_node[0]=-1;
	min_weight[0]=0;
	for(i=0;i<no_of_vertex-1;++i)
	{
		u=min_weight_node(min_weight, visited, no_of_vertex);
		visited[u]=1;
		for(j=0;j<no_of_vertex;++j)
		{
			if(visited[j]==0 && min_weight[j]>weight[u][j] && weight[u][j]!=-1)
			{
				parent_node[j]=u;
				min_weight[j]=weight[u][j];
			}
		}
	}
	for(i=0;i<no_of_vertex;++i)
	{
		sum=sum+min_weight[i];
	}
	for(i=0;i<no_of_vertex;++i)
	{
		for(j=0;j<no_of_vertex;++j)
		{
			if(parent_node[j]==i)
			{
				weight_mst[i][j]=weight[i][j];
				weight_mst[j][i]=weight[i][j];
			}
		}
	}
	printf("\nWEIGHT MATRIX OF MINIMUM SPANNING TREE:\n");
	printf("\n\t   ");
	for(i=0;i<no_of_vertex;++i)
	{
		printf("V%d\t",i);
	}
	printf("\n-----------------------------------------------------------------\n");
	for(i=0;i<no_of_vertex;++i)
	{
		printf("V%d\t|  ",i);
		for(j=0;j<no_of_vertex;++j)
		{
			if(weight_mst[i][j]==0)
			{
				printf("X\t");
			}
			else
			{
				printf("%d\t",weight_mst[i][j]);
			}
		}
		printf("\n");
	}
	printf("\nMINIMUM WEIGHT : %d",sum);
	return 0;
}

/*
6
2
-1
-1
-1
4
8
-1
-1
3
6
1
-1
12
-1
2
*/

/*
6
2
4
3
-1
-1
5
2
5
-1
3
-1
5
6
4
7
*/
