// 1.Direct Recursion
#include <stdio.h>

void directRecursion(int n) {
    if (n > 0) {
        printf("%d ", n);
        directRecursion(n - 1);  // Direct recursive call
    }
}

int main() {
    directRecursion(5);
    return 0;
}
// 2.Tail Recursion
#include <stdio.h>

void tailRecursion(int n) {
    if (n == 0) return;
    printf("%d ", n);
    tailRecursion(n - 1);  // Tail call
}

int main() {
    tailRecursion(5);
    return 0;
}
// 3. Head Recursion (No Tail Recursion)
#include <stdio.h>

void headRecursion(int n) {
    if (n == 0) return;
    headRecursion(n - 1);  // Recursive call first
    printf("%d ", n);
}

int main() {
    headRecursion(5);
    return 0;
}
// 4. Linear Recursion
#include <stdio.h>

int sum(int n) {
    if (n == 0) return 0;
    return n + sum(n - 1);  // One recursive call => Linear recursion
}

int main() {
    printf("Sum = %d\n", sum(5));
    return 0;
}
// 5. Tree Recursion
#include <stdio.h>

void treeRecursion(int n) {
    if (n == 0) return;
    printf("%d ", n);
    treeRecursion(n - 1);
    treeRecursion(n - 1);  // Two recursive calls => Tree recursion
}

int main() {
    treeRecursion(3);
    return 0;
}

// 6.Indirect Recursion
#include <stdio.h>

void funcA(int);
void funcB(int);

void funcA(int n) {
    if (n > 0) {
        printf("A: %d\n", n);
        funcB(n - 1);
    }
}

void funcB(int n) {
    if (n > 0) {
        printf("B: %d\n", n);
        funcA(n / 2);
    }
}

int main() {
    funcA(10);
    return 0;
}
// 7.Nested Recursion
#include <stdio.h>

int nestedRecursion(int n) {
    if (n <= 0) {
        return 0;  // Base case
    } else {
        return n + nestedRecursion(nestedRecursion(n - 1));  // Nested recursive calls
    }
}

int main() {
    int result = nestedRecursion(5);
    printf("Result: %d\n", result);  // Expected output will be the sum
    return 0;
}

