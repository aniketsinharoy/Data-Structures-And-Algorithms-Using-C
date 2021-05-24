//Name: Aniket Sinha Roy
//CSE 2nd yr
//Roll: 60
//Assignment: 15(evaluate postfix expression)
#include<stdio.h>
#include<math.h>
#include<string.h>
int top=-1;
int a[50]={0};
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
	}
}
int pop()
{
	if(top==-1)
	{
		printf("Stack is empty...nothing to delete.\n");
	}
	else
	{
		int b;
		b=a[top];
		top=top-1;
	    return b;
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
	}
}
int main()
{
	int i=0,n1,n2,ans;
	char c;
	char p[50];
	printf("Enter the postfix expression: ");
	scanf("%s",&p);
	while(i<=strlen(p)-1)
	{
		c=p[i];
		if(isdigit(c))
		{
			push(c-48);
		}
		else
		{
			n1=pop();
			n2=pop();
			if(c=='+')
			{
				ans=n1+n2;
			}
			if(c=='-')
			{
				ans=n2-n1;
			}
			if(c=='*')
			{
				ans=n2*n1;
			}
			if(c=='/')
			{
				ans=n2/n1;
			}
			if(c=='^')
			{
				ans=pow(n2,n1);
			}
			push(ans);
		}
		++i;
	}
	printf("\nResult: ");
	display();
	return 0;
}
