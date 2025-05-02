// Write a program to find the second largest of n numbers using an array.
#include <stdio.h>

int main() {
    int n, i, first, second;
    printf("Enter the number of elements (at least 2): ");
    scanf("%d", &n);

    if (n < 2) {
        printf("At least two numbers are required.\n");
        return 1;
    }
    int arr[n];
    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    if (arr[0] > arr[1]) {
        first = arr[0];
        second = arr[1];
    } else {
        first = arr[1];
        second = arr[0];
    }
    for(i = 2; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    if (first == second) {
        printf("All elements are equal or there is no distinct second largest number.\n");
    } else {
        printf("The second largest number is: %d\n", second);
    }

    return 0;
}
