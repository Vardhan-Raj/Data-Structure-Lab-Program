// WAMDP to implement a single linked list
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *next;
} *head;
// creating the linked list
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
// traversing the input
void traverse()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->info);
        temp = temp->next;
    }
    printf("\n");
}
// insert at begin
void insert_begin(int k)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->info = k;
    temp->next = head;
    head = temp;
}
// insert at last
void insert_end(int k)
{
    struct Node *newnode, *temp = head;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->info = k;
    if(head==NULL)
        head=newnode;
    else{
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    newnode->next = NULL;
}
// insert at position
void insert_pos(int data, int pos)
{
    struct Node *newnode, *temp = head;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->info = data;
    pos--;
    while (--pos)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
// deletion at begin
int delete_begin()
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("No element to delete in Linked list\n");
        return 0;
    }
    printf("The deleted element is : %d\n", head->info);
    head = head->next;
    temp->next = NULL;
    free(temp);
    return 1;
}
// delete at last
int delete_last()
{
    struct Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return 1;
}
// delete at position
int delete_pos(int pos)
{
    struct Node *temp = head, *temp2 = head;
    if(pos == 1){
        int x = delete_begin();
        return 0;
    }
    for (int i = 1; i <= pos - 2; i++)
    {
        temp = temp->next;
    }
    temp2 = temp->next;
    temp->next = temp->next->next;
    temp2->next = NULL;
    free(temp2);
    return 1;
}
// searching the element
void searching(int k)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->info == k)
            printf("%d Element found\n", k);
        temp = temp->next;
    }
    printf("\n");
}
// main method1
int main()
{
    int ch, choice;
    int k, l, j, m, z, key, i = 1;
    do
    {
        printf("Press 1, to enetring in linked list : ");
        scanf("\n%d", &ch);
        printf("\n");
        if (ch == 1)
        {
            printf("Press 1, to create a linked list\n");
            printf("Press 2, to traverse the list\n");
            printf("Press 3, to insert at begin in the list\n");
            printf("Press 4, to insert at last in the list\n");
            printf("Press 5, to insert at any position in the list\n");
            printf("Press 6, to delete at begin in the list\n");
            printf("Press 7, to delete at last in the list\n");
            printf("Press 8, to delete at any position in the list\n");
            printf("Press 9, to search in the linked list\n");
            printf("\nEnter the choice : ");
            scanf("\n%d", &choice);
            switch (choice)
            {
            case 1:
                create_list();
                break;
            case 2:
                traverse();
                break;
            case 3:
                printf("Enter the element you want to insert at begin : ");
                scanf("\n%d", &k);
                insert_begin(k);
                traverse();
                break;
            case 4:
                printf("Enter the element you want to insert at last node : ");
                scanf("\n%d", &l);
                insert_end(l);
                traverse();
                break;
            case 5:
                printf("Enter the element and its position : ");
                scanf("%d %d", &j, &m);
                insert_pos(j, m);
                traverse();
                break;
            case 6:
                delete_begin();
                traverse();
                break;
            case 7:
                delete_last();
                traverse();
                break;
            case 8:
                printf("Enetr the position you want to delete : ");
                scanf("\n%d", &z);
                delete_pos(z);
                traverse();
                break;
            case 9:
                printf("Enetr the element to search : ");
                scanf("\n%d", &key);
                searching(key);
            default:
                printf("Invalid Input\n");
            }
        }
        else
        {
            printf("INVALID INPUT\n\n");
            printf("Press 1, to continue again or press any number to exit\n");
            scanf("%d", &i);
            printf("\n");
        }
    } while (i == 1);
    printf("Your desicion to leave the page is accepted\n");
    return 0;
}