#include <stdio.h>
// main method
int main()
{
    int m, n;
    printf("Enetr the size of row and column\n");
    scanf("%d %d", &m, &n);
    int count = 0;
    int matrix[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter the elemnt of matrix[%d][%d] : ", i + 1, j + 1);
            scanf("\n%d", &matrix[i][j]);
            if (matrix[i][j] != 0)
            {
                count++;
            }
        }
    }
    // // Displaying the user defined matrix
    // printf("Teh matrix you entered is below :\n");
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         printf("%d\t", matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    // creating the sparse transpose
    int transpose[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            transpose[j][i]= matrix[i][j];
        }
    }
    // Creating the Sparse Matrix
    int p = count + 2, t = 2;
    int sparse[p][3];
    sparse[0][0] = 77;
    sparse[0][1] = 78;
    sparse[0][2] = 67;
    sparse[1][0] = m;
    sparse[1][1] = n;
    sparse[1][2] = count;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (transpose[i][j] != 0)
            {
                sparse[t][0] = i;
                sparse[t][1] = j;
                sparse[t][2] = transpose[i][j];
                t++;
            }
        }
    }
    // Displaying the Sparse Matrix
    printf("The created sparse matrix is below :\n");
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i < 1)
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