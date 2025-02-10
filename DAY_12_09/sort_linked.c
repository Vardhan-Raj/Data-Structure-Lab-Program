#include <stdio.h>
#include <stdlib.h>
// Define a structure for a node in a linked list
struct Node
{
    int info;
    struct Node *next;
};

// Function to insert a node at the end of a linked list
void create_list(struct Node **head, int n)
{
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
// Function to merge and sort two linked lists
struct Node *mergeAndSort(struct Node *list1, struct Node *list2)
{
    struct Node *result = NULL;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->info < list2->info)
        {
            create_list(&result, list1->info);
            list1 = list1->next;
        }
        else
        {
            create_list(&result, list2->info);
            list2 = list2->next;
        }
    }
    while (list1 != NULL)
    {
        create_list(&result, list1->info);
        list1 = list1->next;
    }
    while (list2 != NULL)
    {
        create_list(&result, list2->info);
        list2 = list2->next;
    }
    return result;
}
// traversing the input
void traverse(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->info);
        temp = temp->next;
    }
    printf("\n");
}
// main method
int main()
{
    struct Node *list1 = NULL;
    int n;
    printf("Enetr the no. of nodes in List 1 : ");
    scanf("\n%d", &n);
    create_list(&list1, n);
    struct Node *list2 = NULL;
    int j;
    printf("Enetr the no. of nodes in List 1 : ");
    scanf("\n%d", &j);
    create_list(&list2, j);
    // Display the original lists
    printf("Original List 1: ");
    traverse(list1);
    printf("Original List 2: ");
    traverse(list2);

    // Merge and sort the lists
    struct Node *mergedList = mergeAndSort(list1, list2);

    // Display the merged and sorted list
    printf("Merged and Sorted List: ");
    traverse(mergedList);
    return 0;
}
