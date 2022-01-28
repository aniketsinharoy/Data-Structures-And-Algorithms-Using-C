#include<stdio.h>
#include<stdlib.h>
struct node
{
	int a;
	struct node *next;
};
struct node* insert_end(int n, struct node *top,struct node *save)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->a=n;
	temp->next=NULL;
	if(top==NULL)
	{
		top=temp;
		save=temp;	
	}
	else
	{
		save->next=temp;
		save=temp;
	}
	printf("INSERTED AT THE END\n");
	return top;
}
struct node* insert_begin(int n, struct node *top,struct node *save)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(top==NULL)
	{
		temp->a=n;
        temp->next=NULL;
        top=temp;
        save=temp;
	}
	else
	{
		temp->a=n;
		temp->next=top;
		top=temp;
	}
	printf("INSERTED AT THE BEGINNING\n");
	return top;
}
struct node* display(struct node *top)
{
	struct node *temp;
	if(top==NULL)
	{
		printf("list is empty.\n");
	}
	else
	{
		temp=top;
		while(temp!=NULL)
		{
			printf("%d\n",temp->a);
			temp=temp->next;
		}
	}
	return top;
}
struct node* count(struct node *top)
{
	struct node *temp;
	temp=top;
	int b=0;
	if(top==NULL)
	{
		printf("number of node present: %d\n",b);
	}
	else
	{
	while(temp!=NULL)
	{
		++b;
		temp=temp->next;
	}
	printf("number of nodes presnt: %d\n",b);
    }
    return top;
}
struct node* postion(int n,int m,struct node *top)
{
    struct node *temp,*p,*s;
    p=top;
    int d=1;
   	temp=(struct node*)malloc(sizeof(struct node));
   	temp->a=n;
   	temp->next=NULL;
   	if(top==NULL)
   	{
   		printf("list is empty\n");
	}
	else
	{
    	while(d<=m)
     	{
     	   s=p;
   		   p=p->next;
   		   ++d;
    	}
    	temp->next=p;
    	s->next=temp;
    	printf("INSERTED AFTER %d position.\n",m);
    }
    return top;
}
int main()
{
	char c;
	struct node *top,*save;
	top=NULL;
	save=NULL;
	do
	{
		int i,n,m;
		printf("what do you want to do?\n");
		printf( "1) add a node at the end of the list\n 2) no. of nodes present in the list\n 3) add a new node at the beginning of the list\n 4) add a new node after the specified no. of nodes\n 5) display the contents of the list\n 6) exit\n");
	    scanf("%d",&i);
	    printf("\n");
		switch(i)
		{
			case 1:
				{
					printf("enter the number to be inserted: \n");
					scanf("%d",&n);
					top=insert_end(n,top,save);
					save=top;
					break;
				}
			case 2:
			    {
				    top=count(top);
				    break;
			    }	
			case 3:
			    {
			    	printf("enter the number to be inserted at the beginning: \n");
			    	scanf("%d",&n);
			    	top=insert_begin(n,top,save);
			    	break;
				}  
			case 4:
			   {
				    printf("enter the postion after which you want to insert a number: \n");
				    scanf("%d",&m);
				    printf("enter the number: \n");
				    scanf("%d",&n);
				    top=postion(n,m,top);
				    break;
			   }  
			case 5:
				{
					top=display(top);
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
