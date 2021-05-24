#include<stdio.h>
#include<stdlib.h>
struct node
{
	int a;
	struct node* next;
};
struct node *top;
void insert_node(int n)
{
	int i,b;
	struct node *temp,*d;
	printf("enter the numbers: ");
	for(i=0;i<n;++i)
	{
		scanf("%d",&b);
		temp=(struct node*)malloc(sizeof(struct node));
		if(top==NULL)
		{
			temp->a=b;
			temp->next=temp;
			top=temp;
		}
		else
		{
			temp->a=b;
			d=top;
			while(d->next!=top)
			{
				d=d->next;
			}
			d->next=temp;
			temp->next=top;
		}	
	}
	printf("Link list created\n");
}
void insert_b(int n)
{
	struct node *temp,*d;
	temp=(struct node*)malloc(sizeof(struct node));
	if(top==NULL)
	{
		temp->a=n;
		temp->next=temp;
		top=temp;
	}
	else
	{
		d=top;
		while(d->next!=top)
		{
			d=d->next;
		}
		temp->a=n;
		d->next=temp;
		temp->next=top;
		top=temp;
	}
	printf("Inserted at the beginning.\n");
}
void insert_e(int n)
{
	struct node *temp,*d;
	temp=(struct node*)malloc(sizeof(struct node));
	if(top==NULL)
	{
		temp->a=n;
		temp->next=temp;
		top=temp;
	}
	else
	{
		d=top;
		while(d->next!=top)
		{
			d=d->next;
		}
		temp->a=n;
		d->next=temp;
		temp->next=top;
	}
	printf("Inserted at the end.\n");
}
void display()
{
	struct node *temp;
	if(top==NULL)
	{
		printf("List is empty.\n");
	}
	else
	{
		temp=top;
		while(temp->next!=top)
		{
			printf("%d\n",temp->a);
			temp=temp->next;
			if(temp->next==top)
			{
				printf("%d\n",temp->a);
			}
		}
	}
		
}
void del_f()
{
	struct node *temp;
	if(top==NULL)
	{
		printf("List is empty. Nothing to delete.\n");
	}
	else
	{
		temp=top;
		while(temp->next!=top)
		{
			temp=temp->next;
		}
		top=top->next;
		temp->next=top;
		printf("Deleted from beginning.\n");
	}
}
void del_e()
{
		struct node *temp,*d;
	if(top==NULL)
	{
		printf("List is empty. Nothing to delete.\n");
	}
	else
	{
		temp=top;
		while(temp->next!=top)
		{
			d=temp;
			temp=temp->next;
		}
	    d->next=top;
		printf("Deleted from end.\n");
	}
}
void 	del_c()
{
		if(top==NULL)
	{
		printf("List is empty. Nothing to delete.\n");
	}
	else
	{
	    top=NULL;
		printf("Circular link list deleted.\n");
	}
}
int main()
{
	char c;
	do
	{
		int i,n,m;
		printf("what do you want to do?\n");
		printf( " 1)create a circular linked list\n 2)insert a node at the beginning\n 3)insert a node at the end\n 4)delete a node at the front\n 5)delete a node at the end\n 6)delete the circular list\n 7)display the list\n 8) exit\n");
	    scanf("%d",&i);
	    printf("\n");
		switch(i)
		{
			case 1:
				{
					printf("enter how many nodes do you want to inserted: \n");
					scanf("%d",&n);
					insert_node(n);
					break;
				}
			case 2:
			    {
			    	printf("enter the number: \n");
			    	scanf("%d",&n);
				    insert_b(n);
				    break;
			    }	
			case 3:
			    {
			    	printf("enter the number : \n");
			    	scanf("%d",&n);
			    	insert_e(n);
			    	break;
				}  
			case 4:
			   {
				   del_f();
				    break;
			   }  
			case 5:
				{
					del_e();
					break;
				}
			case 6:
				{
					del_c();
					break;
				}
            case 7:
            	{
            		display();
					break;
				}
			case 8:
			    {
			    	printf("Exit\n");
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
