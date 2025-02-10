#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *head = NULL;
// function to display list
void display()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        // if (temp->next != NULL)
        // {
        //     printf("->");
        // }
        temp = temp->next;
    }
    printf("\n");
}
// function to create linked list
void createList()
{
    struct Node *newnode, *temp = head;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the data for Node %d:", i + 1);
        scanf("%d", &newnode->data);
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp->next = newnode;
        }
        temp = newnode;
    }
    temp->next = NULL;
}
// function to rearrange the list
void rearrange()
{
    struct Node *temp = head, *temp2 = head->next, *temp3 = temp2;
    while (temp->next != NULL && temp2->next != NULL)
    {
        temp->next = temp2->next;
        temp = temp2->next;
        temp2->next = temp->next;
        temp2 = temp->next;
    }
    temp->next = temp3;
}
// main method
int main()
{
    printf("Enter the number of nodes in the List: ");
    createList();
    display();
    rearrange();
    display();
    return 0;
}