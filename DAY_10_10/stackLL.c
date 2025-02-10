// Implement stack using linked list.
#include<stdio.h>
#include<stdlib.h>
#define N 10
struct Node
{
    int data;
    struct Node *next;
} *top = NULL;
// push element in the stack
void Push(int dataa){
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = dataa;
    new->next = NULL;
    if(top == NULL)
        top=new;
    else{
        new->next = top;
        top=new;
    }
}
// delete element in stack
int Pop(){
    if(top==NULL){
        printf("Underflow\n");
        exit(0);
    }
    struct Node *temp = top;
    top = top->next;
    int x= temp->data;
    free(temp);
    return x;
}
// display the top element of the stack
int Peek(){
    if(top == NULL){
        printf("Underflow\n");
        exit(0);
    }
    return top->data;
}
// display the entire stack
void display(){
    if( top == NULL){
        printf("Underflow\n");
        exit(0);
    }
    int arr[N], i=0;
    while(top!=NULL){
        arr[i]= pop();
        i++;
    }
    while(i>=0){
        push(arr[i]);
        i--;
    }
}
// main method
int main(){
    push(5);
    display();
    return 0;
}