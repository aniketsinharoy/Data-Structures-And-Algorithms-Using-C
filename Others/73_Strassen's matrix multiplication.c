//Name: Aniket Sinha Roy
//CSE 4th sem
//Roll: 73
//Assignment 13 (Strassen's matrix multiplication)
#include<stdio.h>
int main()
{
	int a[2][2],b[2][2],c[2][2];
	int i,j,k,d=0;
	int p,q,r,s,t,u,v;
	printf("STRASSEN'S MATRIX MULTIPLICATION FOR 2X2:\n\n");
	for(k=0;k<=1;++k)
	{
		for(i=0;i<=1;++i)
		{
			for(j=0;j<=1;++j)
			{
				if(k==0)
				{
					printf("Enter the value at [%d][%d] of matrix A: ",i+1,j+1);
					scanf("%d",&a[i][j]);
					printf("\n");
				}
				else
				{
					printf("Enter the value at [%d][%d] of matrix B: ",i+1,j+1);
					scanf("%d",&b[i][j]);
					printf("\n");
				}
			}
		}
	}
	p=(a[0][0]+a[1][1])*(b[0][0]+b[1][1]);
	q=(a[1][0]+a[1][1])*b[0][0];
	r=a[0][0]*(b[0][1]-b[1][1]);
	s=a[1][1]*(b[1][0]-b[0][0]);
	t=(a[0][0]+a[0][1])*b[1][1];
	u=(a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
	v=(a[0][1]-a[1][1])*(b[1][0]+b[1][1]);
	c[0][0]=p+s-t+v;
	c[0][1]=r+t;
	c[1][0]=q+s;
	c[1][1]=p+r-q+u;
	printf("MATRIX MULTIPLICATION RESULT: \n");
	printf("|%d   %d|  *  |%d   %d|   =   |%d   %d|\n",a[0][0],a[0][1],b[0][0],b[0][1],c[0][0],c[0][1]);
    printf("|%d   %d|     |%d   %d|       |%d   %d|\n",a[1][0],a[1][1],b[1][0],b[1][1],c[1][0],c[1][1]);
	return 0;
}
/*
1
2
3
4
5
6
7
8
*/
