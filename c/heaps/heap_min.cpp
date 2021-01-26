#include<stdio.h>

// Heapmin

void swap(int *arr,int i,int j){
	int t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

void heapify(int *arr,int index,int n){
	int r = 2*index+2;
	int l = 2*index+1;
	int min = -1;
	if(r<n){
		if(arr[r]<arr[l]){
			min = r;
		}else{
			min = l;
		}
	}else if(l<n){
		min = l;
	}
	if(min!=-1 && arr[min]<arr[index]){
		swap(arr,min,index);
		heapify(arr,min,n);
	}
}

int main(){
	int arr[] = {78,66,35,29,33,21,9,12,5,10};
	int n = sizeof(arr)/sizeof(arr[0]);
	for(int i=(n/2);i>=0;i--){
		heapify(arr,i,n);
	}
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
