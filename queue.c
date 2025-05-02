#include <stdio.h>
#include <stdlib.h>

// Queue structure
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

//1. Function to create a queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

//2. Check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

//3. Check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

//4. Add an item to the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full, cannot enqueue.\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue.\n", item);
}

//5. Remove an item from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot dequeue.\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

//6. Get the front item from the queue
int peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->array[queue->front];
}

//7. Display the elements in the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->array[(queue->front + i) % queue->capacity]);
    }
    printf("\n");
}

//8. Main menu-driven program
int main() {
    struct Queue* queue = createQueue(5); // Create a queue with capacity 5
    int choice, item;

    do {
        printf("\n***** MAIN MENU *****\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Check if empty\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &item);
                enqueue(queue, item);
                break;
            case 2:
                item = dequeue(queue);
                if (item != -1)
                    printf("%d dequeued from queue.\n", item);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                item = peek(queue);
                if (item != -1)
                    printf("Front element is: %d\n", item);
                break;
            case 5:
                if (isEmpty(queue)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
