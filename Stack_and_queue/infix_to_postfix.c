//Name:Aniket Sinha Roy
//CSE 2nd year
//Assignment:14 (infix to postfix)
//Roll:60
#include<stdio.h>
int top=-1;
char a[50];
void push(char n)
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
char pop()
{
	int b;
	if(top==-1)
	{
		printf("Stack is empty...nothing to delete.\n");
	}
	else
	{
		b=a[top];
		top=top-1;
	}
	return b;
}
int priority(char x)
{
	if(x=='(')
	{
		return 0;
	}
	if(x=='+' || x=='-')
	{
		return 1;
	}
	if(x=='*' || x=='/')
	{
		return 2;
	}
	if(x=='^')
	{
		return 3;
	}
	
}
int main()
{
	char ex[50];
	char p[50];
	int i=0,j;
	char *e;
	char x;
    printf("Enter the infix expression:\n");
    scanf("%s",&ex);
    e=ex;
    while(*e!='\0')
    {
    	if((*e>=48 && *e<=57)||(*e>=97 && *e<=122)||(*e>=65 && *e<=90))
    	{
    		p[i]=*e;
    		++i;
		}
		else if(*e=='(')
		{
			push(*e);
		}
		else if(*e==')')
		{
			while(a[top]!='(')
			{
				j=pop();
				p[i]=j;
				++i;
			}
			--top;
		}
		else
		{
			while(priority(a[top])>=priority(*e))
			{
				if((priority(a[top])==priority(*e)) && priority(*e)!=3)
				{
					p[i]=pop();
					++i;
				}
				else
				{
				p[i]=pop();
				++i;
			    }
			}
			push(*e);
		} 
	  ++e;	
	}
	while(top>-1)
	{
		p[i]=pop();
		++i;
	}   
	printf("The postfix expression is: %s\n",p); 
	return 0;
}
