#include<stdio.h>

int max(int a,int b){
    return a>b?a:b;
}

int knapsack(int W,int wt[],int val[],int n,int mem[][W+1]){
    if(W==0 || n==0){
        // base case
        return 0;
    }

    if(W<wt[n]){
        // if nth item has more weight than knapsack weight
        // we cannot include that item
        return knapsack(W,wt,val,n-1,mem);
    }

    if(mem[n+1][W]!=-1){
        // using already calculated values
        // memorization technique
        return mem[n+1][W];
    }

    // including nth item value and excluding nth item val
    // taking the max val of both the values
    mem[n+1][W] = max((val[n]+knapsack(W-wt[n],wt,val,n-1,mem)),knapsack(W,wt,val,n-1,mem));
    return mem[n+1][W];

}

int main(){
    int n = 3; // total items
    int val[] = {60,100,120}; // weight array
    int wt[] ={10,20,30}; // cost array
    int W = 50; // knapsack weight
    int mem[n+1][W+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < W+1; j++)
        {
            if(i==0 || j==0){
                mem[i][j] = 0;
            }else{
                mem[i][j] = -1;
            }
        }
        
    }
    
    int res = knapsack(W,wt,val,n-1,mem);
    printf("KNAPSACK VALUE: %d\n",res);
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < W+1; j++)
        {
            printf("%d ",mem[i][j]);
        }
        printf("\n");
    }
}
