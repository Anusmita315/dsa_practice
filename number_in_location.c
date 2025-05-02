// Write a program to insert a number at a given location in an array.

#include <stdio.h>

int main() {
    int arr[100], n, i, pos, num;
    printf("Enter the number of elements (max 100): ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to insert: ");
    scanf("%d", &num);

    printf("Enter the position to insert at (1 to %d): ", n + 1);
    scanf("%d", &pos);
    if(pos < 1 || pos > n + 1) {
        printf("Invalid position!\n");
        return 1;
    }
    for(i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = num;
    n++;
    printf("Array after insertion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
