#include<stdio.h>

// Heapmax

void swap(int *arr,int i,int j){
	int t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

void heapify(int *arr,int index,int n){
	int r = 2*index+2;
	int l = 2*index+1;
	int max = -1;
	if(r<n){
		if(arr[r]>arr[l]){
			max = r;
		}else{
			max = l;
		}
	}else if(l<n){
		max = l;
	}
	if(max!=-1 && arr[max]>arr[index]){
		swap(arr,max,index);
		heapify(arr,max,n);
	}
}

int main(){
	int arr[] = {5 ,10 ,9 ,12 ,33 ,21 ,35 ,66 ,29 ,78};
	int n = sizeof(arr)/sizeof(arr[0]);
	for(int i=(n/2);i>=0;i--){
		heapify(arr,i,n);
	}
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
