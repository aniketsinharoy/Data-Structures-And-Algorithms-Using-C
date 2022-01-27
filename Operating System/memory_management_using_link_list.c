#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct node
{
    int p_id;
    int p_starting_address;
    int p_size;
    struct node *next;
};

int total_memory_size=1000;
int memory_size_in_use=200;

struct node *original_head=NULL;
struct node *original_save=NULL;

struct node *first_fit_head=NULL;
struct node *first_fit_save=NULL;

struct node *best_fit_head=NULL;
struct node *best_fit_save=NULL;

struct node *worst_fit_head=NULL;
struct node *worst_fit_save=NULL;

void insert(int id,int size)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->p_id=id;
    temp->p_size=size;
    if(original_head==NULL)
    {
        original_head=temp;
        original_save=temp;
        temp->next=NULL;
        temp->p_starting_address=200;
    }
    else
    {
        original_save->next=temp;
        temp->p_starting_address=original_save->p_starting_address+original_save->p_size;
        temp->next=NULL;
        original_save=temp;
    }
}
void merge_holes()
{
    if(original_head!=NULL)
    {
        struct node *temp;
        struct node *next_temp;
        temp=original_head;
        next_temp=temp->next;
        while(next_temp!=NULL)
        {
            if(temp->p_id==-1 && next_temp->p_id==-1)
            {
                temp->p_size=temp->p_size+next_temp->p_size;
                temp->next=next_temp->next;
                free(next_temp);
                next_temp=temp->next;
            }
            else
            {
                temp=next_temp;
                next_temp=next_temp->next;
            }
        }
    }
}
void copy_link_list()
{
    if(original_head!=NULL)
    {
        struct node *temp_original;
        temp_original=original_head;
        while(temp_original!=NULL)
        {
            struct node *temp_first_fit;
            struct node *temp_best_fit;
            struct node *temp_worst_fit;
            temp_first_fit=(struct node*)malloc(sizeof(struct node));
            temp_best_fit=(struct node*)malloc(sizeof(struct node));
            temp_worst_fit=(struct node*)malloc(sizeof(struct node));
            
            temp_best_fit->p_id=temp_original->p_id;
            temp_best_fit->p_size=temp_original->p_size;
            temp_best_fit->p_starting_address=temp_original->p_starting_address;
            temp_best_fit->next=NULL;

            temp_first_fit->p_id=temp_original->p_id;
            temp_first_fit->p_size=temp_original->p_size;
            temp_first_fit->p_starting_address=temp_original->p_starting_address;
            temp_first_fit->next=NULL;

            temp_worst_fit->p_id=temp_original->p_id;
            temp_worst_fit->p_size=temp_original->p_size;
            temp_worst_fit->p_starting_address=temp_original->p_starting_address;
            temp_worst_fit->next=NULL;

            if(temp_original==original_head)
            {
                best_fit_head=temp_best_fit;
                best_fit_save=temp_best_fit;

                first_fit_head=temp_first_fit;
                first_fit_save=temp_first_fit;

                worst_fit_head=temp_worst_fit;
                worst_fit_save=temp_worst_fit;
            }
            else
            {
                best_fit_save->next=temp_best_fit;
                best_fit_save=temp_best_fit;

                first_fit_save->next=temp_first_fit;
                first_fit_save=temp_first_fit;

                worst_fit_save->next=temp_worst_fit;
                worst_fit_save=temp_worst_fit;
            }
            temp_original=temp_original->next;
        }
    }
}
void first_fit(int id,int size)
{
    struct node *temp;
    struct node *temp_previous;
    temp=first_fit_head;
    int allocate=0;
    while(temp!=NULL)
    {
        if((temp->p_id==-1)&&(temp->p_size>=size))
        {
            if(temp->p_size==size)
            {
                temp->p_id=id;
            }
            else
            {
                struct node *newtemp;
                newtemp=(struct node*)malloc(sizeof(struct node));
                newtemp->p_id=id;
                newtemp->p_size=size;
                newtemp->p_starting_address=temp->p_starting_address;
                if(temp==first_fit_head)
                {
                    first_fit_head=newtemp;
                }
                else
                {
                    temp_previous->next=newtemp;
                }
                newtemp->next=temp;
                temp->p_starting_address=newtemp->p_starting_address+size;
                temp->p_size=temp->p_size-size;
            }
            allocate=1;
            break;
        }
        temp_previous=temp;
        temp=temp->next;
    }
    if(allocate==0)
    {
        printf("Unable to allocate memory to the process!!!\n");
    }
}
void best_fit(int id,int size)
{
    int least_size_allocation=INT_MAX;
    struct node *temp;
    struct node *temp_previous=NULL;
    struct node *destination;
    struct node *destination_previous;
    int allocation=0;
    temp=best_fit_head;
    while(temp!=NULL)
    {
        if(temp->p_id==-1 && temp->p_size>=size)
        {
            if(temp->p_size==size)
            {
                temp->p_id=id;
                allocation=1;
                break;
            }
            else
            {
                if(temp->p_size<least_size_allocation)
                {
                    least_size_allocation=temp->p_size;
                    destination=temp;
                    destination_previous=temp_previous;
                    allocation=2;
                }
            }
        }
        temp_previous=temp;
        temp=temp->next;
    }
    if(allocation==2)
    {
        struct node *newtemp;
        newtemp=(struct node*)malloc(sizeof(struct node));
        newtemp->p_id=id;
        newtemp->p_size=size;
        newtemp->p_starting_address=destination->p_starting_address;
        if(destination_previous==NULL)
        {
            best_fit_head=newtemp;
        }
        else
        {
            destination_previous->next=newtemp;
        }
        newtemp->next=destination;
        destination->p_starting_address=newtemp->p_starting_address+size;
        destination->p_size=destination->p_size-size;
    }
    if(allocation==0)
    {
        printf("Unable to allocate memory to the process!!!\n");
    }
    
}
void worst_fit(int id,int size)
{
    int max_size_allocation=INT_MIN;
    struct node *temp;
    struct node *temp_previous=NULL;
    struct node *destination;
    struct node *destination_previous;
    int allocation=0;
    temp=worst_fit_head;
    while(temp!=NULL)
    {
        if(temp->p_id==-1 && temp->p_size>=size)
        {
            if(temp->p_size>max_size_allocation || allocation==0)
            {
                max_size_allocation=temp->p_size;
                destination=temp;
                destination_previous=temp_previous;
                allocation=1;
            }
            
        }
        temp_previous=temp;
        temp=temp->next;
    }
    if(allocation==1)
    {
        if(size==max_size_allocation)
        {
            destination->p_id=id;
        }
        else
        {
            struct node *newtemp;
            newtemp=(struct node*)malloc(sizeof(struct node));
            newtemp->p_id=id;
            newtemp->p_size=size;
            newtemp->p_starting_address=destination->p_starting_address;
            if(destination_previous==NULL)
            {
                worst_fit_head=newtemp;
            }
            else
            {
                destination_previous->next=newtemp;
            }
            newtemp->next=destination;
            destination->p_starting_address=newtemp->p_starting_address+size;
            destination->p_size=destination->p_size-size;
        }
    }
    else
    {
        printf("Unable to allocate memory to the process!!!\n");
    }
}
void display_original()
{
    printf("\nSnapshot of memory at a partical instance of time:");
    printf("\n-------+----------------------+----------+-------------\n");
    printf("  PID  |  P_STARTING_ADDRESS  |  P_SIZE  |  COMMENT  \n");
    printf("-------+----------------------+----------+-------------\n");
    if(original_head==NULL)
    {
        printf("  0    |           0          |    200   |   OS  \n");
    }
    else
    {
        printf("  0    |           0          |    200   |   OS  \n");
        struct node *temp;
        temp=original_head;
        while(temp!=NULL)
        {
            if(temp->p_id!=-1)
            {
                printf("  %d    |         %d          |    %03d   |  Process\n",temp->p_id,temp->p_starting_address,temp->p_size);
            }
            else
            {
                printf(" %d    |         %d          |    %03d   |  Hole\n",temp->p_id,temp->p_starting_address,temp->p_size);
            }
            temp=temp->next;
        }
    }
}
void display_best_fit()
{
     printf("\nAfter applying Best Fit:");
    printf("\n-------+----------------------+----------+-------------\n");
    printf("  PID  |  P_STARTING_ADDRESS  |  P_SIZE  |  COMMENT  \n");
    printf("-------+----------------------+----------+-------------\n");
    if(best_fit_head==NULL)
    {
        printf("  0    |           0          |    200   |   OS  \n");
    }
    else
    {
        printf("  0    |           0          |    200   |   OS  \n");
        struct node *temp;
        temp=best_fit_head;
        while(temp!=NULL)
        {
            if(temp->p_id!=-1)
            {
                printf("  %d    |         %d          |    %03d   |  Process\n",temp->p_id,temp->p_starting_address,temp->p_size);
            }
            else
            {
                printf(" %d    |         %d          |    %03d   |  Hole\n",temp->p_id,temp->p_starting_address,temp->p_size);
            }
            temp=temp->next;
        }
    }
}
void display_first_fit()
{
     printf("\nAfter applying First Fit:");
    printf("\n-------+----------------------+----------+-------------\n");
    printf("  PID  |  P_STARTING_ADDRESS  |  P_SIZE  |  COMMENT  \n");
    printf("-------+----------------------+----------+-------------\n");
    if(first_fit_head==NULL)
    {
        printf("  0    |           0          |    200   |   OS  \n");
    }
    else
    {
        printf("  0    |           0          |    200   |   OS  \n");
        struct node *temp;
        temp=first_fit_head;
        while(temp!=NULL)
        {
            if(temp->p_id!=-1)
            {
                printf("  %d    |         %d          |    %03d   |  Process\n",temp->p_id,temp->p_starting_address,temp->p_size);
            }
            else
            {
                printf(" %d    |         %d          |    %03d   |  Hole\n",temp->p_id,temp->p_starting_address,temp->p_size);
            }
            temp=temp->next;
        }
    }
}
void display_worst_fit()
{
    printf("\nAfter applying Worst Fit:");
    printf("\n-------+----------------------+----------+-------------\n");
    printf("  PID  |  P_STARTING_ADDRESS  |  P_SIZE  |  COMMENT  \n");
    printf("-------+----------------------+----------+-------------\n");
    if(worst_fit_head==NULL)
    {
        printf("  0    |           0          |    200   |   OS  \n");
    }
    else
    {
        printf("  0    |           0          |    200   |   OS  \n");
        struct node *temp;
        temp=worst_fit_head;
        while(temp!=NULL)
        {
            if(temp->p_id!=-1)
            {
                printf("  %d    |         %d          |    %03d   |  Process\n",temp->p_id,temp->p_starting_address,temp->p_size);
            }
            else
            {
                printf(" %d    |         %d          |    %03d   |  Hole\n",temp->p_id,temp->p_starting_address,temp->p_size);
            }
            temp=temp->next;
        }
    }
}
void release_memory()
{
    if(original_head!=NULL)
    {
        struct node *temp=original_head;
        struct node *next_temp;
        while(temp!=NULL)
        {
            next_temp=temp->next;
            free(temp);
            temp=next_temp;
        }
        original_head=NULL;
        original_save=NULL;
    }
    if(best_fit_head!=NULL)
    {
        struct node *temp=best_fit_head;
        struct node *next_temp;
        while(temp!=NULL)
        {
            next_temp=temp->next;
            free(temp);
            temp=next_temp;
        }
        best_fit_head=NULL;
        best_fit_save=NULL;
    }
    if(first_fit_head!=NULL)
    {
        struct node *temp=first_fit_head;
        struct node *next_temp;
        while(temp!=NULL)
        {
            next_temp=temp->next;
            free(temp);
            temp=next_temp;
        }
        first_fit_head=NULL;
        first_fit_save=NULL;
    }
    if(worst_fit_head!=NULL)
    {
        struct node *temp=worst_fit_head;
        struct node *next_temp;
        while(temp!=NULL)
        {
            next_temp=temp->next;
            free(temp);
            temp=next_temp;
        }
        worst_fit_head=NULL;
        worst_fit_save=NULL;
    }
}
int main()
{
    int total_p_and_hole;
    int p_id,p_size;
    printf("Enter total number of processes and holes present in the RAM: ");
    scanf("%d",&total_p_and_hole);
    while(total_p_and_hole>0)
    {
        printf("Enter Process ID (if hole enter -1): ");
        scanf("%d",&p_id);
        printf("Enter the process/hole size: ");
        scanf("%d",&p_size);
        if(memory_size_in_use+p_size<=total_memory_size && p_id!=0)
        {
            insert(p_id,p_size);
            memory_size_in_use=memory_size_in_use+p_size;
            --total_p_and_hole;
            if(total_p_and_hole>0 && memory_size_in_use==total_memory_size)
            {
                printf("No more process can be alloacted memory is full...\n");
                break;
            }
        }
        else
        {
            if(p_id==0)
            {
                printf("Process Id cannot be 0!!!\n");
            }
            else
            {
                printf("Unable to allocate memory to process/hole!!!\n");
            }
        }
    }
    if(memory_size_in_use<total_memory_size)
    {
        p_size=total_memory_size-memory_size_in_use;
        insert(-1,p_size);
    }
    merge_holes();
    copy_link_list();
    int total_processes;
    printf("Enter total number of processes to enter in the RAM: ");
    scanf("%d",&total_processes);
    while(total_processes>0)
    {
        printf("Enter Process ID: ");
        scanf("%d",&p_id);
        printf("Enter the process size: ");
        scanf("%d",&p_size);
        first_fit(p_id,p_size);
        best_fit(p_id,p_size);
        worst_fit(p_id,p_size);
        --total_processes;
    }
    display_original();
    display_first_fit();
    display_best_fit();
    display_worst_fit();
    release_memory();
    return 0;
}