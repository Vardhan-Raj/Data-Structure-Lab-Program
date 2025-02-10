#include <stdio.h>
// main method
int main()
{
    int arr1[100] = {0};
    int arr2[100] = {0};
    int product[200] = {0};
    int m, n;
    // int sum[100];
    // taking input in first polynomial
    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &m);
    printf("Enter coefficients for the first polynomial (from x^0 ... x^%d):\n", m);
    for (int i = 0; i <= m; i++)
    {
        scanf("%d", &arr1[i]);
    }
    // taking input in second polynomial
    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &n);
    printf("Enter coefficients for the second polynomial (from x^0 x^1 ... x^%d):\n", n);
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &arr2[i]);
    }
    // process of multiplication
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            product[i + j] = product[i + j] + arr1[i] * arr2[j];
        }
    }
    // displaying the multiplication 
    printf("Product polynomial coefficients:\n");
    for (int i = 0; i <= n + m; i++)
    {
        printf("%d ", product[i]);
    }
    return 0;
}