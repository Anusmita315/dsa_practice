// Write a program to insert a number at a given location in an array.

#include <stdio.h>

int main() {
    int arr[100], n, i, pos, num;

    // Input the number of elements
    printf("Enter the number of elements (max 100): ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Input the number to insert and position
    printf("Enter the number to insert: ");
    scanf("%d", &num);

    printf("Enter the position to insert at (1 to %d): ", n + 1);
    scanf("%d", &pos);

    // Validate position
    if(pos < 1 || pos > n + 1) {
        printf("Invalid position!\n");
        return 1;
    }

    // Shift elements to the right
    for(i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the number
    arr[pos - 1] = num;
    n++;

    // Display the updated array
    printf("Array after insertion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
