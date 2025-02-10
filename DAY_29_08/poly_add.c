#include <stdio.h>
// main method
int main()
{
    int m, n;
    printf("Enter the highest degree of the first polynomial: ");
    scanf("%d", &m);
    int a[m];
    printf("Enter the coefficients a, b, c and so on of the polynomial aX^0 + bx^1 + cx^3 + dx^4.....\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the highest degree of the second polynomial: ");
    scanf("%d", &n);
    int b[n];
    printf("Enter the coefficients a1, a2, a3..., of the polynomial a1x^0 + a2x^1 + a3x^3 + a4x^4.....\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }
    if (m > n)
    {
        for (int i = 0; i < n; i++)
        {
            a[i] += b[i];
        }
        printf("Polynomial addition is below : \n");
        for (int i = 0; i < m; i++)
        {
            printf("%d ", a[i]);
        }
    }
    else if (m < n)
    {
        for (int i = 0; i < m; i++)
        {
            b[i] += a[i];
        }
        printf("Polynomial addition is below : \n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", b[i]);
        }
    }
    else if(m==n)
    {
        for (int i = 0; i < n; i++)
        {
            a[i] += b[i];
        }
        printf("Polynomial addition is below : \n");
        for (int i = m; i >= 0; i++)
        {
            printf("%d ", a[i]);
        }
    }
    return 0;
}