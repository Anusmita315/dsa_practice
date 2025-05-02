// Write a program to delete a number from a given location in an array.


#include <stdio.h>

int main() {
    int arr[100], n, pos, i;
    printf("Enter the number of elements (max 100): ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter the position to delete (1 to %d): ", n);
    scanf("%d", &pos);

    //
