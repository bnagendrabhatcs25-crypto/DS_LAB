
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Create linked list
void createList(struct Node **head, int n)
{
    struct Node *newNode, *temp;
    int i;

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

// Delete first node
void deleteBeginning(struct Node **head)
{
    struct Node *temp;

    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = *head;
    *head = (*head)->next;

    free(temp);

    printf("First node deleted\n");
}

// Delete specified position
void deletePosition(struct Node **head, int pos)
{
    struct Node *temp, *prev;
    int i;

    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(pos < 1)
    {
        printf("Invalid position\n");
        return;
    }

    temp = *head;

    if(pos == 1)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    for(i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Node deleted\n");
}

// Delete last node
void deleteEnd(struct Node **head)
{
    struct Node *temp, *prev;

    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = *head;

    if(temp->next == NULL)
    {
        *head = NULL;
        free(temp);
        return;
    }

    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);

    printf("Last node deleted\n");
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
    int n, choice, position;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if(n < 0)
    {
        printf("Invalid number of nodes!\n");
        return 1;
    }

    createList(&head, n);

    printf("\nOriginal linked list:\n");
    display(head);

    do
    {
        printf("\n1. Delete from Beginning");
        printf("\n2. Delete from Specified Position");
        printf("\n3. Delete from End");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                deleteBeginning(&head);
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deletePosition(&head, position);
                break;

            case 3:
                deleteEnd(&head);
                break;

            case 4:
                display(head);
                break;

            case 5:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 5);

    return 0;
}
