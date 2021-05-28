//Name: Aniket Sinha Roy
//CSE 4th sem
//Roll: 73
#include<stdio.h>
int main()
{
	int transitation_table[11][11];
	int initial_stage, no_of_final_stage, no_of_stages;
	int final_stages[10],current_stage;
	int i,j,k,flag,no_of_alphabet;
	char alpha[10];
	char string[50];
	printf("Enter the number of alphabets:");
	scanf("%d",&no_of_alphabet);
	printf("Enter the alphabets:");
	for(i=0;i<no_of_alphabet;++i)
	{
		scanf(" ");
		scanf("%c",&alpha[i]);	
	}
	
	
	//Stages must be given in numbers
	
	
	printf("Enter the number of states:");
	scanf("%d",&no_of_stages);
	printf("Enter the initial stage(in number):");
	scanf("%d",&initial_stage);
	printf("Enter number of final stage:");
	scanf("%d",&no_of_final_stage);
	printf("Enter the final stage(s)(in number):");
		for(i=0;i<no_of_final_stage;++i)
	{
		scanf("%d",&final_stages[i]);	
	}
	printf("Enter the transitation table:\n");
	for(i=0;i<no_of_stages;++i)
	{
		for(j=0;j<no_of_alphabet;++j)
	       {
			  printf("Stage: %d  Alphabet selected: %c",i,alpha[j]);
			  printf("  Next stage selected: ");
			  scanf("%d",&transitation_table[i][j]);
			  printf("\n");
	       }
	} 

	printf("Given transition table:\n");
	printf("     | ");
	for(i=0;i<no_of_alphabet;++i)
	{
		printf(" %c\t",alpha[i]);
	}  
	printf("\n----------------------------------------------------\n");
	for(i=0;i<no_of_stages;++i)
	{
		flag=0;
		for(j=0;j<no_of_final_stage;++j)
		{
			if(i==final_stages[j])
			 {
			if(i==initial_stage)
				{
					printf("->*%d | ",i);
					flag=2;
				}
			else
				{
				    printf("* %d  | ",i);
				    flag=1;
			    }
				break;
			 }
		}
		
		if(i==initial_stage && flag!=2)
		{
			printf("->%d  | ",i);
			flag=3;
		}
		if(flag==0)
		{
			printf("  %d  | ",i);
		}
		for(j=0;j<no_of_alphabet;++j)
	       {
			  printf(" %d\t",transitation_table[i][j]);  
	       }
	       printf("\n");
	}  
	printf("Enter the checking string: ");
	scanf("%s",&string);
	current_stage=initial_stage;
	for(i=0;string[i]!='\0';++i)
	{
		for(j=0;j<no_of_stages;++j)
		{
			if(current_stage==j)
			{
				for(k=0;k<no_of_alphabet;++k)
				{
					if(string[i]==alpha[k])
					{
						current_stage=transitation_table[j][k];
						flag=5;
						break;
					}
				}
				if(flag==5)
				{
					break;
				}
			}
		}
	}
	for(i=0;i<no_of_final_stage;++i)
	{
		if(current_stage==final_stages[i])
		{
			printf("\n");
			printf("String accepted for the given DFA.");
			flag=10;
			break;
		}
	}
	if(flag!=10)
	{
		printf("String not accepted for the given DFA.");
	}
	return 0;
}
