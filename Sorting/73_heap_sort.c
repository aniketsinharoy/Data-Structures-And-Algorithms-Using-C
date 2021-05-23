//Name: Aniket Sinha Roy
//CSE 2nd year 
//Roll:73
//Assignment:3
#include <stdio.h>
void swap(int *a, int *b) 
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
  
void heapify(int arr[], int n, int i) 
{
    int max = i; 
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
  
    
    if (leftChild < n && arr[leftChild] > arr[max])
      max = leftChild;
  

    if (rightChild < n && arr[rightChild] > arr[max])
      max = rightChild;
  

    if (max != i) {
      swap(&arr[i], &arr[max]);
      heapify(arr, n, max);
    }
}

  
void heapSort(int arr[], int n) 
{
    int i;
    for(i=n/2-1;i>=0;i--)
      heapify(arr, n, i);
 
    for(i =n-1;i>=0;i--) 
	{
      swap(&arr[0], &arr[i]); 
      heapify(arr, i, 0); 
    }
  }
void display(int arr[], int n) 
{
	int i;
    for(i=0;i<n;++i)
    {
      printf("%d ", arr[i]);
      printf("\n");
    }
}

int main() 
{
    int arr[100],n,j;
    printf("How many elements do you want to enter: ");
	scanf("%d",&n);
	printf("\nEnter the elements :\n");
	for(j=0;j<n;++j)
	{
		scanf("%d",&arr[j]);
	}
    printf("Original array:\n");
    display(arr, n);
    heapSort(arr, n);
    printf("Sorted array:\n");
    display(arr, n);
    return 0;
}

