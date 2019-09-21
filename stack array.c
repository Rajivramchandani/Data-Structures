#include <stdio.h>
#include<string.h>
#define MAX 10
struct stack
{
    int stk[MAX];
    int top;
};
typedef struct stack STACK;
STACK s;

void push(void);
int pop(void);
void display(void);
void main()
{
    int choice,i;
    int n,rem;
    char str[20];
    int option=1;
    s.top=-1;
    while (option)
    {
        printf("Enter choice\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
		printf("4.Exit\n");
        printf("\nEnter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4: return;
    	}
        fflush(stdin);
        printf("Do you want to continue(Type 0 or 1)?\n");
        scanf("%d", &option);
    }
}
void push ()
{
    int num,i;
    if (s.top==(MAX-1))
    {
        printf("Stack is Full\n");
        return;
    }
    else
    {
	    printf ("Enter the element to be pushed\n");
	    scanf ("%d", &num);
	    s.top=s.top+1;
	    s.stk[s.top] = num;
    }
    return;
}
int pop ()
{
    int num;
    if (s.top==-1)
    {
        printf("Stack is Empty\n");
        return(s.top);
    }
    else
    {
        num=s.stk[s.top];
        printf("poped element is=%d\n",s.stk[s.top]);
        s.top=s.top - 1;
    }
    return(num);
}

void display ()
{
    int i;
    if (s.top==-1)
    {
        printf ("Stack is empty\n");
        return;
    }
    else
    {
        printf ("\n The status of the stack is \n");
        for (i=s.top;i>=0;i--)
        {
            printf("%d\n",s.stk[i]);
        }
    }
    printf ("\n");
}

