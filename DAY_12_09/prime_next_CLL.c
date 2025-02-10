#include <stdio.h>
#include <stdlib.h>
// structure of linked list
struct Node
{
    int info;
    struct Node *next;
} *head;
// creating the single circular linked list
void createCSLL()
{
    int n;
    printf("Enetr the number of nodes in linked list : ");
    scanf("\n%d", &n);
    struct Node *newnode, *temp = head;
    for (int i = 0; i < n; i++)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enetr the element in linked list : ");
        scanf("\n%d", &newnode->info);
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
    temp->next = head;
    printf("\n");
}
// traversing the single circular linked list
void traverse()
{
    struct Node *temp = head;
    do
    {
        printf("%d\t", temp->info);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
// check for prime
int isPrime(int n)
{
    if (n <= 1)
    {
        return 0;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
// print next element of prime value in node
void printPrimeNext()
{
    struct Node *temp = head, *temp2;
    do
    {
        if (isPrime(temp->info))
        {
            printf("%d\t", temp->next->info);
        }
        temp = temp->next;
    } while (temp != head);
}
// main method
int main()
{
    createCSLL();
    printf("The original list is: ");
    traverse();
    printf("The next element of prime numbers are: ");
    printPrimeNext();
    return 0;
}