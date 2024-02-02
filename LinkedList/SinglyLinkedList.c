#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *first, *p, *second, *third, *q = NULL;
;

// 1.Creating a Linked List

void create()
{
    struct Node *temp;

    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        struct Node *p = first;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}
// 2.Insert at first

void insertFirst()
{
    int num;
    p = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter value to insert: ");
    scanf("%d", &num);
    p->data = num;
    p->next = first;
    first = p;
    printf("Value inserted\n");
}

// 3.Insert at last

void insertLast()
{
    p = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = first;
    int num;
    printf("Enter value to insert: ");
    scanf("%d", &num);
    p->data = num;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = p;
    p->next = NULL;
    printf("Value inserted\n");
}

// 4.Insert after a given node

void afterInsert()
{
    struct Node *temp, *q;
    int node, num;
    printf("Enter the node after which the Node will be inserted and the value to be inserted: ");
    scanf("%d%d", &node, &num);
    q = (struct Node *)malloc(sizeof(struct Node));
    q->data = num;
    q->next = NULL;
    temp = first;
    while (temp != NULL && temp->data != node)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Node is not found.");
    }
    else
    {
        q->next = temp->next;
        temp->next = q;
        printf("Value inserted\n");
    }
}

// 5.Insert before a given node

void brforeInsert()
{
    struct Node *temp, *q, *p;
    int node, num;
    printf("Enter the node before which the Node will be inserted and the value to be inserted: ");
    scanf("%d%d", &node, &num);
    q = (struct Node *)malloc(sizeof(struct Node));
    q->data = num;
    q->next = NULL;
    temp = first;
    while (temp != NULL && temp->data != node)
    {
        p = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Node is not found.");
    }
    else
    {
        q->next = p->next;
        p->next = q;
        printf("Value inserted\n");
    }
}

// 6.Insert at any position full function

void insertAnyPos()
{
    struct Node *t;
    p = first;
    int index, num, i;
    printf("Enter the index and number: ");
    scanf("%d%d", &index, &num);
    if (index < 1 || index > count())
    {
        return;
    }
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = num;

    if (index == 1)
    {
        t->next = first;
        first = t;
    }
    else
    {
        p = first;
        for (i = 1; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
    printf("Value inserted\n");
}



// 7.Delete first node

void deleteFirst()
{
    p = first;
    int num;
    first = first->next;
    num = p->data;
    free(p);
    printf("Node deleted\n");
}

// 8.Delete last node

void deletelast()
{
    p = first;
    if (first == NULL)
        return;

    if (first->next == NULL)
    {
        free(first);
        printf("Node deleted\n");
        return;
    }

    struct Node *q = first;
    while (q->next->next != NULL)
        q = q->next;

    free (q->next);
    printf("Node deleted\n");

    q->next = NULL;

    return;
}

// 9.Delete element after a given node

void afterDelete()
{
    int key;
    struct Node *q, *temp, *t;
    printf("Enter the node after which the Node will be deleted: ");
    scanf("%d", &key);
    q = (struct Node *)malloc(sizeof(struct Node));
    q->data = key;
    q->next = NULL;
    temp = first;
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Key is not found.");
    }
    else
    {
        if (temp->next == NULL)
        {
            printf("Deletion not posible because it is the last node.");
        }
        else
        {
            t = temp->next;
            temp->next = t->next;
            free (p);
            printf("Node Deleted\n");
        }
    }
}

// 10.Delete element beore a given node

void beforeDelete()
{
    int key;
    struct Node *temp, *p;
    printf("Enter the node before which the Node will be deleted: ");
    scanf("%d", &key);
    temp = first;
    while (temp != NULL && temp->next->data != key)
    {
        p = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Key is not found.");
    }
    else
    {
        if (temp == first)
        {
            deleteFirst();
        }
        else
        {
            p->next = temp->next;
            free(temp);
            printf("Node Deleted\n");
        }
    }
}

// 11.Delete from any position full function

void deleteAnyPos()
{
    p = first;
    struct Node *q;
    int i, index;
    printf("Enter the index: ");
    scanf("%d", &index);
    if (index < 1 || index > count())
    {
        printf("Index is invalid.");
    }

    if (index == 1)
    {
        first = first->next;
        free(p);
        printf("Node deleted\n");
    }
    else
    {
        p = first;
        q = NULL;
        for (i = 0; i < index - 1 && p; i++)
        {
            q = p;
            p = p->next;
        }
        if (p)
        {
            q->next = p->next;
            free(p);
            printf("Node deleted\n");
        }
    }
}
// 12.Display of Linked List

void display()
{
    p = first;
    printf("The Nodes are: ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
// 13.Display of Linked List using Recursion

void RDisplay(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        RDisplay(p->next);
    }
}

// 14.Counting Nodes in a Linked List

int count()
{
    p = first;
    int c = 0;
    while (p != 0)
    {
        c++;
        p = p->next;
    }
    return c;
}

// 15.Counting Nodes in a Linked List using Recursion

int Rcount(struct Node *p)
{
    if (p == 0)
    {
        return 0;
    }
    else
    {
        return Rcount(p->next) + 1;
    }
}


int main()
{

    int choice;
    while (1)
    {
        printf("\n 1.Create \n  2.Insert at first \n 3.Insert at last \n 4.Insert element after a given node \n 5.Insert element before a given node \n 6.Insert at any position \n  7.Delete from first \n 8.Delete from last \n 9.Delete element after a given node \n10.Delete element before a given node \n 11.Delete from any position \n12.Display \n 13.Display using Recursion \n 14.Count \n 15.Count using Recursion \n 16.To exit \n");
        printf("Enter Choice :\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            insertFirst();
            break;
        case 3:
            insertLast();
            break;
        case 4:
            afterInsert();
            break;
        case 5:
            brforeInsert();
            break;
        case 6:
            insertAnyPos();
            break;
        case 7:
            deleteFirst();
            break;
        case 8:
            deletelast();
            break;
        case 9:
            afterDelete();
            break;
        case 10:
            beforeDelete();
            break;
        case 11:
            deleteAnyPos();
            break;
       case 12:
            display();
            break;
        case 13:
            printf("The Nodes are: ");
            RDisplay(first);
            break;
        case 14:
            printf("The number of elements present in Linked struct Node are: %d", count());
            break;
        case 15:
            printf("The number of elements present in Linked struct Node are: %d", Rcount(first));
            break;
        case 16:
            exit(1);
            break;
        default:
            printf("Incorrect Choice\n");
        }
    }

    return 0;
}