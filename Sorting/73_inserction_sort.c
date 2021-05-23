// name: Aniket Sinha Roy
// CSE 3rd sem
//roll: 60
//assignment: 2
#include<stdio.h>
int main()
{
	int j,n,a[100],t,m,d,i;
	printf("how many element do u want to enter: ");
	scanf("%d",&n);
	printf("\nenter the numbers: ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
    	for(j=1;j<n;++j)
    	{
    		m=j-1;
    		if(a[j]<a[m])
    		{
    			t=a[m];
    			a[m]=a[j];
    			a[j]=t;
    			for(d=m;d>0;--d)
    			{
    				if(a[d]<a[d-1])
    				{
    					t=a[d];
    					a[d]=a[d-1];
    					a[d-1]=t;
					}
					else
					break;
				}
			}
		
		}
	printf("\n after shorting: ");
	for(i=0;i<n;i++)
	{
		printf("\n %d",a[i]);
	}
	return 0;
}
