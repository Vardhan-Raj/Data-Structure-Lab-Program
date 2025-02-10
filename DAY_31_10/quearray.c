#include <stdio.h>
#include <stdlib.h>
#define N 10

int queue[N];
int front = -1;
int rear = -1;
// function to insert the element
void enqueue(int ele)
{
    if (rear == N - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = rear+1;
    queue[rear] = ele;
}
// function to delete the element
int dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        exit(0);
    }
    int x = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return x;
}
// function to display the top most element
int peek()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        exit(0);
    }
    return queue[front];
}
// function to print the entire queue
void traverse()
{
    // int i;
    if (front == -1)
    {
        printf("No element\n");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
}
// main method
int main()
{
    int choice, item;
    printf("Getting started with queue-server\n");
    while (1)
    {
        printf("\nPress1->Enqueue\nPress2->Dequeue\nPress3->Peek\nPress4->Traverse\nPress5->Exit\n");
        printf("Enter your choice: ");
        scanf("\n%d", &choice);
        switch (choice){
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