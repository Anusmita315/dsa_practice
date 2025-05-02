// Write a program to insert a number in an array that is already sorted in ascending order.

#include <stdio.h>

int main() {
    int arr[100], n, num, i, j;
    printf("Enter the number of elements (max 100): ");
    scanf("%d", &n);
    printf("Enter %d sorted elements in ascending order:\n", n);
    for(i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to insert: ");
    scanf("%d", &num);
    for(i = 0; i < n; i++) {
        if(arr[i] > num)
            break;
    }
    for(j = n; j > i; j--) {
        arr[j] = arr[j - 1];
    }
    arr[i] = num;
    n++;
    printf("Array after insertion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
