#include <stdio.h>
// main method
int main()
{
    int i, j;
    printf("Enetr the no. of rows and column : ");
    scanf("\n%d %d", &i, &j);
    int arr[i][j];
    for (int m = 0; m < i; m++)
    {
        for (int n = 0; n < j; n++)
        {
            printf("Enetr the element in matrix[%d][%d] : ", m + 1, n + 1);
            scanf("\n%d", &arr[m][n]);
        }
    }
    printf("\n");
    // Displaying the above diagonal
    printf("The above diagonal is below : \n");
    for (int m = 0; m < i; m++)
    {
        for (int n = 0; n < j; n++)
        {
            if (m < n)
            {
                printf("%d\t", arr[m][n]);
            }
            else
                printf("\t");
        }
        printf("\n");
    }
    // Displaying the main/ principle diagonal
    printf("The main diagonal is below : \n");
    for (int m = 0; m < i; m++)
    {
        for (int n = 0; n < j; n++)
        {
            if (m == n)
            {
                printf("%d\t", arr[m][n]);
            }
            else
                printf(" \t");
        }
        printf("\n");
    }
    // Displaying the below diagonal
    printf("The below diagonal is below : \n");
    for (int m = 0; m < i; m++)
    {
        for (int n = 0; n < j; n++)
        {
            if (m > n)
            {
                printf("%d\t", arr[m][n]);
            }
            else
                printf("\t");
        }
        printf("\n");
    }
    return 0;
}