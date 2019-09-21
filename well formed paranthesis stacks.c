#include<stdio.h>
#define MAX_SIZE 20
void push(char);
char pop();
int check_well_formedness_parenthesis();
char stack_array[MAX_SIZE];
int top=-1;
int main()
{
	char choice;
	do{
	int valid=0;
	valid=check_well_formedness_parenthesis();
	if(valid==0)
	  printf("\nEntered expression is invalid!");
	else
	 printf("\nEntered expression is valid!");

	 printf("\n Do you want to continue (Y/N)??");
	 scanf("%c",&choice);
	}while(choice=='y'||choice=='Y');
}
void push(char c)
{
	if(top==(MAX_SIZE-1))
	{
	 printf("\nStack is full!");
	 return;
	}
	else
	{
	  top=top+1;
	  stack_array[top]=c;
	}
}
char pop()
{
  if(top==-1)
	{
		printf("\nStack is empty! Pop is not possible");
		return;
	}
	else
	  return stack_array[top--];
}
int check_well_formedness_parenthesis()
{
	char expression[20];
	int valid=0;
	printf("\nEnter an algebraic expression:");
	fflush(stdin);
	gets(expression);
	int i;
	for(i=0;i<strlen(expression);i++)
	{
      if(expression[i]=='('||expression[i]=='{'||expression[i]=='[')
	      push(expression[i]);

	  if(expression[i]==')'||expression[i]=='}'||expression[i]==']')
	  {
	    if(top==-1)
		  valid=0;
		else
		 {
		   char temp;
		   temp=pop();

		   if(expression[i]==')'&&(temp=='{'||temp=='['))
		     valid=0;
		   else if (expression[i]=='}'&&(temp=='('||temp=='['))
		     valid=0;
		   else if(expression[i]==']'&&(temp=='{'||temp=='('))
		     valid=0;
		   else
		     valid=1;
		 }
	  }
	}
	return valid;
}
