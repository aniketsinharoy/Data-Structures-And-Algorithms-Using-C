//Name: Aniket Sinha Roy
//CSE 4th sem
//Roll: 73
#include<stdio.h>
void swap(int *i,int *j)
{
	int t;
	t=*i;
	*i=*j;
	*j=t;
}
void heap_sort(int a[],int n)
{
	int i,j,parent_node;
	int left_child,right_child;
	for(i=1;i<n;++i)   // ************************************Creating Maxheap from the given array*******************************
	{
		if(i%2==1)                             // if index i is odd, then its parent is i/2
		{
			parent_node=i/2;                             
			if(a[parent_node]>=a[i])         // if parent of i (a[parent_node]) is greater than the current number (a[i]) do nothing
			{
				continue;
			}
			else
			{
				j=i;
				while(a[j]>a[parent_node] && parent_node>=0)     // if parent of i (a[parent_node]) is less than the current number (a[i]) then
				{                                               //  swap it untill parent is greater than its children
					swap(&a[j],&a[parent_node]);
					j=parent_node;                       //current index -> parent index
					if(parent_node%2==1)
					{
						parent_node=parent_node/2;                // parent index -> parent's parent index
					}
					else
					{
						if(j==0)            // when we reach the final parent (root node) then break
						{
							break;
						}
						else
						{
							parent_node=parent_node/2-1;          // parent index -> parent's parent index
						}
						
					}
				}
			}
		}
		else
		{
			parent_node=(i/2)-1;                    // if index i is even, then its parent is i/2 -1
			if(a[parent_node]>=a[i])
			{
				continue;
			}
			else
			{
				j=i;
				while(a[j]>a[parent_node] && parent_node>=0)     // if parent of i (a[parent_node]) is less than the current number (a[i]) then 
				{                                               // swap it untill parent is greater than its children
					swap(&a[j],&a[parent_node]);
					j=parent_node;                            //current index -> parent index
					if(parent_node%2==1)
					{
						parent_node=parent_node/2;                       // parent index -> parent's parent index
					}
					else
					{
						if(j==0)                    // when we reach the final parent (root node) then break
						{
							break;
						}
						else
						{
							parent_node=parent_node/2-1;                      // parent index -> parent's parent index
						}
						
					}
				}
			}
		}
	}
	for(i=0;i<n;++i)           //**********************************delete element from maxheap******************************************
	{
		j=0;                               //delete the root node from maxheap
		left_child=2*j+1;                  
		right_child=2*j+2;
		swap(&a[n-i-1],&a[j]);            //swap last node of maxheap with delete node(one space is free)
		while(((a[j]<a[left_child] || a[j]<a[right_child]) && (left_child<n-i-1 && right_child<n-i-1)) || (a[j]<a[left_child] && left_child<n-i-1))    
		{                                                                   //if children are greater than parent then swap the elements  
			if(a[left_child]>=a[right_child] || right_child>=n-i-1)        //see which child is greater, swap with it
			{
				swap(&a[j],&a[left_child]);
				j=left_child;
				left_child=2*j+1;
		        right_child=2*j+2;
			}
			else
			{
				swap(&a[j],&a[right_child]);
				j=right_child;
				left_child=2*j+1;
		        right_child=2*j+2;
			}
		} 
	}  
}
int main()
{
	int a[100];
	int i,no_of_elements;
	printf("Enter number of elements: ");
	scanf("%d",&no_of_elements);
	printf("\nEnter the elements: ");
	for(i=0;i<no_of_elements;++i)
	{
		scanf("%d",&a[i]);
	}
	heap_sort(a,no_of_elements);
	printf("\nAfter sorting: \n\n");
	for(i=0;i<no_of_elements;++i)
	{
		printf("%d ",a[i]);
	}
}
/*
5
10
20
15
30
40
*/
