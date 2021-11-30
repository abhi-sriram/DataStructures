#include <stdio.h>

int main()
{
    int n, v;
    printf("No.of matrices: ");
    scanf("%d", &n);
    int arr[n + 1];
    int mem[n][n];
    // for (int i = 0; i < n; i++)
    // {
    //     printf(": ");
    //     scanf("%d", &v);
    //     arr[i] = v;
    // }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                mem[i][j] = 0;
            }
            else
            {
                mem[i][j] = -1;
            }
        }
    }

    int i = 0, j = 1, j_temp = j;
    while (i != 0 || j != n)
    {
        mem[i][j] = 0;
        j++;
        i++;
        if (j == n)
        {
            i = 0;
            j = j_temp + 1;
            j_temp = j;
        }
    }
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            printf("%d ", mem[i][j]);
        }
        printf("\n");
    }
}
