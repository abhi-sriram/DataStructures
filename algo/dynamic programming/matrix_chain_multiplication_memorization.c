#include <stdio.h>
#include <limits.h>

int MCM(int arr[], int i, int j, int mem[j+1][j+1])
{
    if (i == j)
    {
        mem[i][j] = 0;
        return 0;
    }

    if (mem[i][j] != -1)
    {
        return mem[i][j];
    }else{
        int min = INT_MAX,temp;

        for (int k = i; k < j; k++)
        {
            temp = MCM(arr,i,k,mem) + MCM(arr,k+1,j,mem) + arr[i-1]*arr[k]*arr[j];
            mem[i][j] = temp;
            if(temp<min){
                min = temp;
            }
        }
        return min;
        
    }

    
    // mem[i][j] = min;
    // return mem[i][j];
}

int main()
{
    int n, v;
    printf("No.of matrices: ");
    scanf("%d", &n);
    int arr[n + 1];
    int mem[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        printf(": ");
        scanf("%d", &v);
        arr[i] = v;
        for (int j = 0; j <= n; j++)
        {
            mem[i][j] = -1;
        }
    }

    printf("\n\n");
    int res = MCM(arr, 1, n, mem);
    printf("MIN: %d\n", res);

    for (int i = 0; i <=n; i++)
    {
        for (int j = 0; j <=n; j++)
        {
            printf("%d\t",mem[i][j]);
        }
        printf("\n");
        
    }
    
}

// 40 20 30 10 30 = 26000
// 10 20 30 40 30 = 30000
// 10 20 30 = 6000
