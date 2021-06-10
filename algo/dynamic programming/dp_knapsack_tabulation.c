#include <stdio.h>

// knapsack using dp-tabulation method

int max(int a,int b){
	return a>b?a:b;
}

int main(){
	int wt[5] = {3,2,3,4,5};
	int val[5] = {15,20,7,9,15};
	int W = 10;
	int n = 5;
	
	int arr[n+1][W+1];
	for(int i=0;i<n+1;i++){
		for(int j=0;j<W+1;j++){
			if(i==0){
				arr[i][j] = 0;
			}
			else if(j==0){
				arr[i][j] = 0;
			}
			else{
				arr[i][j] = -1;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=W;j++){
			if(wt[i-1]<=j){
				arr[i][j] = max((val[i-1]+arr[i-1][j-wt[i-1]]),arr[i-1][j]);
			}else{
				arr[i][j] = arr[i-1][j];
			}
		}
	}
	
	
	for(int i=0;i<n+1;i++){
		for(int j=0;j<W+1;j++){
			printf("%d  ",arr[i][j]);
		}
		printf("\n");
	}
	
}
