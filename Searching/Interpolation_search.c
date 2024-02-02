#include <stdio.h>

int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x) {
                return low;
            } else {
                return -1;  // Not found
            }
        }

        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));

        if (arr[pos] == x) {
            return pos;
        } else if (arr[pos] < x) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    return -1;  // Not found
}

int main() {
    // int arr[] = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // int x = 85;  // Element to search
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements in sorted order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    printf("Enter the element to search: ");
    scanf("%d", &x);

    int result = interpolationSearch(arr, n, x);

    if (result == -1) {
        printf("Element %d not found\n", x);
    } else {
        printf("Element %d found at index %d\n", x, result);
    }

    return 0;
}
