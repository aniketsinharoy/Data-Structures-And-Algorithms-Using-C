#include<stdio.h>
#include<stdlib.h>
int front_a=-1, rear_a=-1;
struct node* front_l=NULL;
struct node* rear_l=NULL;
int a[50];
struct node
{
	int a;
	struct node *next;
};
void insert_a(int n)
{
	if(rear_a==49)
	{
		printf("Queue is full...(ARRAY)\n");
	}
	else if(front_a==-1 && rear_a==-1)
	{
	    ++front_a;
	    ++rear_a;
		a[rear_a]=n;
		printf("INSERTED IN LINEAR QUEUE(ARRAY)\n");
	}
	else
	{
		++rear_a;
		a[rear_a]=n;
		printf("INSERTED IN LINEAR QUEUE(ARRAY)\n");
	}
}
void del_a()
{
	if(front_a==-1 || front_a==49)
	{
		printf("Queue is empty...nothing to delete.(ARRAY)\n");
	}
	else
	{
		front_a=front_a+1;
		printf("ELEMENT DELETED FROM LINEAR QUEUE(ARRAY)\n");
	}
}
void display_a()
{
	int d;
	d=front_a;
	if(front_a==-1)
	{
		printf("Queue is empty.(ARRAY)\n");
	}
	else
	{
		while(d<=rear_a)
		{
			printf("%d\n",a[d]);
			++d;
		}
		printf("DISPLAYED LINEAR QUEUE(ARRAY.\n");
	}
}
void insert_l(int n)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->a=n;
	temp->next=NULL;
	if(front_l==NULL)
	{
		front_l=temp;
		rear_l=temp;
	}
	else
	{
		rear_l->next=temp;
		rear_l=temp;
	}
	printf("INSERTED IN LINEAR QUEUE(LINK LIST)\n");
}
void del_l()
{
	struct node* temp;
	if(front_l==NULL)
	{
		printf("Queue is empty...nothing to delete.(LINK LIST)\n");
	}
	else
	{
		temp=front_l;
		front_l=front_l->next;
		free(temp);
		printf("ELEMENT DELETED FROM LINEAR QUEUE(LINK LIST)\n");
	}
}
void display_l()
{
	struct node *temp;
	if(front_l==NULL)
	{
		printf("Queue is empty.(LINK LIST)\n");
	}
	else
	{
		temp=front_l;
		while(temp!=rear_l)
		{
			printf("%d\n",temp->a);
			temp=temp->next;
		}
		printf("%d\n",temp->a);
		printf("DISPLAYED LINEAR QUEUE(LINK LIST)\n");
	}
}
int main()
{
	char c;
	do
	{
		int i,n,j;
		printf("what do you want to do?\n");
		printf("1.Linear queue using array \n2.Linear queue using link list\n");
		scanf("%d",&j);
		if(j==1)
		{
			printf( "1) INSERT\n2) DELETE\n3) DISPLAY\n4) EXIT\n");
	        scanf("%d",&i);
	        printf("\n");
	        switch(i)
		{
			case 1:
				{
					printf("enter the number to be inserted in queue: \n");
					scanf("%d",&n);
					insert_a(n);
					break;
				}
			case 2:
			    {
				    del_a();
				    break;
			    }	
			case 3:
			    {
			    	display_a();
			    	break;
				}  
			case 4:
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
		}
		else
		{
			printf( "1) INSERT\n2) DELETE\n3) DISPLAY\n4) EXIT\n");
	        scanf("%d",&i);
	        printf("\n");
	        switch(i)
		{
			case 1:
				{
					printf("enter the number to be inserted in queue: \n");
					scanf("%d",&n);
					insert_l(n);
					break;
				}
			case 2:
			    {
				    del_l();
				    break;
			    }	
			case 3:
			    {
			    	display_l();
			    	break;
				}  
			case 4:
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
		}
		
		printf("want to do again(y/n): \n");
		scanf(" %c",&c);
	}
	while((c=='y') || (c=='Y'));
	return 0;
}
