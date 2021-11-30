#include<stdio.h>

int max(int a,int b){
    return a>b?a:b;
}

int knapsack(int W,int wt[],int val[],int n){
    if(W==0 || n==0){
        // base case
        return 0;
    }
    if(W<wt[n]){
        // if nth item has more weight than knapsack weight
        // we cannot include that item
        return knapsack(W,wt,val,n-1);
    }
    // including nth item value and excluding nth item val
    // taking the max val of both the values
    return max((val[n]+knapsack(W-wt[n],wt,val,n-1)),knapsack(W,wt,val,n-1));
}

int main(){
    int n = 5; // total items
    int val[] = {1,6,18,22,28}; // weight array
    int wt[] ={1,2,5,6,7}; // cost array
    int W = 11; // knapsack weight
    int res = knapsack(W,wt,val,n-1);
    printf("KNAPSACK VALUE: %d",res);
}
