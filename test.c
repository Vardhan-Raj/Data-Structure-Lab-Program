#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int coeff;         
    int pow_x;        
    int pow_y;         
    struct Node *next; 
};
struct Node *create_node(int coeff, int pow_x, int pow_y)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->coeff = coeff;
    new_node->pow_x = pow_x;
    new_node->pow_y = pow_y;
    new_node->next = NULL;
    return new_node;
}
void insert_node(struct Node **head, int coeff, int pow_x, int pow_y)
{
    struct Node *new_node = create_node(coeff, pow_x, pow_y);
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    { 
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}
void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%dx^%dy^%d", temp->coeff, temp->pow_x, temp->pow_y);
        if (temp->next != NULL)
        {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}
struct Node *prod(struct Node *poly1, struct Node *poly2)
{
    struct Node *result = NULL; 
    struct Node *p1 = poly1;    
    struct Node *p2 = poly2;    
    while (p1 != NULL)
    {
        while (p2 != NULL)
        { 
            int coeff = p1->coeff * p2->coeff;
            int pow_x = p1->pow_x + p2->pow_x;
            int pow_y = p1->pow_y + p2->pow_y;
            insert_node(&result, coeff, pow_x, pow_y);
            p2 = p2->next;
        }
        p2 = poly2;
        p1 = p1->next;
    }
    return result;
}
int main()
{
    struct Node *poly1 = NULL, *poly2 = NULL;
    int deg1, deg2;
    printf("enter the degree of poly 1 and poly2 : ");
    scanf("%d %d", &deg1, &deg2);
    for(int i=0;i<deg1;i++){
        int coff, powx, powy;
        printf("enter the coefficient, powx and powy at %d : ", i + 1);
        scanf("\n%d %d %d", &coff, &powx, &powy);
        insert_node(&poly1, coff, powx, powy);
    }
    printf("Enetr the second polynomial \n");
    for(int i=0;i<deg2;i++){
        int coff, powx, powy;
        printf("enter the coefficient, powx and powy at %d : ", i + 1);
        scanf("\n%d %d %d", &coff, &powx, &powy);
        insert_node(&poly2, coff, powx, powy);
    }
    printf("First polynomial: ");
    display(poly1);
    printf("Second polynomial: ");
    display(poly2);
    struct Node *poly3 = prod(poly1, poly2);
    printf("Result polynomial: ");
    display(poly3);
    return 0;
}