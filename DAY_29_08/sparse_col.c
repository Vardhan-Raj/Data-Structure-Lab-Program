#include <stdio.h>
// main method
int main()
{
    int m, n;
    printf("Enter the value of row and columnm : ");
    scanf("\n%d %d", &m, &n);
    int matrix[m][n], count = 0;
    // taking input in user defined matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enetr the %d element : ", i + 1);
            scanf("\n%d", &matrix[i][j]);
            if (matrix[i][j] != 0)
                count++;
        }
    }
    // Displaying the user defined matrix
    printf("\nTeh user defined matrix is below :\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    int p = count + 2, t = 2;
    int sparse[3][p];
    sparse[0][0] = 77;
    sparse[1][0] = 78;
    sparse[2][0] = 67;
    sparse[0][1] = m;
    sparse[1][1] = n;
    sparse[2][1] = count;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparse[0][t] = i;
                sparse[1][t] = j;
                sparse[2][t] = matrix[i][j];
                t++;
            }
        }
    }
    // Displaying the Sparse Matrix
    printf("The created sparse matrix is below :\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < p; j++)
        {
            if (j < 1)
            {
                printf("%c\t", sparse[i][j]);
            }
            else
                printf("%d\t", sparse[i][j]);
        }
        printf("\n");
    }
    return 0;
}