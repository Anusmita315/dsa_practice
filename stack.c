#include <stdio.h>
#define SIZE 100

int stack[SIZE];
int top = -1;
//1. Push Operation
void push(int value) {
    if (top == SIZE - 1) {
        printf("Stack Overflow! Cannot push.\n");
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed onto the stack.\n", value);
    }
}
//2. Pop Operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop.\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}
//3. Peek Operation
void peek() {
    if (top == -1) {
        printf("Stack is empty. No top element.\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}
//4. void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack contents (top to bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
//5. Menu-Driven Main Function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a number from 1 to 5.\n");
        }
    }

    return 0;
}
