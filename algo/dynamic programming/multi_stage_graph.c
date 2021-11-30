#include <stdio.h>
#include <limits.h>

int min = INT_MAX;
int source, destination;
void MSG(int n, int table[n][n], int s, int d, int mem[n][3])
{
    if (d == n)
    {
        return;
    }
    int M = INT_MAX, val, prev_node;
    for (int i = d; i >= 0; i--)
    {
        if (i > 0 && table[d][i - 1] != 0)
        {
            val = table[d][i - 1] + mem[i - 1][2];

            if (val < M)
            {
                M = val;
                prev_node = i - 1;
            }
        }
    }
    mem[d][0] = d;
    mem[d][1] = prev_node;
    mem[d][2] = M;
    MSG(n, table, s, d + 1, mem);
}

int main()
{
    int n = 8; // no of vertices
    // printf("N: ");
    // scanf("%d",&n);
    int table[][8] = {
        {0, 1, 2, 5, 0, 0, 0, 0},
        {1, 0, 0, 0, 4, 11, 0, 0},
        {2, 0, 0, 0, 9, 5, 16, 0},
        {5, 0, 0, 0, 0, 0, 2, 0},
        {0, 4, 9, 0, 0, 0, 0, 18},
        {0, 11, 5, 0, 0, 0, 0, 13},
        {0, 0, 16, 2, 0, 0, 0, 2},
        {0, 0, 0, 0, 18, 13, 2, 0}};

    int mem[8][3];
    // int a,b,w;
    mem[0][0] = 0;
    mem[0][1] = 0;
    mem[0][2] = 0;
    MSG(n, table, 0, 1, mem);
    for (int i = 0; i < 8; i++)
    {
        printf("%d\t%d\t%d\n", mem[i][0], mem[i][1], mem[i][2]);
    }
}
