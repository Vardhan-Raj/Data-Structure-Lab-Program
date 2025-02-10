// Write a menu driven program to implement Deques (both Inputrestricted and output-restricted) and
// performed operations such as Enqueue, Dequeue, Peek, IsEmpty, IsFull using static array.
#include <stdio.h>
#define MAX 7
int deque[MAX];
int left = -1, right = -1;

void insert_from_right(int item)
{
    if ((left == 0 && right == MAX - 1) || (left == right + 1))
    {
        printf("Queue Overflow \n");
        return;
    }
    if (left == -1)
    {
        left = 0;
        right = 0;
    }
    else if (right == MAX - 1)
        right = 0;
    else
        right = right + 1;
    deque[right] = item;
}

void insert_from_left(int item)
{
    if ((left == 0 && right == MAX - 1) || (left == right + 1))
    {
        printf("Queue Overflow \n");
        return;
    }
    if (left == -1)
    {
        left = 0;
        right = 0;
    }
    else if (left == 0)
        left = MAX - 1;
    else
        left = left - 1;
    deque[left] = item;
}

void delete_from_left()
{
    if (left == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted from queue is : %d\n", deque[left]);
    if (left == right)
    {
        left = -1;
        right = -1;
    }
    else if (left == MAX - 1)
        left = 0;
    else
        left = left + 1;
}

void delete_from_right()
{
    if (left == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted from queue is : %d\n", deque[right]);
    if (left == right)
    {
        left = -1;
        right = -1;
    }
    else if (right == 0)
        right = MAX - 1;
    else
        right = right - 1;
}

void display_queue()
{
    int front_pos = left, rear_pos = right;
    if (left == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements :\n");
    if (front_pos <= rear_pos)
    {
        while (front_pos <= rear_pos)
        {
            printf("%d ", deque[front_pos]);
            front_pos++;
        }
    }
    else
    {
        while (front_pos <= MAX - 1)
        {
            printf("%d ", deque[front_pos]);
            front_pos++;
        }
        front_pos = 0;
        while (front_pos <= rear_pos)
        {
            printf("%d ", deque[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
}

int main()
{
    int choice, item;
    do
    {
        printf("1.Insert at right\n");
        printf("2.Insert at left\n");
        printf("3.Delete from right\n");
        printf("4.Delete from left\n");
        printf("5.Display\n");
        printf("6.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Input the element for adding in queue : ");
            scanf("%d", &item);
            insert_from_right(item);
            break;
        case 2:
            printf("Input the element for adding in queue : ");
            scanf("%d", &item);
            insert_from_left(item);
            break;
        case 3:
            delete_from_right();
            break;
        case 4:
            delete_from_left();
            break;
        case 5:
            display_queue();
            break;
        case 6:
            break;
        default:
            printf("Wrong choice\n");
        }
    } while (choice != 6);
    return 0;
}
