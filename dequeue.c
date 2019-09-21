#include<stdio.h>
#define max 5
int insfront(int);
void delfront();
int insrear(int);
void delrear();
void disp();
struct queue{
	int data[max];
	int front;
	int rear;
}q;
int main()
{
	q.front=-1;
	q.rear=-1;
	char c='y';
	int ch, item;
	do
	{
		printf("1.Insert from front \n2.Insert from rear \n3.Delete from front \n4.Delete from rear \n5.Display\nchoice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					if(q.front==MAX-1)
					printf("Overflow!");
					else
					{
						printf("Enter element: ");
						scanf("%d",&item);
						insfront(item);
						printf("Element inserted");
					}
					break;
				}
			case 2:
				{
					if(q.rear==max-1)
					printf("Overflow!");
					else
					{
						printf("Enter element: ");
						scanf("%d",&item);
						insrear(item);
						printf("Element inserted");
					}
					break;
				}
			case 3:
				{
					delfront();
					break;
				}
			case 4:
				{
					delrear();
					break;
				}
			case 5:
				{
					disp();
					break;
				}
		}
		printf("\nContinue? y/n: ");
		fflush(stdin);
		scanf("%c",&c);
		printf("\n");
		if(q.front==max)
		{
			printf("End of queue");
			break;
		}
	}while(c=='y');
}
int insrear(int item)
{
	if(q.front==-1)
	{
		q.front++;
		q.rear++;
		q.data[q.rear]=item;
	}
	else
	{
		q.rear++;
		q.data[q.rear]=item;
	}
}
int insfront(int item)
{
	if(q.front==-1)
	{
		q.front++;
		q.rear++;
		q.data[q.front]=item;
	}
	else
	{
		q.front--;
		q.data[q.front]=item;
	}
}
void delfront()
{
	int item;
	if(q.front==-1)
	printf("Underflow!");
	else if(q.front>q.rear)
	printf("Underflow!");
	else
	{
		item=q.data[q.front];
		q.front++;
		printf("Removed: %d",item);
	}
}
void delrear()
{
	int item;
	if(q.front==-1)
	printf("Underflow!");
	else
	{
		item=q.data[q.rear];
		q.rear--;
		printf("Removed: %d",item);
	}
}
void disp()
{
	int i;
	for(i=q.front;i<=q.rear;i++)
	printf("%d ",q.data[i]);
}

