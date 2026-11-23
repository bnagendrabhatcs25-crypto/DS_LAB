
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

// Insert node at the end
struct Node* insert(struct Node *head, int value) {
    struct Node *newNode = createNode(value);
    struct Node *temp;

    if (head == NULL)
        return newNode;

    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

// Display linked list
void display(struct Node *head) {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Sort linked list
void sortList(struct Node *head) {
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
}

// Reverse linked list
struct Node* reverse(struct Node *head) {
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Concatenate two linked lists
struct Node* concatenate(struct Node *head1,
                         struct Node *head2) {
    struct Node *temp;

    if (head1 == NULL)
        return head2;

    temp = head1;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head2;

    return head1;
}

// Main function
int main() {
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;

    int n, m, i, value;

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);

    printf("Enter elements of first list:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        head1 = insert(head1, value);
    }

    printf("\nFirst Linked List:\n");
    display(head1);

    printf("\nSorted Linked List:\n");
    sortList(head1);
    display(head1);

    printf("\nReversed Linked List:\n");
    head1 = reverse(head1);
    display(head1);

    printf("\nEnter number of nodes in second list: ");
    scanf("%d", &m);

    printf("Enter elements of second list:\n");

    for (i = 0; i < m; i++) {
        scanf("%d", &value);
        head2 = insert(head2, value);
    }

    printf("\nSecond Linked List:\n");
    display(head2);

    head1 = concatenate(head1, head2);

    printf("\nConcatenated Linked List:\n");
    display(head1);

    return 0;
}

