#include<stdio.h>

// Selection sort

void swap(int *arr,int a,int b){
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}


void selectionSort(int *arr,int len){
	for(int i=0;i<len;i++){
		int min = arr[i],loc = i;
		for(int j=i+1;j<len;j++){
			if(arr[j]<min){
				loc = j;
				min = arr[j];
			}
		}
		
		swap(arr,i,loc);
	}
}

int main(){
	int arr[] = {4,3,1,5,6,7,2,11,9};
	int len = sizeof(arr)/sizeof(arr[0]);
	
	selectionSort(arr,len);
	
	for(int i=0;i<len;i++){
		printf("%d\n",arr[i]);
	}
}
