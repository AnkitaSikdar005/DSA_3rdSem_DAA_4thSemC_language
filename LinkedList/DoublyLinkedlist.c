#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} list;

list *head, *tail = NULL, *p;

// 1.Creating a Linked List

void create()
{
    list *newNode = (list *)malloc(sizeof(list));
    int x;
    printf("Enter data: ");
    scanf("%d", &x);
    newNode->data = x;

    // If list is empty
    if (head == NULL)
    {
        head = tail = newNode;
        head->prev = NULL;
        tail->next = NULL;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        tail->next = NULL;
    }
}

// 2.Display of Linked List

void display()
{
    p = head;
    printf("The nodes are: ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
// 3.Insert at first

void insertFirst()
{
    int num;
    p = (list *)malloc(sizeof(list));
    printf("Enter value to insert: ");
    scanf("%d", &num);
    p->data = num;
    p->prev = NULL;
    p->next = NULL;
    if (head == NULL)
        head = p;
    else
    {
        p->next = head;
        head->prev = p;
        head = p;
    }
    printf("Value inserted\n");
}

// 4.Insert at last

void insertLast()
{
    p = (list *)malloc(sizeof(list));
    int num;
    printf("Enter value to insert: ");
    scanf("%d", &num);
    p->data = num;
    p->prev = NULL;
    p->next = NULL;
    if (head == NULL)
        head = p;
    else
    {
        list *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        p->prev = temp;
        temp->next = p;
    }
    printf("Value inserted\n");
}

// 5.Insert after a given node

void afterInsert()
{
    list *temp, *q;
    int node, num;
    printf("Enter the node after which the Node will be inserted and the value to be inserted: ");
    scanf("%d%d", &node, &num);
    q = (list *)malloc(sizeof(list));
    q->data = num;
    q->next = NULL;
    q->prev = NULL;
    temp = head;
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
        q->prev = temp;
        temp->next = q;
        temp->next->prev = q;
        printf("Value inserted\n");
    }
}

// 6.Insert before a given node

void brforeInsert()
{
    list *temp, *q, *p;
    int node, num;
    printf("Enter the node before which the Node will be inserted and the value to be inserted: ");
    scanf("%d%d", &node, &num);
    q = (list *)malloc(sizeof(list));
    q->data = num;
    q->next = NULL;
    q->prev = NULL;
    temp = head;
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
        q->prev = temp->prev;
        temp->prev = q;
        q->next = temp;
        if (q->prev != NULL)
            q->prev->next = q;
        else
            head = q;
    }
    printf("Value inserted\n");
}
//Counting Nodes in a Linked List
int count()
{
    p = head;
    int c = 0;
    while (p != 0)
    {
        c++;
        p = p->next;
    }
    return c;
}

// 7.Insert at any position full function

void insertAnyPos()
{
    list *t;
    int index, num, i;
    printf("Enter the index and number: ");
    scanf("%d%d", &index, &num);
    if (index < 1 || index > count())
    {
        printf("Index is invalid.");
    }

    p = head;
    t = (list *)malloc(sizeof(list));
    t->data = num;

    if (index == 1)
    {
        t->prev = NULL;
        t->next = head;
        head->prev = t;
        head = t;
    }
    else
    {
        for (int i = 1; i < index - 1; i++)
        {
            p = p->next;
        }
        t->prev = p;
        t->next = p->next;
        if (p->next)
        {
            p->next->prev = t;
        }
        p->next = t;
    }
    printf("Value inserted\n");
}

// 8.Delete first node

void deleteFirst()
{
    p = head;
    int num;
    head = head->next;
    num = p->data;
    free(p);
    printf("Node deleted\n");
}

// 9.Delete last node

void deletelast()
{
    p = head;
    if (head == NULL)
        return;

    if (head->next == NULL)
    {
        free(head);
        printf("Node deleted\n");
        return;
    }

    list *q = head;
    while (q->next->next != NULL)
        q = q->next;

    free(q->next);
    printf("Node deleted\n");

    q->next = NULL;

    return;
}

// 10.Delete element after a given node

void afterDelete()
{
    int key, x;
    list *q, *temp, *t, *ptr;
    printf("Enter the node after which the Node will be deleted: ");
    scanf("%d", &key);
    q = (list *)malloc(sizeof(list));
    q->data = key;
    q->next = NULL;
    temp = head;
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
        else if (temp->next->next == NULL)
        {
            temp->next = NULL;
            printf("Node Deleted\n");
        }
        else
        {
            ptr = temp->next;
            temp->next = ptr->next;
            ptr->next->prev = temp;
            free(ptr);
            printf("Node Deleted\n");
        }
    }
}


void deleteAnyPos()
{
    p = head;
    int i, index;
    printf("Enter the index: ");
    scanf("%d", &index);
    if (index < 1 || index > count())
    {
        printf("Index is invalid.");
    }
    if (index == 1)
    {
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(p);
        printf("Node deleted\n");
    }
    else
    {
        p = head;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next != NULL)
        {
            p->next->prev = p->prev;
        }
        free(p);
        printf("Node deleted\n");
    }
}


int main()
{
    int choice;
    while (1)
    {
        printf("\n 1.Create \n 2.Display \n  3.Insert at first \n 4.Insert at last \n 5.Insert element after a given node \n 6.Insert element before a given node \n 7.Insert at any position \n 8.Delete from first \n 9.Delete from last \n 10.Delete element after a given node \n 11.Delete from any position \n  12.To exit \n");
        printf("Enter Choice :\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insertFirst();
            break;
        case 4:
            insertLast();
            break;
        case 5:
            afterInsert();
            break;
        case 6:
            brforeInsert();
            break;
        case 7:
            insertAnyPos();
            break;
        case 8:
            deleteFirst();
            break;
        case 9:
            deletelast();
            break;
        case 10:
            afterDelete();
            break;
        // case 17:
        //     beforeDelete();
        //     break;
        case 11:
            deleteAnyPos();
            break;
        case 12:
            exit(1);
            break;
        default:
            printf("Incorrect Choice\n");
        }
    }
    return 0;
}