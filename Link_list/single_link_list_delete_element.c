//name:Aniket Sinha Roy
//CSE 2nd year
//Roll:60
//assignment: 6
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*link;
};
struct node* append(struct node *root)
{
	struct node* temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("enter Node:\n");
	scanf("%d",&(temp->data));
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node *p;
		p=root;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
	}
	return root;
}
int no_of_nodes(int count,struct node* root)
{
	struct node *s;
	s=root;
	while(s!=NULL)
	{
		count++;
		s=s->link;
	}
	return count;
}
struct node* add_at_begin(struct node* root)
{
	struct node *temp1;
	temp1=(struct node *)malloc(sizeof(struct node));
	printf("enter Node:\n");
	scanf("%d",&(temp1->data));
	temp1->link=NULL;
	if(root==NULL)
	{
		root=temp1;
	}
	else
	{
		temp1->link=root;
		root=temp1;
	}
	return root;
}
struct node *add_in_middle(struct node *root,int loc)
{
	int j=1,k=0;
	struct node *temp2;
	temp2=(struct node *)malloc(sizeof(struct node));
	printf("enter Node:\n");
	scanf("%d",&(temp2->data));
	temp2->link=NULL;
	if(root==NULL)
	{
		root=temp2;
	}
	else
	{
		struct node *q;
		q=root;
		while(j<loc)
		{
			q=q->link;
			j++;
		}
		temp2->link=q->link;
		q->link=temp2;
	}
	return root;
}
void display(struct node* root)
{
	struct node *m;
	m=root;
	if(root==NULL)
	{
		printf("no elements found\n");
	}
	else
	{
		printf("the nodes are:\n");
		while(m!=NULL)
		{
			printf("%d\n",m->data);
			m=m->link;
		}
	}
}
struct node* create(struct node* root,int n)
{
	int a,j;
	struct node* temp,*p;
	printf("enter datas:\n");
	for(j=0;j<n;j++)
	{
		temp=(struct node *)malloc(sizeof(struct node));
	    scanf("%d",&a);
	    temp->data=a;
	    if(j==0)
	    {
	    	root=temp;
	    	p=temp;
		}
		else
		{
		    p->link=temp;
		    p=temp;
	    }
	}
    temp->link=NULL;
    return root;
}
struct node *front_del(struct node *root)
{
	struct node* p;
	p=root;
	if(root==NULL)
	{
		printf("no element to be deleted\n");
	}
	else if(root->link==NULL)
	{
		root=NULL;
		printf("no element present now after deletion\n");
	}
	else
	{
		root=p->link;
	}
	return root;	
}
struct node* end_del(struct node* root)
{
	struct node* q;
	q=root;
	if(root==NULL)
	{
		printf("no element to be deleted\n");
	}
	else if(root->link==NULL)
	{
		root=NULL;
		printf("no element present now after deletion\n");
	}
	else
	{
		struct node *r;
		while((q->link)->link!=NULL)
		{
			q=q->link;
		}
		q->link=NULL;
	}
	return root;
}
int search(struct node* root,int s)
{
	int k=1;
	struct node *ptr;
	ptr=root;
	if(root==NULL)
	{
		printf("there is no element:\n");
	}
	else
	{
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
			if(ptr->data==s)
			break;
			k++;
		}
	}
	return k;
}
struct node* del_after_key(struct node* root,int s)
{
	struct node *t;
	t=root;
	if(root==NULL)
	{
		printf("there is no element:\n");
	}
	else
	{
		while(t->link!=NULL)
		{
			if(t->data==s)
			{
				t->link=(t->link)->link;
				break;
		    }
		    t=t->link;
		}
		printf("element nit present\n");
		return root;
	}
}
struct node* del_before_key(struct node* root,int s)
{
	struct node *x,*y;
	x=root;
	y=root;
	int l=0,m=1;
	while(x!=NULL)
	{
		if(x->data==s)
		{
			while(m<=l-2)
			{
				y=y->link;
				m++;
			}
			y->link=(y->link)->link;
		    break;
	    }
	    l++;
		x=x->link;
	}
	return root;
}
int main ()
{
	int i;
	struct node* root=NULL;
	do
	{
	printf("enter operation:\n1)creating linked list\n2)delete from front\n3)delete from end\n4)search for given element\n5)delete after search\n6)delete before search\n7)display\n8)exit\n");
	scanf("%d",&i);
	switch(i)
	{
		case 1:
		{
			int n;
			printf("enter number of nodes:\n");
			scanf("%d",&n);
			root=create(root,n);
		    break;		
		}
		case 2:
		{
			root=front_del(root);
			printf("deleting from front...\n");	
			break;
		}
		case 3:
		{
			root=end_del(root);
			printf("deleting form end...\n");
			break;
		}
		case 4:
		{
			int s,o;
			printf("enter search element:\n");
			scanf("%d",&s);
			o=search(root,o);
			printf("%d is present in %dnd node\n",s,o);
			break;
		}
		case 5:
		{
			int s;
			printf("enter search element:\n");
			scanf("%d",&s);
			root=del_after_key(root,s);
			printf("deleting after search...\n");
			break;
		}
		case 6:
		{
			int s;
			printf("enter search element:\n");
			scanf("%d",&s);
			root=del_before_key(root,s);
			printf("deleting before search...\n");
			break;
		}	
		case 7:
		{
			display(root);
			break;
		}
		case 8:
		{
			printf("process is exited\n");
		    break;	
		}	
		default:
		{
			printf("wrong input");
			break;
		}
	}
    }
    while(i!=8);
    return 0;
}
