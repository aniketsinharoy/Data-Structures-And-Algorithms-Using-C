#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int i,j,k,a,b,u,v,n,ne=1;
int min,mincost=0;
int cost[21][21]={ };
int parent[21];
int find(int);
int uni(int,int);
int main()
{
	printf("Enter the no of vertices: ");
	scanf("%d",&n);
	printf("\nEnter the cost adjacency matrix:\n");
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			if(i==j)
			{
				cost[i][j]=-1;
			}
			else
			{
				if(cost[i][j]==0)
				{
				printf("\nEnter the weight of edge between vertex V%d and V%d (if edge does not exit enter -1): ",i,j);
			    scanf("%d",&cost[i][j]);
			    cost[j][i]=cost[i][j];
			    }
			}
		
		}
	}
	printf("\nCOST ADJACENCY MATRIX:\n");
	printf("\n\t   ");
	for(i=1;i<=n;++i)
	{
		printf("V%d\t",i);
	}
	printf("\n-----------------------------------------------------------------\n");
	for(i=1;i<=n;++i)
	{
		printf("V%d\t|  ",i);
		for(j=1;j<=n;++j)
		{
			printf("%d\t",cost[i][j]);
				if(cost[i][j]==-1)
				{
					cost[i][j]=999;
				}
		}
		printf("\n");
	}
	printf("\nThe edges of Minimum Cost Spanning Tree are: \n");
	while(ne < n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			printf("Edge (V%d -> V%d) =%d\n",a,b,min);
			ne++;
			mincost +=min;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\n\tMinimum cost = %d\n",mincost);
	return 0;
}
int find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}
int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}
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
