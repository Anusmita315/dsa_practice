// 1. print this pattern
// *
// **
// ***
// ****
// *****


#include <stdio.h>

int main() {
    int i, j, n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

// 2. print this pattern

//     *
//    ***
//   *****
//  *******
// *********

#include <stdio.h>

int main() {
    int i, j, k, n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        
        for(j = i; j < n; j++) {
            printf(" ");
        }
        
        for(k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}


// 3. print this pattern


//     *
//    ***
//   *****
//  *******
// *********
//  *******
//   *****
//    ***
//     *

#include <stdio.h>

int main() {
    int i, j, k, n;
    printf("Enter the number of rows (odd number): ");
    scanf("%d", &n);

    
    for(i = 1; i <= n/2 + 1; i++) {
        
        for(j = i; j < n/2 + 1; j++) {
            printf(" ");
        }
       
        for(k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }

    
    for(i = n/2; i >= 1; i--) {
        
        for(j = i; j <= n/2; j++) {
            printf(" ");
        }
        
        for(k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}




// 4. print this pattern

// *****
// ****
// ***
// **
// *

#include <stdio.h>

int main() {
    int i, j, n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for(i = n; i >= 1; i--) {
        for(j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

//  5. print this pattern

//     1
//    121
//   12321
//  1234321
// 123454321

#include <stdio.h>

int main() {
    int i, j, k, n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        
        for(j = i; j < n; j++) {
            printf(" ");
        }
        
        for(k = 1; k <= i; k++) {
            printf("%d", k);
        }
        
        for(k = i - 1; k >= 1; k--) {
            printf("%d", k);
        }
        printf("\n");
    }
    return 0;
}



