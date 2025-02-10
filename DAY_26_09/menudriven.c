#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} *head;
// creating the doubly linked list
void create(int data)
{
    struct Node *nwnode = (struct Node *)malloc(sizeof(struct Node));
    nwnode->data = data;
    nwnode->next = NULL;
    nwnode->prev = NULL;
    if (head == NULL)
    {
        head = nwnode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nwnode;
        nwnode->prev = temp;
    }
}
// traversing the linked list
void traverse()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
// searching for an element
void search(int data)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            printf("Key found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Key not found\n");
}
// insertion at begin
void insert_begin(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    temp->prev = NULL;
    if (head != NULL)
        head->prev = temp;
    head = temp;
}
// insertion at the end
void insert_end(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
    {
        temp->prev = NULL;
        head = temp;
    }
    else
    {
        struct Node *temp2 = head;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
        temp->prev = temp2;
    }
}
// insert at any position
void insert_pos(int pos, int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("\nThere are less than %d elements", pos);
            return;
        }
    }
    newnode->data = data;
    if (pos == 1)
    {
        insert_begin(data);
        return;
    }
    else
    {
        struct Node *temp2 = newnode->next;
        newnode->next = newnode;
        temp2->prev = newnode;
        newnode->prev = newnode;
        newnode->next = temp2;
    }
}
// deletion at starting node
void delete_begin()
{
    if (head == NULL)
        printf("\n Linked list not created yet\n");
    else
    {
        struct Node *temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}
// deletion at the end
void delete_end()
{
    if (head == NULL)
        printf("\n UNDERFLOW");
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
    }
    else
    {
        struct Node *temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        // temp->prev->next = NULL;
        free(temp->next);
        temp->next= NULL;
    }
}
// delete at any posotion
void delete_pos(int pos)
{
    struct Node *temp = head;

    int i;

    for (i = 1; i < pos; i++)
    {
        temp = temp->next;
        if (temp == NULL){
            printf("\nThere are less than %d elements", pos);
            return;
        }
    }
    if (pos == 1)
    {
        delete_begin();
        return;
    }
    else
    {
        struct Node *temp2 = temp->prev;
        temp2->next = temp->next;
        free(temp);
        return;
    }
}
// main method
int main()
{
    int n, choice, data, pos, key;
    menu:
    printf("\nMAIN MENU\n");
    printf("Press 1. Creating the List\n");
    printf("Press 2. Display the List\n");
    printf("Press 3. Searching in the List\n");
    printf("Press 4. Insert at beginning\n");
    printf("Press 5. Insert at end\n");
    printf("Press 6. Insert at any position\n");
    printf("Press 7. Delete from beginning\n");
    printf("Press 8. Delete from end\n");
    printf("Press 9. Delete from any position\n");
    printf("Press 10. EXIT\n");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enetr the no. of node : ");
        scanf("\n%d", &n);
        for (int i = 0; i < n; i++)
        {
            printf("Enter the item to be inserted: ");
            scanf("%d", &data);
            create(data);
        }
        goto menu;
        break;

    case 2:
        traverse();
        goto menu;
        break;

    case 3:
        printf("Enter the key to search: ");
        scanf("%d", &key);
        search(key);
        goto menu;
        break;

    case 4:
        printf("Enter the item to be inserted: ");
        scanf("%d", &data);
        insert_begin(data);
        goto menu;
        break;

    case 5:
        printf("Enter the item to be inserted: ");
        scanf("%d", &data);
        insert_end(data);
        goto menu;
        break;

    case 6:
        printf("Enter the position at which to insert: ");
        scanf("%d", &pos);
        printf("Enter the item to be inserted: ");
        scanf("%d", &data);
        insert_pos(pos, data);
        goto menu;
        break;

    case 7:
        delete_begin();
        goto menu;
        break;

    case 8:
        delete_end();
        goto menu;
        break;

    case 9:
        printf("Enter the position from which to delete: ");
        scanf("%d", &pos);
        delete_pos(pos);
        goto menu;
        break;

    case 10:
        exit(0);
    default:
        printf("Invalid Choice");
    }
    return 0;
}