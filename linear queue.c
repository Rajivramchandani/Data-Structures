#include <stdio.h>

#define MAX 20
int q[MAX];
int rear = - 1;
int front = - 1;
main()
{
    int ch;
    while(4)
    {
        printf("1.Insert element to queue \n2.Delete element from queue \n3.Display all elements of queue \n");
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
{
    int item;
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)

        front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &item);
        rear = rear + 1;
        q[rear] =item;
    }
}

delete()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", q[front]);
        front = front + 1;
    }
}
display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", q[i]);
        printf("\n");
    }
}
