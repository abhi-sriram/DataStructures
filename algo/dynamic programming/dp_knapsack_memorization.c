#include <stdio.h>


int arr[5+1][10+1];


int max(int a,int b){
	return a>b?a:b;
}

int knapsack(int n,int W,int *wt,int *val){
	if(n==0 || W<=0){
		arr[n][W] = 0;
		return arr[n][W];
	}
	else if(arr[n][W]!=-1){
		return arr[n][W];
	}
	else{
		if(wt[n-1]<=W){
			arr[n][W] = max((val[n-1]+knapsack(n-1,W-wt[n-1],wt,val)),knapsack(n-1,W,wt,val));
			return arr[n][W];
		}else{
			arr[n][W] = knapsack(n-1,W,wt,val);
			return arr[n][W];
		}
	}
}

int main(){
	int wt[5] = {3,2,3,4,5};
	int val[5] = {15,20,7,9,15};
	int W = 10;
	int n = 5;
//	int arr[n+1][W+1];
	for(int i=0;i<n+1;i++){
		for(int j=0;j<W+1;j++){
			arr[i][j] = -1;
		}
	}
	knapsack(n,W,wt,val);
	
	
	for(int i=0;i<n+1;i++){
		for(int j=0;j<W+1;j++){
			printf("%d  ",arr[i][j]);
		}
		printf("\n");
	}
	
}
