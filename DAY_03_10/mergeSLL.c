#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void create_list(struct Node **head, int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
}
// merge the lists in an alternate way
void mergeLists(struct Node **head1, struct Node **head2)
{
    struct Node *temp1 = *head1;
    struct Node *temp2 = *head2;
    struct Node *prev = NULL;
    while (temp1 != NULL && temp2 != NULL)
    {
        struct Node *next1 = temp1->next, *next2 = temp2->next;
        temp1->next = temp2;
        temp2->next = next1;
        prev = temp2;
        temp1 = next1;
        temp2 = next2;
    }
    if (temp2 != NULL)
    {
        prev->next = temp2;
    }
}
// displaying the input
void traverse(struct Node *head)
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
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    int i, m, n;
    printf("Enter the size of the first linked list: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        int data;
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        create_list(&head2, data);
    }
    // taking the output in list 2
    printf("Enter the size of the first linked list: ");
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        int data;
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        create_list(&head1, data);
    }
    printf("List 1: ");
    traverse(head1);
    printf("List 2: ");
    traverse(head2);
    mergeLists(&head2, &head1);
    printf("Merged list: ");
    traverse(head2);
    return 0;
}