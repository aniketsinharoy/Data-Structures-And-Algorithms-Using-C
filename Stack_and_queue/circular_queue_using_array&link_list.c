//Name:Aniket Sinha Roy
//CSE 2nd year
//Assignment:17 (circular queue using array & link list)
//Roll:60
#include<stdio.h>
#include<stdlib.h>
int front_a=-1;
int rear_a=-1;
struct node* front_l=NULL;
struct node* rear_l=NULL;
int a[10];
struct node
{
	int a;
	struct node *next;
};
void insert_a(int n)
{
	if((rear_a==9 && front_a==0)||(rear_a+1==front_a))
	{
		printf("Circular Queue is full...(ARRAY)\n");
	}
	else if(front_a==-1 && rear_a==-1)
	{
	    ++front_a;
	    ++rear_a;
		a[rear_a]=n;
		printf("INSERTED IN CIRCULAR QUEUE(ARRAY)\n");
	}
	else if(front_a!=0 && rear_a==9)
	{
		rear_a=0;
		a[rear_a]=n;
		printf("INSERTED IN CIRCULAR QUEUE(ARRAY)\n");
	}
	else
	{
		++rear_a;
		a[rear_a]=n;
		printf("INSERTED IN CIRCULAR QUEUE(ARRAY)\n");
	}
}
void del_a()
{
	if(front_a==-1 && front_a==-1)
	{
		printf("Circular Queue is empty...nothing to delete.(ARRAY)\n");
	}
	else if(front_a==rear_a)
	{
		front_a=-1;
		rear_a=-1;
		printf("ELEMENT DELETED FROM CIRCULAR QUEUE(ARRAY)\n");
	}
	else if(front_a==9 && rear_a<front_a)
	{
		front_a=0;
		printf("ELEMENT DELETED FROM CIRCULAR QUEUE(ARRAY)\n");
	}
	else
	{
		front_a=front_a+1;
		printf("ELEMENT DELETED FROM CIRCULAR QUEUE(ARRAY)\n");
	}
}
void display_a()
{
	int d;
	d=front_a;
	if(front_a==-1)
	{
		printf("Circular Queue is empty.(ARRAY)\n");
	}
	else
	{
		if(rear_a>=front_a)
		{
			while(d<=rear_a)
	    	{
			printf("%d\n",a[d]);
			++d;
		    } 
		}
		else
		{
			while(d<=9)
		    {
			printf("%d\n",a[d]);
			++d;
		    }
		    d=0;
		    while(d<=rear_a)
		   { 
			printf("%d\n",a[d]);
			++d;
		   }
		}
	
		printf("DISPLAYED CIRCULAR QUEUE(ARRAY.\n");
	}
}
void insert_l(int n)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(rear_l==NULL)
	{
		temp->a=n;
		temp->next=temp;
		rear_l=temp;
		front_l=temp;
	}
	else
	{
		temp->a=n;
		rear_l->next=temp;
		temp->next=front_l;
		rear_l=rear_l->next;
	}
	printf("INSERTED IN CIRCULAR QUEUE(LINK LIST)\n");
}
void del_l()
{
	struct node* temp;
	if(front_l==NULL)
	{
		printf("Circular Queue is empty...nothing to delete.(LINK LIST)\n");
	}
	else if(rear_l==front_l)
	{
		temp=front_l;
		rear_l=NULL;
		front_l=NULL;
		free(temp);
		printf("ELEMENT DELETED FROM CIRCULAR QUEUE(LINK LIST)\n");
	}
	else
	{
		temp=front_l;
		front_l=front_l->next;
		rear_l->next=front_l;
		free(temp);
		printf("ELEMENT DELETED FROM CIRCULAR QUEUE(LINK LIST)\n");
	}
}
void display_l()
{
	struct node *temp;
	if(front_l==NULL)
	{
		printf("Circular Queue is empty.(LINK LIST)\n");
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
		printf("DISPLAYED CIRCULAR QUEUE(LINK LIST)\n");
	}
}
int main()
{
	char c;
	do
	{
		int i,n,j;
		printf("what do you want to do?\n");
		printf("1.Circular queue using array \n2.Circular queue using link list\n");
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
