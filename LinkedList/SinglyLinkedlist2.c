#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create() {
    struct Node *temp, *newNode;
    int num;

    printf("Enter the number of nodes to create: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
}

void insert() {
    struct Node *temp, *newNode;
    int position, num, count = 1;

    printf("Enter the position to insert the node: ");
    scanf("%d", &position);

    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data for the new node: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        printf("Node inserted at the beginning.\n");
        return;
    }

    temp = head;

    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node inserted at position %d.\n", position);
    }
}

void delete() {
    struct Node *temp, *prev;
    int position, count = 1;

    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    printf("Enter the position to delete the node: ");
    scanf("%d", &position);

    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    temp = head;

    if (position == 1) {
        head = head->next;
        free(temp);
        printf("Node deleted from the beginning.\n");
        return;
    }

    prev = NULL;

    while (temp != NULL && count < position) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
    } else {
        prev->next = temp->next;
        free(temp);
        printf("Node deleted from position %d.\n", position);
    }
}

void display() {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                insert();
                break;
            case 3:
                delete();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
