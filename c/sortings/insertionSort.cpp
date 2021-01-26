#include<stdio.h>

// Insertion sort

void swap(int *arr,int a,int b){
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void print_arr(int *arr,int len){
	for(int i=0;i<len;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void insertionSort(int *arr,int len){
	for(int i=0;i<len-1;i++){
		for(int j=i+1;j>0;j--){
			if(arr[j]<arr[j-1]){
				swap(arr,j,j-1);
			}
		}
	}
}

int main(){
	int arr[] = {9,8,7,6,5,4,3,2,1,0};
	int len = sizeof(arr)/sizeof(arr[0]);
	
	insertionSort(arr,len);
	
	print_arr(arr,len);
}
