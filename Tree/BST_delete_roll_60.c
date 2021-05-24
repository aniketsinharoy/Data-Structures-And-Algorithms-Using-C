//Name: Aniket Sinha Roy
// CSE 2nd year
//roll: 60
//assignment: 20 (binary search tree : insert, delete, preorder, inorder, postorder)
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
struct node* min_val(struct node *node)
{
	struct node *c;
	c=node;
	while(c && c->left!=NULL)
	{
		c=c->left;
	}
	return c;
}
struct node* del(struct node *root,int key)
{
   	if(root==NULL)
   	{
   		return root;
	}
	else
	{
	if(key<root->a)
	{
		root->left=del(root->left,key);
	}
	else if(key>root->a)
	{
		root->right=del(root->right,key);
	}
	else {
        if (root->left == NULL) 
		{
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) 
		{
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = min_val(root->right);
        root->a = temp->a;
        root->right = del(root->right, temp->a);
    }
    return root;
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
}
void inorder(struct node *root)
{
	if(root!=NULL)
	{
	    inorder(root->left);
	    printf("%d\t",root->a);
	    inorder(root->right);
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
		printf( "1)Insert an element in binary search tree \n2)Delete an element from binary search tree \n3)Preorder traversal \n4)Inorder traversal \n5)Postorder traversal \n6)Exit \n");
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
            		printf("enter the element to be deleted: \n");
					scanf("%d",&n);
					if(tree_root!=NULL)
					{
					tree_root=del(tree_root,n);
					printf("Element deleted from binary search tree.\n");
				    }
					else
					{
						printf("Binary Search tree is empty\n");
					}
					break;
				}
			case 3:
			    {
			    	preorder(tree_root);
			    	break;
				}  
			case 4:
			   {
				    inorder(tree_root);
				    break;
			   }  
			case 5:
				{
					postorder(tree_root);
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
		printf("\nwant to do again(y/n): ");
		scanf(" %c",&c);
	}
	while((c=='y') || (c=='Y'));
	return 0;
}
