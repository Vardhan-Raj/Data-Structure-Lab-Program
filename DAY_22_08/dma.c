#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// function for prime
void isPrime(int *ptr, int n){
    int sum = 0, flag;
    for(int i = 0; i < n; i++){
        flag = 0;
        for (int j = 2; j <= sqrt(ptr[i]); j++){
            if (!(ptr[i] % j)){
                flag = 1;
                break;
            }
        }
        if (!flag){
            sum += ptr[i];
        }
    }
    printf("Sum of prime elements is %d\n", sum);
}
// main method
int main(){
    int n;
    scanf("%d", &n);
    int *ptr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d", &ptr[i]);
    }
    isPrime(ptr, n);
    free(ptr);
    return 0;
}