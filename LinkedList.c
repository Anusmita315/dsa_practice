#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct Node {
    int data;
    struct Node* next;
};

// 1: funtion to Create a new Node 

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 2: Display the list 

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


// 3: Add a node at the beginning

struct Node* addAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}


// 4: Add the node at the end

struct Node* addAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// 5: Add the node before a given node

struct Node* addBeforeNode(struct Node* head, int before, int data) {
    if (head == NULL) return head;
    if (head->data == before) {
        return addAtBeginning(head, data);
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != before) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Node with value %d not found.\n", before);
        return head;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// 6: Add the node after a given node

struct Node* addAfterNode(struct Node* head, int after, int data) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != after) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with value %d not found.\n", after);
        return head;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// 7: Delete a node from the beginning

struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// 8: Delete a node from the end

struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// 9: Delete a given node

struct Node* deleteNode(struct Node* head, int data) {
    if (head == NULL) return head;
    if (head->data == data) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != data) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Node with value %d not found.\n", data);
        return head;
    }
    struct Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
    return head;
}

// 10: Delete a node after a given node

struct Node* deleteAfterNode(struct Node* head, int after) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != after) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Node with value %d or no node after it found.\n", after);
        return head;
    }
    struct Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
    return head;
}

// 11: Delete the entire list

void deleteList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// 12: Sort the list

struct Node* sortList(struct Node* head) {
    if (head == NULL) return head;
    struct Node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return head;
}

// 13.⁠ ⁠Reverse 

struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

// 14.⁠ ⁠Finding cycle in LL

int detectCycle(struct Node* head) {
    if (head == NULL) return 0;
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1; 
        }
    }
    return 0; 
}

// 15.⁠ ⁠Finding Middle element in LL

nt findMiddle(struct Node* head) {
    if (head == NULL) return -1;
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}
// Main function to implement the menu-driven program
int main() {
    struct Node* head = NULL;
    int choice, data, after, before;

    do {
        printf("\n*** MAIN MENU ***\n");
        printf("1: Create a list\n");
        printf("2: Display the list\n");
        printf("3: Add a node at the beginning\n");
        printf("4: Add the node at the end\n");
        printf("5: Add the node before a given node\n");
        printf("6: Add the node after a given node\n");
        printf("7: Delete a node from the beginning\n");
        printf("8: Delete a node from the end\n");
        printf("9: Delete a given node\n");
        printf("10: Delete a node after a given node\n");
        printf("11: Delete the entire list\n");
        printf("12: Sort the list\n");
        printf("13: Reverse the list\n");
        printf("14: Finding cycle in LL\n");
        printf("15: Finding Middle element in LL\n");
        printf("16: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = createList();
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("Enter data to add at the beginning: ");
                scanf("%d", &data);
                head = addAtBeginning(head, data);
                break;
            case 4:
                printf("Enter data to add at the end: ");
                scanf("%d", &data);
                head = addAtEnd(head, data);
                break;
            case 5:
                printf("Enter data to add before: ");
                scanf("%d", &before);
                printf("Enter data to add: ");
                scanf("%d", &data);
                head = addBeforeNode(head, before, data);
                break;
            case 6:
                printf("Enter data to add after: ");
                scanf("%d", &after);
                printf("Enter data to add: ");
                scanf("%d", &data);
                head = addAfterNode(head, after, data);
                break;
            case 7:
                head = deleteFromBeginning(head);
                break;
            case 8:
                head = deleteFromEnd(head);
                break;
            case 9:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                head = deleteNode(head, data);
                break;
            case 10:
                printf("Enter data to delete after: ");
                scanf("%d", &after);
                head = deleteAfterNode(head, after);
                break;
            case 11:
                deleteList(head);
                head = NULL;
                printf("List deleted.\n");
                break;
            case 12:
                head = sortList(head);
                break;
            case 13:
                head = reverseList(head);
                break;
            case 14:
                if (detectCycle(head)) {
                    printf("Cycle detected in the list.\n");
                } else {
                    printf("No cycle detected.\n");
                }
                break;
            case 15:
                data = findMiddle(head);
                if (data != -1) {
                    printf("Middle element is: %d\n", data);
                } else {
                    printf("List is empty.\n");
                }
                break;
            case 16:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 16);

    return 0;
}

