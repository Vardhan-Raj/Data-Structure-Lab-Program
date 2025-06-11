// This code creates a linked list, rearranges it so that nodes at odd positions come first followed by nodes at even positions, and displays the original and rearranged lists.
// The rearrangement is done in-place without using any additional data structures.

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

// Function to display the linked list
void display()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to create the linked list
void createList()
{
    struct Node *newnode, *temp = head;
    int n;

    printf("Enter the number of nodes in the List: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter the data for Node %d: ", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            temp = head;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

// Function to rearrange nodes: odd positions first, then even
void rearrangeOddEven()
{
    // Edge case: empty list or single node
    if (head == NULL || head->next == NULL)
        return;

    // Initialize pointers
    struct Node *odd = head;        // odd-positioned nodes
    struct Node *even = head->next; // even-positioned nodes
    struct Node *evenHead = even;   // store head of even list

    // Rearranging links
    while (even != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    // Attach even list after odd list
    odd->next = evenHead;
}

// Main method
int main()
{
    createList();

    printf("Original List:\n");
    display();

    rearrangeOddEven();

    printf("Rearranged List (Odd followed by Even):\n");
    display();

    return 0;
}