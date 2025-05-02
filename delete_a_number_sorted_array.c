// Write a program to delete a number from an array that is already sorted in ascending order.

#include <stdio.h>

int main() {
    int arr[100], n, i, j, num, found = 0;
    printf("Enter the number of elements (max 100): ");
    scanf("%d", &n);
    printf("Enter %d sorted elements in ascending order:\n", n);
    for(i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to delete: ");
    scanf("%d", &num);
    for(i = 0; i < n; i++) {
        if(arr[i] == num) {
            found = 1;
            break;
        }
    }

    if(found) {
        for(j = i; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }
        n--;
        printf("Array after deletion:\n");
        for(i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Number not found in the array.\n");
    }

    return 0;
}
