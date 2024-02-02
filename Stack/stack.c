#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int i,top = -1, arr[SIZE];
// void push();
// void pop();
// void display();

void push()
{
    int x;

    if (top == SIZE - 1)
        printf("\nOverflow!\n");
        
    else
    {
        printf("\nEnter the element to be added onto the stack: ");
        scanf("%d", &x);
        top++;
        arr[top] = x;
    }
}

void pop()
{
    if (top == -1)
        printf("\nUnderflow!\n");
    else
    {
        printf("\nPopped element: %d", arr[top]);
        top--;
    }
}

void display()
{
    if (top == -1)
        printf("No elements present in stack!\n");
        
    else
    {
        printf("\nElements present in the stack: ");
        for (i = top; i >= 0; i--)
            printf("%d ", arr[i]);
    }
}
int main()
{
    int choice;

    while (1)
    {
        printf("\n\nPerform operations on the stack:");
        printf("\n1.Push the element\n2.Pop the element\n3.Display\n4.End");
        printf("\n\nEnter the choice: ");
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
        case 4:
            exit(0);

        default:
            printf("\nInvalid choice.\n");
        }
    }
    return 0;
}