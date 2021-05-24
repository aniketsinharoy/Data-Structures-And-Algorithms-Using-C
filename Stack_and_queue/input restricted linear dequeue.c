//Name:Aniket Sinha Roy
//CSE 2nd year
//Assignment:18 (input restricted linear dequeue)
//Roll:60
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
		printf("INPUT RESTRICTED LINEAR DEQUEUE IS FULL\n");
	}
	else if(front_a==-1 && rear_a==-1)
	{
	    ++front_a;
	    ++rear_a;
		a[rear_a]=n;
		printf("INSERTED IN INPUT RESTRICTED LINEAR DEQUEUE\n");
	}
	else
	{
		++rear_a;
		a[rear_a]=n;
		printf("INSERTED IN INPUT RESTRICTED LINEAR DEQUEUE\n");
	}
}
void del_f()
{
	if(front_a==-1)
	{
		printf("INPUT RESTRICTED LINEAR DEQUEUE IS EMPTY\n");
	}
	else if(front_a==rear_a)
	{
		front_a=-1;
		rear_a=-1;
		printf("ELEMENT DELETED FROM INPUT RESTRICTED LINEAR DEQUEUE\n");
	}
	else
	{
		front_a=front_a+1;
		printf("ELEMENT DELETED FROM INPUT RESTRICTED LINEAR DEQUEUE\n");
	}
}
void del_r()
{
	if(front_a==-1)
	{
		printf("INPUT RESTRICTED LINEAR DEQUEUE IS EMPTY\n");
	}
	else if(front_a==rear_a)
	{
		front_a=-1;
		rear_a=-1;
		printf("ELEMENT DELETED FROM INPUT RESTRICTED LINEAR DEQUEUE\n");
	}
	else
	{
		--rear_a;
		printf("ELEMENT DELETED FROM INPUT RESTRICTED LINEAR DEQUEUE\n");
	}
}
void display()
{
	int d;
	d=front_a;
	if(front_a==-1)
	{
		printf("INPUT RESTRICTED LINEAR DEQUEUE IS EMPTY\n");
	}
	else
	{
		while(d<=rear_a)
		{
			printf("%d\n",a[d]);
			++d;
		}
		printf("DISPLAYED INPUT RESTRICTED LINEAR DEQUEUE\n");
	}
}
int main()
{
	char c;
	printf("INPUT RESTRICTED LINEAR DEQUEQE\n");
	do
	{
		int i,n;
		printf("what do you want to do?\n");
		printf( "1) INSERT FROM REAR\n2) DELETE FROM FRONT\n3) DELETE FROM REAR\n4) DISPLAY\n5) EXIT\n");
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
				    del_f();
				    break;
			    }	
			case 3:
			    {
			    	del_r();
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
