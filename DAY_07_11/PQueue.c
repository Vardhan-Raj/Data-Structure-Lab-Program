// Write a menu driven program to implement priority queue operations such as Enqueue, Dequeue,
// Traverse using linked list.
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    int priority;
    struct node *next;
} Node;

Node *newNode(int data, int priority)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;
    return temp;
}

int peek(Node **head)
{
    return (*head)->data;
}

void pop(Node **head)
{
    Node *temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

void push(Node **head, int data, int priority)
{
    Node *start = (*head);
    Node *temp = newNode(data, priority);
    if ((*head)->priority > priority)
    {
        temp->next = *head;
        (*head) = temp;
    }
    else
    {
        while (start->next != NULL && start->next->priority < priority)
        {
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
}

int isEmpty(Node **head)
{
    return (*head) == NULL;
}

void traverse(Node **head)
{
    Node *start = (*head);
    if (isEmpty(head))
    {
        printf("Queue is empty\n");
        return;
    }
    while (start != NULL)
    {
        printf("Data = %d, Priority = %d\n", start->data, start->priority);
        start = start->next;
    }
}

int main()
{
    Node *pq = newNode(-1, -1);
    int choice, data, priority;
    do
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Input the item value to be added in the queue : ");
            scanf("%d", &data);
            printf("Enter its priority : ");
            scanf("%d", &priority);
            push(&pq, data, priority);
            break;
        case 2:
            if (isEmpty(&pq))
            {
                printf("Queue Underflow\n");
            }
            else
            {
                printf("Deleted item is %d\n", peek(&pq));
                pop(&pq);
            }
            break;
        case 3:
            traverse(&pq);
            break;
        case 4:
            break;
        default:
            printf("Wrong choice\n");
        }
    } while (choice != 4);
    return 0;
}
