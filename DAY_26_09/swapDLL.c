// WAP to swap the alternate node of the double linked list
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
} *head;
// creating the linked list
void create(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct Node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
    }
}
// displaying the output
void traverse()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
// swapping the alterante nodes
void swap()
{
    struct Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        int temp2 = temp->next->data;
        // int temp2 = temp->data;
        temp->data = temp->next->next->data;
        temp->next->next->data = temp2;
        temp = temp->next->next->next;
    }
}
// main method
int main()
{
    int n;
    printf("Enter the number of nodes to be insert in the list : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int data;
        printf("Enter the item to be inserted at node no %d: ", i+1);
        scanf("%d", &data);
        create(data);
    }
    swap();
    traverse();
}