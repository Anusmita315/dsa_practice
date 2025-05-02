#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct Node {
    int data;
    struct Node* next;
};


// 1: Create a list

struct Node* createList() {
    struct Node* head = NULL, *tail = NULL, *newNode;
    int n, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
    }

    return head;
}

// 2: Display the list

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// 3: Add a node at the beginning

struct Node* insertBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;

    return head;
}



// 4.⁠ ⁠Add a node at the end

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    return head;
}

// 5.⁠ ⁠Delete a node at the beginning

struct Node* deleteBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    if (head->next == head) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    struct Node* last = head;

    while (last->next != head) {
        last = last->next;
    }

    head = head->next;
    last->next = head;
    free(temp);

    return head;
}

// 6.⁠ ⁠Delete a node at the end

struct Node* deleteEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    if (head->next == head) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);

    return head;
}

// 7.⁠ ⁠Delete a node after data value.

struct Node* deleteAfterValue(struct Node* head, int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* temp = head;
    do {
        if (temp->data == value) {
            struct Node* toDelete = temp->next;

            if (toDelete == head) {
                printf("Cannot delete head node in this case.\n");
                return head;
            }

            temp->next = toDelete->next;
            free(toDelete);
            return head;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Value not found.\n");
    return head;
}


// 8: Delete the entire list

struct Node* deleteList(struct Node* head) {
    if (head == NULL) return NULL;

    struct Node* current = head->next;
    struct Node* temp;

    while (current != head) {
        temp = current;
        current = current->next;
        free(temp);
    }

    free(head);
    return NULL;
}

// Main function with menu
int main() {
    struct Node* head = NULL;
    int choice, data, value;

    do {
        printf("\n**MAIN MENU**\n");
        printf("1: Create a list\n");
        printf("2: Display the list\n");
        printf("3: Add a node at the beginning\n");
        printf("4: Add a node at the end\n");
        printf("5: Delete a node at the beginning\n");
        printf("6: Delete a node at the end\n");
        printf("7: Delete a node after data value\n");
        printf("8: Delete the entire list\n");
        printf("9: EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = createList();
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                head = insertBeginning(head, data);
                break;
            case 4:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertEnd(head, data);
                break;
            case 5:
                head = deleteBeginning(head);
                break;
            case 6:
                head = deleteEnd(head);
                break;
            case 7:
                printf("Enter data value after which to delete: ");
                scanf("%d", &value);
                head = deleteAfterValue(head, value);
                break;
            case 8:
                head = deleteList(head);
                printf("Entire list deleted.\n");
                break;
            case 9:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 9);

    return 0;
}








