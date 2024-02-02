#include <stdio.h>
#include <stdlib.h>
 
#define MAX 50
 
void insert();
void del();
void display();
int peek(void);
int queue_array[MAX];
int rear = - 1;
int front = - 1;
int val;
int main()
{
    int choice;
    while (1)
    {
        printf("\n1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Peek \n");
        printf("4.Display all elements of queue \n");
        printf("5.Quit \n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            insert();
            break;
            case 2:
            del();
            break;
            case 3:
           val = peek();
            if (val != -1)
           printf("\n The first value in queue is : %d", val);
           break;
            case 4:
            display();
            break;
            case 5:
            exit(1);
            default:
            printf("Wrong choice \n");
        } 
    } 
} 
 
void insert()
{
    int add_item;
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        front = 0;
        printf("Insert the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
        printf("%d is inserted!!\n",add_item);
    }
} 
 
void del()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
}
int peek()
{
if(front==-1 || front>rear)
{
printf("\n QUEUE IS EMPTY");
return -1;
}
else
{
return queue_array[front];
}
}

void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("\nQueue is : ");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
} 