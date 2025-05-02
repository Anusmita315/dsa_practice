// Write a program to create a doubly linked list and perform insertions and deletions in all cases.

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

//1. Display list
void display(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//2. Insert at beginning
struct Node* insertBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;

    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

//3. Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

//4. Insert after a given data
struct Node* insertAfter(struct Node* head, int key, int data) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found.\n", key);
        return head;
    }

    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;

    return head;
}

//5. Delete at beginning
struct Node* deleteBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
    return head;
}

//6. Delete at end
struct Node* deleteEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* temp = head;
    if (temp->next == NULL) {
        free(temp);
        return NULL;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
    return head;
}

//7. Delete node with specific value
struct Node* deleteByValue(struct Node* head, int key) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found.\n", key);
        return head;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next; // deleting head

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    return head;
}

//8. Delete entire list
struct Node* deleteList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return NULL;
}

//9. Main menu-driven program
int main() {
    struct Node* head = NULL;
    int choice, data, key;

    do {
        printf("\n***** MAIN MENU *****\n");
        printf("1. Display list\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at end\n");
        printf("4. Insert after value\n");
        printf("5. Delete at beginning\n");
        printf("6. Delete at end\n");
        printf("7. Delete by value\n");
        printf("8. Delete entire list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(head);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertBeginning(head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertEnd(head, data);
                break;
            case 4:
                printf("Enter key value after which to insert: ");
                scanf("%d", &key);
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAfter(head, key, data);
                break;
            case 5:
                head = deleteBeginning(head);
                break;
            case 6:
                head = deleteEnd(head);
                break;
            case 7:
                printf("Enter data value to delete: ");
                scanf("%d", &key);
                head = deleteByValue(head, key);
                break;
            case 8:
                head = deleteList(head);
                printf("List deleted.\n");
                break;
            case 9:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 9);

    return 0;
}
