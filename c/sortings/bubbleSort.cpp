#include<stdio.h>

// Bubble sort

void swap(int *arr,int a,int b){
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void bubbleSort(int *arr,int len){
	
	for(int i=0;i<len;i++){
		for(int j=0;j<len-1-i;j++){
			if(arr[j]>arr[j+1]){
				swap(arr,j,j+1);
			}
		}
	}
		
}

int main(){
	
	int arr[] = {4,3,1,5,6,7,2,11,9};
	int len = sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr,len);
	for(int i=0;i<len;i++){
		printf("%d\n",arr[i]);
	}
	
	
	return 0;
}
