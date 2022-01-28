 /*construct a binary search tree
find the smallest element 
find the largest element
display mirror image of the tree
count total nodes of the tree
count total external nodes of the tree
count total internal nodes of the tree
calculate height of the tree
delete the tree*/

#include<stdio.h>
#include<stdlib.h>
struct node *tree_root=NULL;
struct node *tree_mirror_root=NULL;
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
struct node* findSmallestElement(struct node *tree)
{
    if( (tree == NULL) || (tree->left == NULL))
        return tree; 
	else
       return findSmallestElement(tree ->left);
}
struct node* findLargestElement(struct node *tree)
{

    if( (tree == NULL) || (tree->right == NULL))
        return tree; 
	else
        return findLargestElement(tree->right);
}
int totalNodes (struct node *tree)
{
    if(tree==NULL)
       return 0; 
	else
       return(totalNodes (tree->left) + totalNodes (tree->right) + 1); 
}
int totalExternalNodes (struct node *tree)
{
    if(tree==NULL)
       return 0; 
	else if((tree->left==NULL) && (tree->right==NULL))
       return 1; 
	else
       return (totalExternalNodes (tree->left) + totalExternalNodes (tree->right));
}
int totalInternalNodes (struct node *tree)
{
    if( (tree==NULL) || ((tree->left==NULL) && (tree->right==NULL)))
        return 0; 
	else
        return (totalInternalNodes(tree->left)+totalInternalNodes(tree->right)+1); 
}
int Height(struct node *tree)
{
    int leftheight, rightheight;
    if(tree==NULL)
       return 0; 
	else
	{
       leftheight = Height(tree->left); 
	   rightheight = Height(tree->right); 
	   if(leftheight > rightheight)
          return (leftheight + 1);
        else
          return (rightheight + 1);
    }
}
struct node* mirrorImage(struct node *tree)
{
    struct node *ptr; 
	if(tree!=NULL)
      {
        mirrorImage(tree->left); 
		mirrorImage(tree->right); 
		ptr=tree->left; 
		ptr->left = ptr->right; 
		tree->right=ptr;
	   }
}
struct node *deleteTree(struct node *tree)
{
    if(tree!= NULL)
    {
       deleteTree(tree->left); 
	   deleteTree(tree->right); 
	   free(tree);
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
	struct node *ptr;
	do
	{
		int i,n,m;
		printf("what do you want to do?\n");
		printf( "1)Insert an element in binary search tree construct a binary search tree \n2)Find the smallest element \n3)Find the largest element \n4)Display mirror image of the tree \n5)Count total nodes of the tree \n6)Count total external nodes of the tree \n7)Count total internal nodes of the tree \n8)Calculate height of the tree \n9)Delete the tree \n10)Preorder traversal \n11)Inorder traversal \n12)Postorder traversal \n13)Exit \n");
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
            		ptr=findSmallestElement(tree_root);
            		printf("Smallest element is: %d\n",ptr->a);
					break;
				}
			case 3:
			    {
			    	ptr=findLargestElement(tree_root);
            		printf("Largest element is: %d\n",ptr->a);
					break;
				}  
			case 4:
			   {
				   tree_root=mirrorImage(tree_root);
				   printf("The inorder traversal of mirror image is: \n");
				   inorder(tree_root);
				   tree_root=mirrorImage(tree_root);
			   }  
			case 5:
				{
					printf("Total number of nodes: %d\n",totalNodes(tree_root));
					break;
				}
			case 6:
				{
					printf("Total number of external nodes: %d\n",totalExternalNodes(tree_root));
					break;
				}
			case 7:
				{
					printf("Total number of internal nodes: %d\n",totalInternalNodes(tree_root));
					break;
				}
			case 8:
				{
					printf("Height of tree: %d\n",Height(tree_root));
					break;
				}
			case 9:
				{
					tree_root=deleteTree(tree_root);
					break;
					printf("Tree deleted\n");
				}
			case 10:
				{
					preorder(tree_root);
			    	break;
				}
			case 11:
				{
					inorder(tree_root);
				    break;
				}
			case 12:
				{
					postorder(tree_root);
					break;
				}
			case 13:
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
