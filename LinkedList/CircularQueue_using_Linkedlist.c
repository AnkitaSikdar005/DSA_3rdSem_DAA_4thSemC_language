#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular queue
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *front = NULL, *rear = NULL;  // Global variables to store front and rear pointers

// Function prototypes
void enqueue(int data);
void dequeue();
void displayQueue();

int main() {
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

// Enqueue an element
void enqueue(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (front == NULL) {
        front = rear = newNode;
        rear->next = front;  // Circular linking
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;  // Circular linking
    }
    printf("Enqueued %d\n", data);
}

// Dequeue an element
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    Node *temp = front;
    int data = temp->data;

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;  // Maintain circularity
    }

    free(temp);
    printf("Dequeued %d\n", data);
}

// Display the queue
void displayQueue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    Node *temp = front;
    printf("Queue: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}
