// name: Aniket Sinha Roy
// CSE 4th sem
//roll: 73
//assignment: 7
#include<stdio.h>
const int M=3;
const int N=21;
int partition(int l,int h,int a[M][N])
 {
  int p=a[2][h];
  int s=l,e=h;
  int t;
     while(s<e)
      {
            while(a[2][s]<p)
             {
                ++s;
             }
           while(a[2][e]>=p)
            {
               --e;
            }
            if(s<e)
            {
                t=a[2][s];
                a[2][s]=a[2][e];
                a[2][e]=t;  

                t=a[0][s];
                a[0][s]=a[0][e];
                a[0][e]=t;

                t=a[1][s];
                a[1][s]=a[1][e];
                a[1][e]=t;  
            }
       }
    t=a[2][h];
    a[2][h]=a[2][s];
    a[2][s]=t;

    t=a[0][h];
    a[0][h]=a[0][s];
    a[0][s]=t;

    t=a[1][h];
    a[1][h]=a[1][s];
    a[1][s]=t;  

    return e;
 }
void qsort(int l,int h,int a[M][N])
 {
   int d;
   if(l<h)
     {
        d=partition(l,h,a);
        qsort(l,d-1,a);
        qsort(d+1,h,a);
     }
 }
int main()
{
  int i,j,m=0;
  int no_of_activity;
  int activity_matrix[3][21];
  printf("Enter number of activity: ");
  scanf("%d",&no_of_activity);
  for(i=0;i<no_of_activity;++i)
  {
      activity_matrix[0][i]=i+1;
      printf("\nEnter starting time of activity %d :",i+1);
      scanf("%d",&activity_matrix[1][i]);
      printf("\nEnter ending time of activity %d :",i+1);
      scanf("%d",&activity_matrix[2][i]);
  }
  printf("\n\n");
  for(i=0;i<3;++i)
  {
    if(i==0)
      {
        printf("Activity No    :  ");
      }
   if(i==1)
     {
    printf("Starting Time  :  ");
     }
   if(i==2)
     {
    printf("Ending Time    :  ");
     }
    for(j=0;j<no_of_activity;++j)
     {
         printf("%d\t",activity_matrix[i][j]);
     }
    printf("\n");
  } 
printf("\n\n"); 
qsort(0,no_of_activity-1,activity_matrix);
printf("The activity sequence is: %d\t",activity_matrix[0][0]);
for(i=1;i<no_of_activity;++i)
 {
	if(activity_matrix[1][i]>=activity_matrix[2][m])
	{
		printf("%d\t",activity_matrix[0][i]);
		m=i;
	}
 }
 return 0;
}

