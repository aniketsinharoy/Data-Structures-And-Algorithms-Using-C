//Name: Aniket Sinha Roy
// CSE 2nd year
//Assignment: 8
//Roll: 60
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
void insert_b(int m,int n)
{
	struct node *temp,*d,*b;
	int k=0;
	b=top;
	while(b->next!=top)
	{
		b=b->next;
	}
	temp=(struct node*)malloc(sizeof(struct node));
	if(top==NULL)
	{
		printf("List is empty!!!Cannot insert\n");
	}
	else
	{
		d=top;
		while(d->a!=m)
		{
			b=d;
			d=d->next;
			if (d->a==m)
			k=1;
		}
		if (d->a==m)
		{
			k=1;
		}
		if (k==1)
		{
	    	temp->a=n;
		    temp->next=d;
		    if(b->next==top)
		    {
		    	top=temp;
			}
		    b->next=temp;
		    printf("Inserted\n");
       }
       else
       {
       	printf("Key not found!!!nothing inserted\n");
	   }
		
	}
}
void insert_a(int m,int n)
{
	struct node *temp,*d;
	int k=0;
	temp=(struct node*)malloc(sizeof(struct node));
	if(top==NULL)
	{
		printf("List is empty!!!Cannot insert");
	}
	else
	{
		d=top;
		while(d->a!=m)
		{
			d=d->next;
			if (d->a==m)
			k=1;
		}
		if (d->a==m)
		{
			k=1;
		}
		if (k==1)
		{
	    	temp->a=n;
		    temp->next=d->next;
		    d->next=temp;
		    printf("Inserted\n");
       }
       else
       {
       	printf("Key not found!!!nothing inserted\n");
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
			if(temp->next==top)
			{
				printf("%d\n",temp->a);
			}
		}
	}
		
}
void del_b(int n)
{
	struct node *temp,*b,*d;
	int k=0;
	if(top==NULL)
	{
		printf("List is empty. Nothing to delete.\n");
	}
	else
	{
		temp=top;
		while(temp->a!=n)
		{
			b=temp;
			temp=temp->next;
			if (temp->a==n)
			k=1;
		}
		if (temp->a==n)
		{
			k=1;
		}
		if (k==1)
		{
			d=top;
			while(d->next!=b)
			{
				d=d->next;
			}
			d->next=temp;
			if(b==top)
			{
				top=temp;
			}
			printf("Deleted.\n");
		}
		else
		{
			printf("Nothing deleted!!!Key not found.\n");
		}
	}
} 
void del_a(int n)
{
	struct node *temp,*b;
	int k=0;
	if(top==NULL)
	{
		printf("List is empty. Nothing to delete.\n");
	}
	else
	{
	    temp=top;
		while(temp->a!=n)
		{
			temp=temp->next;
			if (temp->a==n)
			k=1;
		}
		if (temp->a==n)
		{
			k=1;
		}
		if (k==1)
		{
			b=temp->next;
			temp->next=b->next;
			if(b==top)
			{
				top=b->next;
			}
			printf("Deleted.\n");
		}
		else
		{
			printf("Nothing deleted!!!Key not found.\n");
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
		printf( " 1)create a circular linked list\n 2)insert a node after a key\n 3)insert a node before a key\n 4)delete a node after a key\n 5)delete a node before the key\n 6)display the list\n 7) exit\n");
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
			    	printf("enter the key: \n");
			    	scanf("%d",&m);
			    	printf("enter the number : \n");
			    	scanf("%d",&n);
				    insert_a(m,n);
				    break;
			    }	
			case 3:
			    {
			    	printf("enter the key : \n");
			    	scanf("%d",&m);
			    	printf("enter the number : \n");
			    	scanf("%d",&n);
			    	insert_b(m,n);
			    	break;
				}  
			case 4:
			   {
			   	    printf("enter the key : \n");
			    	scanf("%d",&n);
				    del_a(n);
				    break;
			   }  
			case 5:
				{
					printf("enter the key : \n");
			    	scanf("%d",&n);
					del_b(n);
					break;
				}
			case 6:
				{
					display();
					break;
				}
			case 7:
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
