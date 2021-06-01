#include<stdio.h>

//Using Memorization and Recursive = Dynamic Programming technique



int fib(int n,int *arr){
	if(n==1 || n==0){
		arr[n] = n;
		return n;
	}
	else{
		if(arr[n]==-1){
			arr[n] = fib(n-2,arr)+fib(n-1,arr);
			return arr[n];
		}
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
