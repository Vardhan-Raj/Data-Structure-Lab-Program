#include <stdio.h>
// main method
int main()
{
    int m, n;
    printf("Enetr the size of row and column\n");
    scanf("%d %d", &m, &n);
    int mat1[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter the elemnt of mat1[%d][%d] : ", i + 1, j + 1);
            scanf("\n%d", &mat1[i][j]);
        }
    }
    int a, b;
    printf("Enetr the size of row and column of second matrix : ");
    scanf("\n%d %d", &a, &b);
    int mat2[a][b];
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("Enter the elemnt of matrix[%d][%d] : ", i + 1, j + 1);
            scanf("\n%d", &mat2[i][j]);
        }
    }
    // adding the sparse matrix
    int add[m][n], count=0;
    if (a == m && b == n)
    {
        printf("\nAddition done\n");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                add[i][j] = mat1[i][j] + mat2[i][j];
                if(add[i][j]!=0)
                    count++;
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
                if (add[i][j] != 0)
                {
                    sparse[t][0] = i;
                    sparse[t][1] = j;
                    sparse[t][2] = add[i][j];
                    t++;
                }
            }
        }
        // Displaying the Sparse Matrix
        printf("The created sparse mat1 is below :\n");
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
    }
    else
        printf("Addition not possible, Sparse matrix not created yet\n");
    return 0;
}