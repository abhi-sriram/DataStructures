#include <stdio.h>

int nCr(int n, int r)
{
    if (n < r)
    {
        return 0;
    }
    if (n == r || r == 0)
    {
        return 1;
    }
    if (n - r == 1)
    {
        return n;
    }

    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main()
{
    int n, r;
    printf("n:");
    scanf("%d", &n);
    printf("r:");
    scanf("%d", &r);

    int res = nCr(n, r);
    printf("(%d,%d) = %d", n, r, res);
}
