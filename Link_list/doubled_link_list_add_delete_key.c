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
			temp->next=NULL;
			temp->previous=NULL;
			top=temp;
		}
		else
		{
			temp->a=b;
			d=top;
			while(d->next!=NULL)
			{
				d=d->next;
			}
			d->next=temp;
			temp->next=NULL;
			temp->previous=d;
		}	
	}
	printf("Doubled Link list created\n");
}
void insert_a_n(int m,int n)
{
	struct node *temp,*d;
	temp=(struct node*)malloc(sizeof(struct node));
	if(top==NULL)
	{
		printf("No element in the list...number inserted at the beginning\n");
		top=temp;
		temp->a=n;
		temp->next=NULL;
		temp->previous=NULL;
	}
	else
	{
		d=top;
		while(d->a!=m)
		{
			d=d->next;
		}
		if(d->next==NULL && d->a==m)
		{
			temp->a=n;
			d->next=temp;
			temp->previous=d;
			temp->next=NULL;
			printf("Element inserted after the node.\n");
		}
		else if(d->a==m)
		{
		temp->a=n;
		temp->next=d->next;
		d->next=temp;
		temp->previous=d;
		temp=temp->next;
		temp->previous=d->next;
		printf("Element inserted after the node.\n");
	    }
	    else
	    {
	   	printf("Number not found...nothing inserted");
		}
	}
}
void insert_b_n(int m,int n)
{
	struct node *temp,*d;
	int k=0;
	temp=(struct node*)malloc(sizeof(struct node));
	if(top==NULL)
	{
		printf("No element in the list...number inserted at the beginning\n");
		top=temp;
		temp->a=n;
		temp->next=NULL;
		temp->previous=NULL;
		k=1;
	}
	else
	{
		d=top;
		while(d->a!=m)
		{
			d=d->next;
		}
		if(d==top)
		{
			temp->a=n;
			temp->previous=NULL;
			temp->next=d;
			d->previous=temp;
			top=temp;
			k=1;
			printf("Element inserted before the node.\n");
		}
		else if(d->a==m)
		{
		temp->a=n;
		temp->next=d;
		temp->previous=d->previous;
		d->previous=temp;
		temp=temp->previous;
		temp->next=d->previous;
		printf("Element inserted before the node.\n");
	    }
	    else
	    {
	    	printf("Number not found...nothing inserted.\n");
		}
	}
}
void delete_b()
{
	struct node *temp;
	temp=top;
	if(top==NULL)
	{
		printf("List is empty!!! Nothing deleted...\n");
	}
	else
	{
		top=top->next;
		top->previous=NULL;
		free(temp);
		printf("Deleted at the beginning.\n");
	}
}
void delete_e()
{
	struct node *temp,*d;
	temp=top;
	if(top==NULL)
	{
		printf("List is empty!!! Nothing deleted...\n");
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		d=temp;
		temp=temp->previous;
		temp->next=NULL;
		free(d);
		printf("Deleted at the end.\n");
	}
}
void delete_a_n(int n)
{
	struct node *temp,*d,*m,*k;
	if(top==NULL)
	{
		printf("List is empty!!! Nothing deleted...\n");
	}
	else
	{
		d=top;
		while(d->a!=n)
		{
			d=d->next;
		}
		k=d->next;
		if(d->next==NULL && d->a==n)
		{
			printf("No element after the number...nothing deleted.\n");
		}
		else if(k->next==NULL && d->a==n)
		{
			d->next=NULL;
			free(k);
			printf("Element deleted after the node.\n");
		}
		else if(d->a==n)
		{
		temp=d->next;
		d->next=temp->next;
		m=temp;
		temp=temp->next;
		temp->previous=d;
		free(m);
		printf("Element deleted after the node.\n");
	   }
	   else
	   {
	   	printf("Number not found nothing deleted.\n");
	   }
	}
	
}
void delete_b_n(int n)
{
	struct node *temp,*d,*m,*k;
	if(top==NULL)
	{
		printf("List is empty!!! Nothing deleted...\n");
	}
	else
	{
		d=top;
		while(d->a!=n)
		{
			d=d->next;
		}
		k=d->previous;
		if(d==top && d->a==n)
		{
			printf("No element before it...nothing deleted");
		}
		else if(k==top && d->a==n)
		{
			d->previous=NULL;
			free(k);
			top=d;
			printf("Element deleted before the node.\n");
		}
		else if(d->a==n)
		{
		temp=d->previous;
		d->previous=temp->previous;
		m=temp;
		temp=temp->previous;
		temp->next=d;
		free(m);
		printf("Element deleted before the node.\n");
	    }
	    else
	    {
	    	printf("Number not found...nothing deleted.\n");
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
		int i;
		i=0;
		temp=top;
		while(temp->next!=NULL)
		{
			printf("%d\n",temp->a);
			temp=temp->next;
			i=1;
			if(temp->next==NULL)
			{
				printf("%d\n",temp->a);
		    }
		}
		if(i==0)
		printf("%d\n",temp->a);
	}		
}
int main()
{
	char c;
	do
	{
		int i,n,m;
		printf("what do you want to do?\n");
		printf( " 1)create a double linked list\n 2)insert a node after a node\n 3)insert a node before a node\n 4)delete a node at the beginning\n 5)delete a node at the end\n 6)delete a node after a node\n 7)delete a node before a node\n 8)display the list\n 9) exit\n");
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
			    	printf("enter the number after which the number will be inserted: \n");
			    	scanf("%d",&n);
			    	printf("enter the number: \n ");
			    	scanf("%d",&m);
				    insert_a_n(n,m);
				    break;
			    }	
			case 3:
			    {
			    	printf("enter the number before which the number will be inserted: \n");
			    	scanf("%d",&n);
			    	printf("enter the number: \n ");
			    	scanf("%d",&m);
				    insert_b_n(n,m);
				    break;
				}  
            case 4:
            	{
            		delete_b();
            		break;
				}
			case 5:
			    {
			    	delete_e();
			    	break;
				}	
			case 6:
				{
					printf("enter the number after which the number will be deleted: \n");
			    	scanf("%d",&n);
			    	delete_a_n(n);
			    	break;
				}
            case 7:
            	{
            		printf("enter the number before which the number will be inserted: \n");
			    	scanf("%d",&n);
			    	delete_b_n(n);
			    	break;
				}
			case 8:
		    	{
				    display();
					break;
				}	
			case 9:
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
