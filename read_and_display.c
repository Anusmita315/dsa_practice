// Write a program to read and display a 3*3 matrix.

#include <stdio.h>

int main() {
    int matrix[3][3];
    int i, j;
    printf("Enter the elements of a 3x3 matrix:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("Element at [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nThe 3x3 matrix is:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j
