#include<stdio.h>
int top=-1;
int a[50];
void push(int n)
{
	if(top==49)
	{
		printf("Stack is full...\n");
	}
	else
	{
		++top;
		a[top]=n;
		printf("PUSHED\n");
	}
}
void pop()
{
	if(top==-1)
	{
		printf("Stack is empty...nothing to delete.\n");
	}
	else
	{
		top=top-1;
		printf("POPED\n");
	}
}
void display()
{
	int d;
	d=top;
	if(top==-1)
	{
		printf("Stack is empty.\n");
	}
	else
	{
		while(d>=0)
		{
			printf("%d\n",a[d]);
			--d;
		}
		printf("DISPLAYED.\n");
	}
}
int main()
{
	char c;
	do
	{
		int i,n;
		printf("what do you want to do?\n");
		printf( "1) PUSH\n2) POP\n3) DISPLAY\n4) exit\n");
	    scanf("%d",&i);
	    printf("\n");
		switch(i)
		{
			case 1:
				{
					printf("enter the number to be push: \n");
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
