#include <stdio.h>

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void displayInsertion(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void displayDeletion(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indInsertion(int arr[], int size, int element, int capacity, int index) {
    if (size >= capacity) {
        return -1; // Indicates failure
    }
    
    for (int i = size - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }
    
    arr[index] = element;
    return 1; // Indicates success
}

void indDeletion(int arr[], int size, int index) {
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
}

int main() {
    int size = 0, element = 0, index = 0, size1 = 0, size2 = 0, choice = 0;

    printf("Enter no of elements in the array\n");
    scanf("%d", &size);
    int arr[100]; // Assuming a maximum capacity of 100 for simplicity

    printf("Enter array elements\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Display original array elements\n");
        printf("2. Insert an element\n");
        printf("3. Display array elements after insertion \n");
        printf("4. Delete an element\n");
        printf("5. Display array elements after deletion \n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayArray(arr, size);
                break;

            case 2:
                printf("Enter the element to be inserted\n");
                scanf("%d", &element);
                printf("Enter the index at which the element must be inserted\n");
                scanf("%d", &index);
                if (indInsertion(arr, size, element, 100, index) == 1) {
                    size++;
                } else {
                    printf("Insertion failed. Array is full.\n");
                }
                break;

            case 3:
                size1 = size;
                displayInsertion(arr, size1);
                break;

            case 4:
                printf("Enter the index at which the element must be deleted\n");
                scanf("%d", &index);
                indDeletion(arr, size, index);
                size--;
                break;

            case 5:
                size2 = size;
                displayDeletion(arr, size2);
                break;

            case 6:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
