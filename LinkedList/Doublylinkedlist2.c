#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Global pointer to the head of the doubly linked list
struct Node *head = NULL;

// Function to create a new node with a given data
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the doubly linked list
void insertAtBeginning() {
    int data;
    printf("Enter data to insert at the beginning: ");
    scanf("%d", &data);

    struct Node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    printf("Data inserted at the beginning successfully\n");
}

// Function to insert a node at the end of the doubly linked list
void insertAtEnd() {
    int data;
    printf("Enter data to insert at the end: ");
    scanf("%d", &data);

    struct Node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Data inserted at the end successfully\n");
}
// Function to delete a node with given data from the doubly linked list
void deleteNode() {
    int data;
    printf("Enter data to delete: ");
    scanf("%d", &data);

    struct Node *temp = head;

    while (temp != NULL) {
        if (temp->data == data) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                head = temp->next;
            }

            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }

            free(temp);
            printf("Data deleted successfully\n");
            return;
        }
        temp = temp->next;
    }

    printf("Data not found in the list\n");
}
// Function to delete a node at a specific position in the doubly linked list
void deleteAtPosition() {
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("List is empty, deletion not possible\n");
        return;
    }

    struct Node *temp = head;
    int count = 1;

    while (temp != NULL && count < pos) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position not found in the list\n");
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Node deleted at position %d successfully\n", pos);
}

// Function to display the doubly linked list
void displayList() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
  while(1) {
        printf("\nChoose an option:\n");
        printf("1. Create a doubly linked list\n");
        printf("2. Insert at the beginning\n");
        printf("3. Insert at the end\n");
        printf("4. Delete a node of a given position\n");
        printf("5.Delete a node\n");
        printf("6.Display the list\n ");
        printf("7. Exit\n");
        int choice=0;
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                // Creating a doubly linked list is handled automatically
                printf("Doubly linked list created\n");
                break;
            case 2:
                insertAtBeginning();
                break;
            case 3:
                insertAtEnd();
                break;
            case 4:
                deleteAtPosition();
                break;
             case 5:
                deleteNode();
                break;
            case 6:
                displayList();
                break;
            case 7:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice\n");
        }

    } 
    // #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int data;
//     struct Node* prev;
//     struct Node* next;
// };

// struct Node* head = NULL;

// void createList() {
//     head = NULL;
//     printf("List created successfully!\n");
// }

// void insertNode(int data, int position) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;

//     if (position == 1) {
//         newNode->next = head;
//         newNode->prev = NULL;
//         if (head != NULL) {
//             head->prev = newNode;
//         }
//         head = newNode;
//     } else {
//         struct Node* current = head;
//         int i = 1;
//         while (current != NULL && i < position - 1) {
//             current = current->next;
//             i++;
//         }
//         if (current == NULL) {
//             printf("Invalid position!\n");
//             return;
//         }
//         newNode->next = current->next;
//         newNode->prev = current;
//         if (current->next != NULL) {
//             current->next->prev = newNode;
//         }
//         current->next = newNode;
//     }
//     printf("Node inserted successfully!\n");
// }

// void deleteNode(int position) {
//     if (head == NULL) {
//         printf("List is empty!\n");
//         return;
//     }

//     struct Node* temp;
//     if (position == 1) {
//         temp = head;
//         head = head->next;
//         if (head != NULL) {
//             head->prev = NULL;
//         }
//     } else {
//         struct Node* current = head;
//         int i = 1;
//         while (current != NULL && i < position) {
//             temp = current;
//             current = current->next;
//             i++;
//         }
//         if (current == NULL) {
//             printf("Invalid position!\n");
//             return;
//         }
//         temp->next = current->next;
//         if (current->next != NULL) {
//             current->next->prev = temp;
//         }
//     }
//     free(temp);
//     printf("Node deleted successfully!\n");
// }

// void displayList() {
//     if (head == NULL) {
//         printf("List is empty!\n");
//         return;
//     }

//     struct Node* current = head;
//     printf("List: ");
//     while (current != NULL) {
//         printf("%d ", current->data);
//         current = current->next;
//     }
//     printf("\n");
// }

// int main() {
//     int choice, data, position;

//     while (1) {
//         printf("\nMenu:\n");
//         printf("1. Create List\n");
//         printf("2. Insert Node\n");
//         printf("3. Delete Node\n");
//         printf("4. Display List\n");
//         printf("5. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 createList();
//                 break;
//             case 2:
//                 printf("Enter data to insert: ");
//                 scanf("%d", &data);
//                 printf("Enter position (1-based): ");
//                 scanf("%d", &position);
//                 insertNode(data, position);
//                 break;
//             case 3:
//                 printf("Enter position to delete (1-based): ");
//                 scanf("%d", &position);
//                 deleteNode(position);
//                 break;
//             case 4:
//                 displayList();
//                 break;
//             case 5:
//                 exit(0);
//             default:
//                 printf("Invalid choice!\n");
//         }
//     }

//     return 0;
// }

//**************************************************************************************************************************************
// Function to delete a node with given data from the doubly linked list
// void deleteNode() {
//     int data;
//     printf("Enter data to delete: ");
//     scanf("%d", &data);

//     struct Node *temp = head;

//     while (temp != NULL) {
//         if (temp->data == data) {
//             if (temp->prev != NULL) {
//                 temp->prev->next = temp->next;
//             } else {
//                 head = temp->next;
//             }

//             if (temp->next != NULL) {
//                 temp->next->prev = temp->prev;
//             }

//             free(temp);
//             printf("Data deleted successfully\n");
//             return;
//         }
//         temp = temp->next;
//     }

//     printf("Data not found in the list\n");
// }

    return 0;
}

