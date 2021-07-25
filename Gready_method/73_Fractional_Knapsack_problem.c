//Name: Aniket Sinha Roy
//CSE 4th sem
//Roll: 73
#include<stdio.h>
int M=4,N=100;
void bubble_sort(float a[M][N],int n)
{
	int i,j;
	float t;
	for(i=0;i<n-1;++i)
	{
		for(j=0;j<n-i-1;++j)
		{
		   if(a[3][j]<a[3][j+1])
		   {
		   	  t=a[3][j];
		   	  a[3][j]=a[3][j+1];
		   	  a[3][j+1]=t;
		   	  
		   	  t=a[2][j];
		   	  a[2][j]=a[2][j+1];
		   	  a[2][j+1]=t;
		   	  
		   	  t=a[1][j];
		   	  a[1][j]=a[1][j+1];
		   	  a[1][j+1]=t;
		   	  
		   	  t=a[0][j];
		   	  a[0][j]=a[0][j+1];
		   	  a[0][j+1]=t;
		   }	
		}
	}
}
int main()
{
	int no_of_elements;
	float total_weight;
	float weight_profit_matrix[4][100];
	float remaining_weight,temp;
	float sol_set[100];
	int i,j,k;
	printf("Enter number of elements: ");
	scanf("%d",&no_of_elements);
	printf("\nEnter total weight that the bag can hold: ");
	scanf("%f",&total_weight);
	for(i=0;i<no_of_elements;++i)
	{
		weight_profit_matrix[0][i]=i+1;
		printf("\nEnter the weight of element %d: ",i+1);
		scanf("%f",&weight_profit_matrix[1][i]);
		printf("\nEnter the profit of element %d: ",i+1);
		scanf("%f",&weight_profit_matrix[2][i]);
		weight_profit_matrix[3][i]=weight_profit_matrix[2][i]/weight_profit_matrix[1][i];
		sol_set[i]=0;
	}
	remaining_weight=total_weight;
	printf("\nINPUT:\n\n");
	for(i=0;i<3;++i)
	{
		if(i==0)
		{
			printf("ELEMENT NO:  ");
		}
		else if(i==1)
		{
			printf("WEIGHT:      ");
		}
		else
		{
			printf("PROFIT:      ");
		}
		for(j=0;j<no_of_elements;++j)
		{
			printf("%0.2f\t",weight_profit_matrix[i][j]);
		}
		printf("\n");
	}
	bubble_sort(weight_profit_matrix,no_of_elements);
	printf("\n");
	printf("\nElement selected in this order using Greedy Method: ");
	for(i=0;i<no_of_elements;++i)
	{
		if(remaining_weight>=weight_profit_matrix[1][i])
		{
			printf("%0.1f  ",weight_profit_matrix[0][i]);
			remaining_weight=remaining_weight-weight_profit_matrix[1][i];
			sol_set[(int)(weight_profit_matrix[0][i]+0.5)-1]=1;
		}
		else
		{
			temp=(remaining_weight/weight_profit_matrix[1][i])*remaining_weight;
			printf("%0.1f  ",weight_profit_matrix[0][i]);
			sol_set[(int)(weight_profit_matrix[0][i]+0.5)-1]=temp;
			break;
		}
	}
	printf("\n\nSolution Set : { ");
	for(i=0;i<no_of_elements;++i)
	{
		if(i==no_of_elements-1)
		{
			printf("%0.1f ",sol_set[i]);
		}
		else
		printf("%0.1f ,",sol_set[i]);
	}
	printf("}");
	return 0;
}
/*
7
15
2
10
3
5
5
15
7
7
1
6
4
18
1
3
*/
