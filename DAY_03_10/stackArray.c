// WAP to implement Stack using array
#include<stdio.h>
#include<stdlib.h>
# define N 10
int stack[N];
int top = -1;
// to push an element into the stack
void push(int data){
    if(top==(N-1)){
        printf("Stack Overflow\n");
        exit(0);
    }
    top=top+1;
    stack[top]=data;
}
// function to pop an element
int pop(){
    if(top==-1){
        printf("Stack Underflow\n");
        exit(0);
    }
    int x= stack[top];
    top=top-1;
    return x;
}
// display the peek element
int peek(){
    if(top==-1){
        printf("Stack Underflow\n");
        exit(0);
    }
    return stack[top];
}
void traverse(){
    if(top==-1){
        printf("\nStack Underflow\n");
        exit(0);
    }
    int arr[N], i=0;
    while(top>=0){
        arr[i]=pop();
        printf("%d\t", arr[i]);
        i++;
    }
    while(i>=0){
        push(arr[i]);
        i--;
    }
}
// main method
int main(){
    printf("Enetr the value in stack : ");
    for(int i=0;i<N;i++){
        int x;
        scanf("\n%d", &x);
        push(x);
    }
    printf("\nThe peek element is %d\n", peek());
    pop();
    traverse();
    return 0;
}