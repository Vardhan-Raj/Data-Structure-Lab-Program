#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*front = NULL, *rear = NULL;
// funtion to insert data into Linked List
void enqueue(int item)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;
    if (rear == NULL)
    {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}
// funtion to delete data from Linked List
int dequeue()
{
    if (front == NULL)
    {
        printf("Queue Underflow\n");
        exit(0);
    }
    struct Node *temp = front;
    int item = temp->data;
    front = front->next;
    if (front == NULL)
    {
        rear = NULL;
    }
    free(temp);
    return item;
}
// // funtion to display the top element of Linked List
int peek()
{
    if (front == NULL)
    {
        printf("Queue Underflow\n");
        exit(0);
    }
    return front->data;
}
// displaing the entite Queue
void traverse()
{
    if (front == NULL)
    {
        printf("No elements\n");
        return;
    }
    struct Node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
// main method
int main()
{
    int choice, item;
    printf("Getting started with queue linked list\n");
    while (1)
    {
        printf("\nPress1->Enqueue\nPress2->Dequeue\nPress3->Peek\nPress4->Traverse\nPress5->Exit\n");
        printf("Enter your choice: ");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to EnQueue: ");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 2:
            printf("Dequeued item: %d\n", dequeue());
            break;
        case 3:
            printf("Top item: %d\n", peek());
            break;
        case 4:
            printf("The display of the queue: ");
            traverse();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}