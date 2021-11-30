#include<stdio.h>

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
            if(i<j){
                mem[i][j] = 0;
            }
            else if(i==j || j==0){
                mem[i][j] = 1;
            }
            else{
                mem[i][j] = mem[i-1][j-1]+mem[i-1][j];
            }
        }
    }

    // int res = nCr(n, r, mem);
    // printf("(%d,%d) = %d\n\n", n, r, res);
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < r + 1; j++)
        {
            printf("%d\t", mem[i][j]);
        }
        printf("\n");
    }
}
