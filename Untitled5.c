#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void insert() {
    int value;
    if (rear == SIZE - 1) {
        printf("Queue is overflow\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        printf("Enter the value to insert: ");
        scanf("%d", &value);
        rear++;
        queue[rear] = value;
        printf("Successfully inserted: %d\n", value);
    }
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue is underflow\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;

    while (1) {

        printf("\n--- QUEUE OPERATIONS ---");
        printf("\n1. Insert (Enqueue)");
        printf("\n2. Delete (Dequeue)");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        if (choice == 1) {
            insert();
        } else if (choice == 2) {
            delete ();
        } else if (choice == 3) {
            display();
        } else if (choice == 4) {
            printf("Exit\n");
            exit(0);
        } else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

