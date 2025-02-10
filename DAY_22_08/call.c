#include<stdio.h>
// call by value function
void callByValue(int a, int b){
    if(a<b)
        printf("%d is smaller than %d\n", a,b);
    else if(a>b)
        printf("%d is greater than %d\n", a,b);
    else 
        printf("Both numbers are same\n");
}
// call by address function
void callByAddress(int *a, int *b){
    if (*a<*b)
        printf("%d is smaller than %d\n", *a, *b);
    else if(*a>*b)
        printf("%d is greater than %d\n", *a, *b);
    else 
        printf("Both numbers are same\n");
}
// main method
int main(){
    int a, b;
    printf("Enter the value of a and b\n");
    scanf("%d %d", &a, &b);
    callByValue(a,b);
    callByAddress(&a, &b);
    return 0;
}