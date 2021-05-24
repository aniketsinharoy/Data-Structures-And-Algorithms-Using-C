//Name: Aniket Sinha Roy
// CSE 2nd year
//roll: 60
//assignment: 19 (binary search tree : insert, preorder, inorder, postorder)
#include<stdio.h>
#include<stdlib.h>
struct node *tree_root=NULL;
struct node
{
	int a;
	struct node *left;
	struct node *right;
};
void insert(int n)
{
	struct node *temp, *parent_node, *node_ptr;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->a=n;
	temp->left=NULL;
	temp->right=NULL;
	if(tree_root==NULL)
	{
		tree_root=temp;
	}
	else
	{
		parent_node=NULL;
		node_ptr=tree_root;
		while(node_ptr!=NULL)
		{
			parent_node=node_ptr;
			if(n<node_ptr->a)
			{
				node_ptr=node_ptr->left;
			}
			else
			{
				node_ptr=node_ptr->right;
			}
		}
		if(n<parent_node->a)
		{
			parent_node->left=temp;
		}
		else
		{
			parent_node->right=temp;
		}
	}
}
void preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d\t",root->a);
		preorder(root->left);
		preorder(root->right);
	}
	else
	{
		return;
	}
}
void inorder(struct node *root)
{
	if(root!=NULL)
	{
	    inorder(root->left);
	    printf("%d\t",root->a);
	    inorder(root->right);
	}
	else
	{
		return;
	}
}
void postorder(struct node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->a);
	}
	else
	{
		return;
	}
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
		printf( "1)Insert an element in binary search tree \n2)Preorder traversal \n3)Inorder traversal \n4)Postorder traversal \n5)Exit \n");
	    scanf("%d",&i);
	    printf("\n");
		switch(i)
		{
			case 1:
				{
					printf("enter the element to be inserted: \n");
					scanf("%d",&n);
					insert(n);
					break;
				}
			case 2:
			    {
			    	preorder(tree_root);
			    	break;
				}  
			case 3:
			   {
				    inorder(tree_root);
				    break;
			   }  
			case 4:
				{
					postorder(tree_root);
					break;
				}
			case 5:
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
		printf("\nwant to do again(y/n): ");
		scanf(" %c",&c);
	}
	while((c=='y') || (c=='Y'));
	return 0;
}
