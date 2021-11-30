#include <stdio.h>

double knapsack(int W, int wt[], int val[], int n, double profit[])
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    double total = 0;
    for (int i = 0; i <= n; i++)
    {
        int maxIndex = -1;
        double v = -1;
        for (int j = 0; j <= n; j++)
        {
            if (profit[j] != -1 && profit[j] > v)
            {
                maxIndex = j;
                v = profit[j];
            }
        }
        profit[maxIndex] = -1;
        
        if (W < wt[maxIndex])
        {
            // fractional weights
            printf("--%f",((double)W/(double)wt[maxIndex])*(double)val[maxIndex]);
            total += ((double)W/(double)wt[maxIndex])*(double)val[maxIndex];
            
        }
        else
        {
            total += val[maxIndex];
            W = W-wt[maxIndex];
        }
        printf("%f\n",total);
    }
    return total;
}

int main()
{
    int n = 4;
    int wt[] = {2,1,3,2};
    int val[] = {12,10,20,15};
    int W = 5;
    double profit[n];
    for (int i = 0; i < n; i++)
    {
        profit[i] = (val[i] / wt[i]);
    }
    double res = knapsack(W, wt, val, n - 1, profit);
    printf("\nKNAPSACK VALUE: %f", res);

}
