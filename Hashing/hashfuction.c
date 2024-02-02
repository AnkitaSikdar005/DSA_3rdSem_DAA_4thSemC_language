#include <stdio.h>
#include <stdlib.h>

// Structure for each element in the hash table (for chaining)
struct Node {
    int data;
    struct Node* next;
};

// Function to perform linear probing
int linearProbing(int key, int n, int hashTable[]) {
    int loc = key % n;
    int i = loc;
    while (hashTable[i] != -1) {
        i = (i + 1) % n; // Move to the next slot linearly
    }
    return i;
}

// Function to perform quadratic probing
int quadraticProbing(int key, int n, int hashTable[]) {
    int loc = key % n;
    int i = loc;
    int k = 1;
    while (hashTable[i] != -1) {
        i = (loc + k * k) % n; // Move to the next slot using quadratic probing
        k++;
    }
    return i;
}

// Function to perform double hashing
int doubleHashing(int key, int n, int hashTable[], int R) {
    int loc = key % n;
    int i = loc;
    int h2 = R - (key % R); // Secondary hash function
    while (hashTable[i] != -1) {
        i = (i + h2) % n; // Move to the next slot using double hashing
    }
    return i;
}

// Function to perform chaining
void chaining(int key, int n, struct Node* hashTable[]) {
    int loc = key % n;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = hashTable[loc];
    hashTable[loc] = newNode;
}

// Function to display the hash table
void displaylinearProbing(int n, int hashTable[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", i, hashTable[i]);
    }
    printf("\n");
}
// Function to display the hash table
void displayQuadraticProbing(int n, int hashTable[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", i, hashTable[i]);
    }
    printf("\n");
}
// Function to display the hash table
void displayDoubleHashing(int n, int hashTable[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", i, hashTable[i]);
    }
    printf("\n");
}

// Function to display the hash table (for chaining)
void displayChaining(int n, struct Node* hashTable[]) {
    printf("Hash Table with Chaining:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        struct Node* current = hashTable[i];
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
    printf("\n");
}

int main() {
    int n, m, R;
    printf("Enter the size of the hash table (n): ");
    scanf("%d", &n);
    printf("Enter the number of keys to store (k): ");
    scanf("%d", &m);
    printf("Enter R for double hashing: ");
    scanf("%d", &R);

    int hashTableLinear[n];
    int hashTableQuadratic[n];
    int hashTableDoubleHashing[n];
    struct Node* hashTableChaining[n];

    // Initialize hash tables
    for (int i = 0; i < n; i++) {
        hashTableLinear[i] = -1;
        hashTableQuadratic[i] = -1;
        hashTableDoubleHashing[i] = -1;
        hashTableChaining[i] = NULL;
    }

    // Menu-driven program
    int choice, key, loc;
    while (1) {
        printf("1. Insert key using Linear Probing\n");
        printf("2. Insert key using Quadratic Probing\n");
        printf("3. Insert key using Double Hashing\n");
        printf("4. Insert key using Chaining\n");
        printf("5. Display Linear Probing\n");
        printf("6. Display Quadratic Probing\n");
        printf("7. Display Double Hashing\n");
        printf("8. Display Chaining\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                loc = linearProbing(key, n, hashTableLinear);
                hashTableLinear[loc] = key;
                break;

            case 2:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                loc = quadraticProbing(key, n, hashTableQuadratic);
                hashTableQuadratic[loc] = key;
                break;

            case 3:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                loc = doubleHashing(key, n, hashTableDoubleHashing, R);
                hashTableDoubleHashing[loc] = key;
                break;

            case 4:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                chaining(key, n, hashTableChaining);
                break;

            case 5:
                displaylinearProbing(n, hashTableLinear);
                break;
            case 6:
                displayQuadraticProbing(n, hashTableQuadratic);
                break;
            case 7:
                displayDoubleHashing(n, hashTableDoubleHashing);
                break; 
            case 8:
                displayChaining(n, hashTableChaining);
                break;    
            case 9:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
