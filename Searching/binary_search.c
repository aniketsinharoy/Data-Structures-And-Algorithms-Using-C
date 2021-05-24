// name: Aniket Sinha Roy
// CSE 4th sem
//roll: 60
//assignment: 1
#include<stdio.h>
void binary(int l,int h,int s,int a[])
{
	int m;
	m=(l+h-1)/2;
	if(s==a[m])
	{
		printf("\nvalue found at index : %d",m);
	}
	else if(a[m]>s)
	{
		h=m-1;
		return binary(l,h,s,a);
	}
	else if(a[m]<s)
	{
		l=m+1;
		return binary(l,h,s,a);
	}
	else if(h<l)
	{
	
		printf("\n value not found.");
		
	}
}
int main()
{
	int a[100],i,s,n,l=0,h,t,j;
	printf("how many no do u want to enter: ");
	scanf("%d",&n);
	printf("enter the numbers in shorted form: ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
		   if(a[j]>a[j+1])
		   {
		   	t=a[j];
		   	a[j]=a[j+1];
		   	a[j+1]=t;
		   }	
		}
	}
	h=n;
	printf("\n enter the searching element: ");
	scanf("%d",&s);
    binary(l,h,s,a);
	return 0;
}
