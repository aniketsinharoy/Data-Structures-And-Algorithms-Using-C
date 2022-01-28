#include<stdio.h>
#include<string.h>
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
	char p[50],pix[50],pp[50];
	int i,j;
	char *e;
	char x;
    printf("Enter the infix expression:\n");
    scanf("%s",&pp);
    i=strlen(pp)-1;
    j=-1;
    while(i>=0)
    {
    	++j;
    	if(pp[i]=='(')
    	{
    		ex[j]=')';
		}
		else if(pp[i]==')')
		{
			ex[j]='(';
		}
		else
		{
		ex[j]=pp[i];
		}
    	--i;
	}
    e=ex;
    i=0;
    j=0;
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
	i=strlen(p)-1;
	j=0;
	while(i>=0)
	{
		pix[j]=p[i];
		++j;
		--i;
	}
	printf("The prifix expression is: %s",pix);
	return 0;
}
