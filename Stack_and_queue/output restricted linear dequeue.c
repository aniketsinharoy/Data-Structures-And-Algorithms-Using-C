#include<stdio.h>
#include<stdlib.h>
int front_a=-1;
int rear_a=-1;
#define max 10
int a[max];
void insert_r(int n)
{
	if(rear_a==max-1)
	{
		printf("OUTPUT RESTRICTED LINEAR DEQUEUE IS FULL\n");
	}
	else if(front_a==-1 && rear_a==-1)
	{
	    ++front_a;
	    ++rear_a;
		a[rear_a]=n;
		printf("INSERTED IN OUTPUT RESTRICTED LINEAR DEQUEUE\n");
	}
	else
	{
		++rear_a;
		a[rear_a]=n;
		printf("INSERTED IN OUTPUT RESTRICTED LINEAR DEQUEUE\n");
	}
}
void insert_f(int n)
{
	if(front_a==0)
	{
		printf("OUTPUT RESTRICTED LINEAR DEQUEUE IS FULL AT FRONT\n");
	}
	else if(front_a==-1 && rear_a==-1)
	{
	    ++front_a;
	    ++rear_a;
		a[front_a]=n;
		printf("INSERTED IN OUTPUT RESTRICTED LINEAR DEQUEUE\n");
	}
	else
	{
		--front_a;
		a[front_a]=n;
		printf("INSERTED IN OUTPUT RESTRICTED LINEAR DEQUEUE\n");
	}
}
void del_f()
{
	if(front_a==-1)
	{
		printf("OUTPUT RESTRICTED LINEAR DEQUEUE IS EMPTY\n");
	}
	else if(front_a==rear_a)
	{
		front_a=-1;
		rear_a=-1;
		printf("ELEMENT DELETED FROM OUTPUT RESTRICTED LINEAR DEQUEUE\n");
	}
	else
	{
		front_a=front_a+1;
		printf("ELEMENT DELETED FROM OUTPUT RESTRICTED LINEAR DEQUEUE\n");
	}
}
void display()
{
	int d;
	d=front_a;
	if(front_a==-1)
	{
		printf("OUTPUT RESTRICTED LINEAR DEQUEUE IS EMPTY\n");
	}
	else
	{
		while(d<=rear_a)
		{
			printf("%d\n",a[d]);
			++d;
		}
		printf("DISPLAYED OUTPUT RESTRICTED LINEAR DEQUEUE\n");
	}
}
int main()
{
	char c;
	printf("OUTPUT RESTRICTED LINEAR DEQUEQE\n");
	do
	{
		int i,n;
		printf("what do you want to do?\n");
		printf( "1) INSERT FROM REAR\n2) INSERT FROM FRONT\n3) DELETE FROM FRONT\n4) DISPLAY\n5) EXIT\n");
	    scanf("%d",&i);
	    printf("\n");
	    switch(i)
		{
			case 1:
				{
					printf("enter the number to be inserted in queue: \n");
					scanf("%d",&n);
					insert_r(n);
					break;
				}
			case 2:
			    {
				    printf("enter the number to be inserted in queue: \n");
					scanf("%d",&n);
					insert_f(n);
					break;
			    }	
			case 3:
			    {
			    	del_f();
			    	break;
				}
			case 4:
			    {
			        display();
					break;	
				}  
			case 5:
			   {
				    printf("EXIT\n");
				    break;
			   }  
			default :
				{
					printf("please enter a correct choice.\n");
					break;
				}
		}			
		printf("want to do again(y/n): \n");
		scanf(" %c",&c);
	}
	while((c=='y') || (c=='Y'));
	return 0;
}
