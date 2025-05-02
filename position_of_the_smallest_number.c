// Q.Write a program to print the position of the smallest number of n numbers using arrays.

#include <stdio.h>

int main() {
    int n, i, minIndex;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    minIndex = 0;
    for(i = 1; i < n; i++) {
        if(arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    printf("The smallest number is %d and its position is %d.\n", arr[minIndex], minIndex + 1);

    return 0;
}
