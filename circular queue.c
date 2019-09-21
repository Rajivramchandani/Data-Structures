#include <stdio.h>

#define MAX 5
int q[MAX];
int rear = - 1;
int front = - 1;
main()
{
    int ch;
    while(4)
    {
        printf("\n1.Insert element to queue \n2.Delete element from queue \n3.Display all elements of queue \n");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(4);
        }
    }
}

insert()
 {rear= (rear+1)%MAX;

if (front==rear)
printf( "\nqueue is full");
else
{
    if(front==-1)
        front=0;
    int item;

printf("\nInset the element in queue : ");
scanf("%d",&item);
q[rear]=item ;
}
}

delete()

{int item;
if (front==rear)
printf("queue is empty");
else
{printf("\ndeleted item is %d ",q[front]);
front = front + 1;
item = q[front];
}
}
display()
{
    int i;
    if (front == - 1)
        printf("\nQueue is empty \n");
    else
    {
        printf("\nQueue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", q[i]);
        printf("\n");
    }
}
