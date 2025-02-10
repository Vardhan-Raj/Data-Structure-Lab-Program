// WAP in c to swap in DLL
#include <stdio.h>
#include <stdlib.h>
// doubly linked list decleration
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} *head = NULL;
// create new nodes
void createNode(int dta)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = dta;
    temp->next = head;
    temp->prev = NULL;
    if (head != NULL)
        head->prev = temp;
    head = temp;
}
// function to swap the alternate nodes
void swap()
{
    struct Node *temp = head;
    while (temp != NULL && temp->next != NULL && temp->next->next != NULL)
    {
        int temp2 = temp->data;
        temp->data = temp->next->next->data;
        temp->next->next->data = temp2;
        temp = temp->next->next->next;
    }
}
// traverse the linked list
void traverse()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
// main method
int main()
{
    int n, i, x;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the node values: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        createNode(x);
    }
    // traverse();
    swap();
    traverse();
    return 0;
}
