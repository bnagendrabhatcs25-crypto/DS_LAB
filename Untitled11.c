
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Create a doubly linked list
struct Node* createList(struct Node *head, int n) {
    int i, value;
    struct Node *newNode, *temp;

    for (i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &value);

        newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    return head;
}

// Insert a node to the left of a given node
struct Node* insertLeft(struct Node *head, int key, int value) {
    struct Node *temp, *newNode;

    temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node not found!\n");
        return head;
    }

    newNode = createNode(value);

    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        head = newNode;
    }

    temp->prev = newNode;

    return head;
}

// Delete a node based on a specific value
struct Node* deleteNode(struct Node *head, int key) {
    struct Node *temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node not found!\n");
        return head;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);

    return head;
}

// Display the list
void display(struct Node *head) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("NULL <-> ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main() {
    struct Node *head = NULL;
    int n, key, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createList(head, n);

    printf("\nOriginal Doubly Linked List:\n");
    display(head);

    printf("\nEnter the node value before which to insert: ");
    scanf("%d", &key);

    printf("Enter new value: ");
    scanf("%d", &value);

    head = insertLeft(head, key, value);

    printf("\nAfter Insertion:\n");
    display(head);

    printf("\nEnter the value to delete: ");
    scanf("%d", &key);

    head = deleteNode(head, key);

    printf("\nAfter Deletion:\n");
    display(head);

    return 0;
}

