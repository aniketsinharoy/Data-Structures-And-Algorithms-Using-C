#include<stdio.h>
#include<stdlib.h>
struct node
{
	int a;
	struct node* next;
	struct node* previous;
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
			temp->previous=temp;
			top=temp;
		}
		else
		{
			temp->a=b;
			d=top->previous;
			temp->next=top;
			temp->previous=d;
			d->next=temp;
			top->previous=temp;
		}	
	}
	printf("Doubled Link list created\n");
}
void delete_b()
{
	struct node *temp,*d,*m;
	if(top==NULL)
	{
		printf("List empty...nothing deleted.\n");
	}
	else
	{
		if(top->next==top)
		{
			d=top;
			top=NULL;
			free(d);
		}
		else
		{
	    d=top->next;
	    d->previous=top->previous;
	    temp=top->previous;
	    temp->next=d;
	    m=top;
	    top=d;
	    free(m);
	    }
	    printf("Deleted at the beginning.\n");
	}
}
void delete_e()
{
	struct node *temp,*d;
	if(top==NULL)
	{
		printf("List empty...nothing deleted.\n");
	}
	else
	{
		if(top->next==top)
		{
			d=top;
			top=NULL;
			free(d);
		}
		else
		{
		d=top->previous;
		temp=d->previous;
		temp->next=top;
		top->previous=temp;
		free(d);
	    }
		printf("Deleted at the end.\n");
	}
	
}
void delete_a(int n)
{
	struct node *temp,*d,*m;
	int i=0,j=0;
	d=top;
	if(top==NULL)
	{
		printf("List is empty...nothing to delete.\n");
	}
	else
	{
		if(top->a==n && top->next==top)
		{
			top=NULL;
			free(d);
		}
		else
		{
		while(d->a!=n && (d!=top || j==0))
		 {
			d=d->next;
			j++;
			if(d->a==n)
			{
				i=1;
			}
		 }
		 	if(d->a==n)
			{
				i=1;
			}
		 if(i==1)
		 {
		 	temp=d->next;
		 	d->next=temp->next;
		 	m=temp->next;
		 	m->previous=temp->previous;
		 	free(temp);
		 	printf("element deleted.\n");
		 }
		 else
		 {
		 	printf("element not found...nothing deleted.\n");
		 } 
	    }
    }
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
		}
		if(temp->next==top)
			{
				printf("%d\n",temp->a);
		    }
	}		
}
int main()
{
	char c;
	do
	{
		int i,n,m;
		printf("what do you want to do?\n");
		printf( " 1)create a circular doubly linked list\n 2)delete a node at the beginning\n 3)delete a node at the end\n 4)delete a node after a node\n 5)display the list\n 6) exit\n");
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
				    delete_b();
				    break;
			    }	
			case 3:
			    {
			    	delete_e();
			    	break;
				} 
			case 4:
			    {
			    	printf("enter the number after which the number will be deleted: \n");
			    	scanf("%d",&n);
			    	delete_a(n);
			    	break;
			    }	 
            case 5:
            	{
            		display();
					break;
				}
			case 6:
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
