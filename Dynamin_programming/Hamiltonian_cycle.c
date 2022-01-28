#include<stdio.h>
const int M=21;
const int N=21;
int p=0;
int NextValue(int adj_matrix[M][N],int ham_sol[],int n,int k)
{
	int j;
    do 
      { 
            ham_sol[k]=(ham_sol[k]+1)%(n+1); 
            if(ham_sol[k]==0)
		    {
		   	    return;
			} 
            if(adj_matrix[ham_sol[k-1]][ham_sol[k]]==1) 
            { 
                for(j=1;j<=k-1;++j)
				  {
				      if(ham_sol[j]==ham_sol[k])
					  {
					    break;	
					  }	
				  } 
                if(j==k)
				{
					if((k<n) || ((k==n) && adj_matrix[ham_sol[n]][ham_sol[0]]==1)) 
					{
						return;
					}
				}  
            } 
      } 
	while(1); 
}
void ham_cycle(int adj_matrix[M][N],int ham_sol[],int n,int k)
{
    int i=0;
	do 
      { 
        NextValue(adj_matrix,ham_sol,n,k); 
        if (ham_sol[k]==0)
		{
		    return;
		}  
        else if(k==n) 
	    {  
		    printf("\nSolution set %d : { ",++p);
		    for(i=0;i<=n;++i)
		    {
		    	if(i==n)
		    	{
		    		printf("V%d -> v%d }",ham_sol[i],ham_sol[0]);
				}
				else
				{
				   printf("V%d -> ",ham_sol[i]);	
				}
			}
		}
        else 
		{
		    ham_cycle(adj_matrix,ham_sol,n,k+1);	
		}
      } 
	while(1);
}
int main()
{
	int adj_matrix[21][21];
	int ham_sol[21];
	int no_of_vertices;
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
				if(j>i && (no_of_vertices-1)%2==1)
				{
			      printf("\nEnter 1 if V%d and V%d are connected by an edge or else enter 0: ",i,j);
			      scanf("%d",&adj_matrix[i][j]);
				  adj_matrix[j][i]=adj_matrix[i][j];  
			    }
			    if(j>i && (no_of_vertices-1)%2==0)
			    {
			      printf("\nEnter 1 if V%d and V%d are connected by an edge or else enter 0: ",i,j);
			      scanf("%d",&adj_matrix[i][j]);
				  adj_matrix[j][i]=adj_matrix[i][j];  
				}
		    }
		}
		    ham_sol[i]=0;
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
	ham_sol[0]=0;
	ham_cycle(adj_matrix,ham_sol,no_of_vertices-1,1);
	return 0;
}
/*
4
1
0
1
1
0
1
*/
