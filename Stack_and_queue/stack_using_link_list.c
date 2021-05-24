//Name: Aniket Sinha Roy
// CSE 2nd year
//roll: 60
//assignment: 13(stack using link list)
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int a;
	struct node *next;
};
struct node* top=NULL;
void push(int n)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->a=n;
	temp->next=NULL;
	if(top==NULL)
	{
		top=temp;
	}
	else
	{
		temp->next=top;
		top=temp;
	}
	printf("PUSHED\n");
}
void pop()
{
	struct node* temp;
	if(top==NULL)
	{
		printf("Stack is empty...nothing to delete.\n");
	}
	else
	{
		temp=top;
		top=top->next;
		free(temp);
		printf("POPED\n");
	}
}
void display()
{
	struct node *temp;
	if(top==NULL)
	{
		printf("Stack is empty.\n");
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
}
int main()
{
	char c;
	do
	{
		int i,n;
		printf("what do you want to do?\n");
		printf( "1) PUSH\n2) POP\n3) DISPLAY\n4) EXIT\n");
	    scanf("%d",&i);
	    printf("\n");
		switch(i)
		{
			case 1:
				{
					printf("enter the number to be pushed: \n");
					scanf("%d",&n);
					push(n);
					break;
				}
			case 2:
			    {
				    pop();
				    break;
			    }	
			case 3:
			    {
			    	display();
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
		printf("want to do again(y/n): \n");
		scanf(" %c",&c);
	}
	while((c=='y') || (c=='Y'));
	return 0;
}
