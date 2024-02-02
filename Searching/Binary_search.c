#include <stdio.h>

int main() {
    int c, low, high, middle, n, search, array[100];

    printf("Enter number of elements\n");
    scanf("%d", &n);

    printf("Enter %d integers\n", n);

    for (c = 0; c < n; c++)
        scanf("%d", &array[c]);

    printf("Enter value to find\n");
    scanf("%d", &search);

    low = 0;
    high = n - 1;
    middle = (low + high) / 2;

    while (low <= high) {
        if (array[middle] < search)
            low = middle + 1;
        else if (array[middle] == search) {
            printf("%d found at location %d.\n", search, middle + 1);
            break;
        }
        else
            high = middle - 1;

        middle = (low + high) / 2;
    }
    if (low > high)
        printf("Not found! %d isn't present in the list.\n", search);

    return 0;
}
