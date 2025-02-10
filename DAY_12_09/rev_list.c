#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *next;
} *head;
// creating the list
void create_list()
{
    int n;
    printf("Enetr the number of nodes in linked list : ");
    scanf("\n%d", &n);
    struct Node *temp1, *temp2 = head;
    for (int i = 0; i < n; i++)
    {
        temp1 = (struct Node *)malloc(sizeof(struct Node));
        printf("Enetr the element in linked list : ");
        scanf("\n%d", &temp1->info);
        if (head == NULL)
        {
            head = temp1;
        }
        else
        {
            temp2->next = temp1;
        }
        temp2 = temp1;
    }
    temp2->next = NULL;
    printf("\n");
}
// reverse the single linked list
void reverseList()
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
// traverse the linked list
void traverse()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}
// main method
int main()
{
    create_list();
    printf("Original list: ");
    traverse();
    reverseList();
    printf("Reversed list: ");
    traverse();
    return 0;
}