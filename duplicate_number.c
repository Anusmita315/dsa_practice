Write a program to find whether the array of integers contains a duplicate number.

#include <stdio.h>

int main() {
    int n, i, j, found = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                found = 1;
                printf("Duplicate found: %d at positions %d and %d\n", arr[i], i + 1, j + 1);
                break;
            }
        }
        if(found) break;
    }

    if(!found) {
        printf("No duplicates found in the array.\n");
    }

    return 0;
}
