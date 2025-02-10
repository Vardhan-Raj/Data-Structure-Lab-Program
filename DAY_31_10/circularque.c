// WAP to implement the circular queue using array
#include<stdio.h>
#include<stdlib.h>
#define N 10
int queue[N];
int front = -1;
int rear = -1;
// function to insert the elememt 
void enqueue(int element){
    if(front == (rear+1)%N){
        printf("Circular queue overflow\n");
        exit(0);
    }
    else{
        if(front == -1){
            front = rear =0;
        }
        else
            rear = (rear+1)%N;
        queue[rear]= element;
    }
}
// function to delete the elememt
void dequeue(){
    if(front == -1){
        printf("Queue underflow\n");
        exit(0);
    }
    else{
        int x = queue[front];
        if(front == rear)
            front = rear = -1;
        else{
            front = (front+1)%N;
            printf("%d element is deleted\n", x);
        }
    }
}