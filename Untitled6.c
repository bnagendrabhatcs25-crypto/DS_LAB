#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Create linked list
void create(struct Node **head)
{
    struct Node *newNode, *temp;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if(*head == NULL)
            *head = newNode;
        else
        {
            temp = *head;

            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }
}

// Insert at beginning
void insertFirst(struct Node **head)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = *head;
    *head = newNode;
}

// Insert at end
void insertEnd(struct Node **head)
{
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    if(*head == NULL)
        *head = newNode;
    else
    {
        temp = *head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }
}

// Insert at any position
void insertPosition(struct Node **head)
{
    struct Node *newNode, *temp;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos < 1)
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        insertFirst(head);
        return;
    }

    temp = *head;

    for(i = 1; i < pos-1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = temp->next;
    temp->next = newNode;
}

// Display linked list
void display(struct Node *head)
{
    struct Node *temp = head;

    if(temp == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    int ch;

    create(&head);

    do
    {
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at Position");
        printf("\n3. Insert at End");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: insertFirst(&head);
                    break;

            case 2: insertPosition(&head);
                    break;

            case 3: insertEnd(&head);
                    break;

            case 4: display(head);
                    break;

            case 5: printf("Exiting...");
                    break;

            default: printf("Invalid choice");
        }

    } while(ch != 5);

    return 0;
}

