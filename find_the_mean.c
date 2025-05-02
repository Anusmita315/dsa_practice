// Q. Write a program to find the mean of n numbers using arrays.

#include <stdio.h>
int main() {
    int n, i;
    float sum = 0, mean;

   
    printf("Enter the number of elements: ");
    scanf("%d", &n);

   
    float arr[n];

    
    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%f", &arr[i]);
        sum += arr[i];
    }

    
    mean = sum / n;

    printf("The mean of the entered numbers is: %.2f\n", mean);

    return 0;
}
