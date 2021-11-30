#include <stdio.h>

int check(int n, int table[n][n], int i, int j)
{
    // 2nd diogonal
    int t1 = i, t2 = j;

    while (i - 1 >= 0 && j + 1 <= (n - 1))
    {
        i = i - 1;
        j = j + 1;
        // printf("%d %d\n", i, j);
        if(table[i][j]==1){
            return 1;
        }
    }

    i = t1;
    j = t2;
    while (i + 1 <= (n - 1) && j - 1 >= 0)
    {
        i = i + 1;
        j = j - 1;
        // printf("%d %d\n", i, j);
        if(table[i][j]==1){
            return 1;
        }
    }

    // printf("\n\n1st diagonal\n");

    i = t1;
    j = t2;

    while (i+1<=(n-1) && j+1<=(n-1))
    {
        i = i+1;
        j = j+1;
        // printf("%d %d\n", i, j);
        if(table[i][j]==1){
            return 1;
        }
    }
    i = t1;
    j = t2;

    while (i-1>=0 && j-1>=0)
    {
        i = i-1;
        j = j-1;
        // printf("%d %d\n", i, j);
        if(table[i][j]==1){
            return 1;
        }
    }
    
    // vertical strip
    // printf("\n\nVertical strip\n");
    i = t1;
    j = t2;

    while (i-1>=0)
    {
        i = i-1;
        // printf("%d %d\n", i, j);
        if(table[i][j]==1){
            return 1;
        }
    }
    
    i = t1;
    j = t2;
    while (i+1<=(n-1))
    {
        i = i+1;
        // printf("%d %d\n", i, j);
        if(table[i][j]==1){
            return 1;
        }
    }
    return 0;
    
}

void print(int n,int table[n][n]){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(table[i][j]==1){
                printf("-\t");
            }else{
                printf("%d\t",table[i][j]);
            }
        }
        printf("\n");
        
    }
    printf("\n\n");
}

int count = 0;

void nQueens(int n, int table[n][n], int i)
{
    if(i==n){
        count++;
        print(n,table);
        return;
    }
    for (int k = 0; k < n; k++)
    {
        if(table[i][k]==0 && !check(n,table,i,k)){
            table[i][k] = 1;
            nQueens(n,table,i+1);
            table[i][k] = 0;
        }
    }
    
}

int main()
{
    int n;
    printf("N: ");
    scanf("%d", &n);
    int table[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            table[i][j] = 0;
        }

    }
    nQueens(n,table,0);
    printf("\n\n\nCount: %d",count);
}
