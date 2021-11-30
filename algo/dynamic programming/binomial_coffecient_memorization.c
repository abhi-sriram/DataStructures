#include <stdio.h>

int nCr(int n, int r, int mem[n + 1][r + 1])
{
    if (mem[n][r] != -1)
    {
        return mem[n][r];
    }
    if (n < r)
    {
        mem[n][r] = 0;
        return mem[n][r];
    }
    if (n == r || r == 0)
    {
        mem[n][r] = 1;
        return mem[n][r];
    }

    mem[n][r] = nCr(n - 1, r - 1, mem) + nCr(n - 1, r, mem);
    return mem[n][r];
}

int main()
{
    int n, r;
    printf("n:");
    scanf("%d", &n);
    printf("r:");
    scanf("%d", &r);

    int mem[n + 1][r + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < r + 1; j++)
        {

            mem[i][j] = -1;
        }
    }

    int res = nCr(n, r, mem);
    printf("(%d,%d) = %d\n\n", n, r, res);
}
