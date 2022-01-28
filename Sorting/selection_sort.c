#include<stdio.h>
int main()
{
	int i,j,n,a[100],t,m,f=0;
	printf("how many element do u want to enter: ");
	scanf("%d",&n);
	printf("\nenter the numbers: ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
    for(i=0;i<n;++i)
    {
    	t=a[i];
    	for(j=i+1;j<n;++j)
    	{
    		if(t>a[j])
    		{
    			t=a[j];
    			m=j;
    			f=1;
			}
		}
		if(f==1)
		{
		a[m]=a[i];
		a[i]=t;
		f=0;
	    }
	}
	printf("\n after shorting: ");
	for(i=0;i<n;i++)
	{
		printf("\n %d",a[i]);
	}
	return 0;
}
