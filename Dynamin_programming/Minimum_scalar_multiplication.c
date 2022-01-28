#include<stdio.h>
const int M=21;
const int N=21;
void print_ans_sequence(int s[M][N],int i, int j)
{
	if(i==j)
	{
		printf("A%d",i);
	}
	else
	{
		printf("(");
		print_ans_sequence(s,i,s[i][j]);
		print_ans_sequence(s,s[i][j]+1,j);
		printf(")");
	}
}
int main()
{
	int sum_matrix[21][21],dimension_matrix[21][2];
	int k_maxtrix[21][21],number_of_matrixes;
	int i,j,k,m,n,min,min_current,min_k;
	printf("Enter number of matrixes: ");
	scanf("%d",&number_of_matrixes);
	for(i=0;i<number_of_matrixes;++i)
	{
		printf("\nEnter number of rows of matrix %d: ",i);
		scanf("%d",&dimension_matrix[i][0]);
		printf("\nEnter number of columns of matrix %d: ",i);
		scanf("%d",&dimension_matrix[i][1]);
	}
	for(i=0;i<number_of_matrixes;++i)
	{
		sum_matrix[i][i]=0;
	}
	for(i=0;i<number_of_matrixes-1;++i)
	{
		for(j=0;j<number_of_matrixes-(i+1);++j)
		{
			min=-1;
			m=j+1+i;
			for(k=j;k<=m-1;++k)
			{
				min_current=sum_matrix[j][k]+sum_matrix[k+1][m]+dimension_matrix[j][0]*dimension_matrix[k][1]*dimension_matrix[m][1];
				if(min==-1)
				{
					min=min_current;
					min_k=k;
				}
				else if(min>min_current)
				{
					min=min_current;
					min_k=k;
				}
				else
				{
					continue;
				}
			}
			sum_matrix[j][m]=min;
			k_maxtrix[j][m]=min_k;
		}	
	}
	printf("\n\t");
	for(i=0;i<number_of_matrixes;++i)
	{
		printf("M%d\t",i);
	}
	printf("\n----------------------------------------------------------\n");
	for(i=0;i<number_of_matrixes;++i)
	{
		printf("M%d   |  ",i);
		for(j=0;j<number_of_matrixes;++j)
		{
			if(j<i)
			{
				printf("0\t");
			}
			else
			{
			printf("%d\t",sum_matrix[i][j]);
		    }
		    
		}
		printf("\n");
	}
	
	
	printf("\nMinimum number of scalar multiplication required is: %d\n",sum_matrix[0][number_of_matrixes-1]);
	printf("Sequence : ");
	print_ans_sequence(	k_maxtrix,0,number_of_matrixes-1);
	return 0;
}
