#include <stdio.h>

//Fibnocii Dynamic programming using Tabulation technique

void fib(int n,int *arr){
	if(n<0){
		return;
	}
	
	arr[0] = 0;
	arr[1] = 1;
	for(int i=2;i<=n;i++){
		arr[i] = arr[i-2]+arr[i-1];
	}
	
}

int main(){
	int arr[10];
	for(int i=0;i<10;i++){
		arr[i] = -1;
	}
	fib(9,arr);
	printf("%d\n",arr[9]);
	for(int i=0;i<10;i++){
		printf("%d ",arr[i]);
	}
}
