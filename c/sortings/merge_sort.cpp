#include<stdio.h>

void print_arr(int *arr,int size){
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void merging(int *arr,int start,int mid,int end){
	if(end>start){
		int size = end-start;
		
		int temp[size],k=0,i = start,j=mid+1;
		
	//	for(int n=0;n<size;n++){
	//		if(arr[i]<arr[j] && i<=mid){
	//			temp[k] = arr[i];
	//			k++;			
	//			i++;
	//		}
	//		else{
	//			temp[k] = arr[j];
	//			k++;
	//			j++;
	//		}
	//	}
		
		while(i<=mid && j<=end){
			if(arr[i]<arr[j]){
				temp[k] = arr[i];
				k++;			
				i++;
			}else{
				temp[k] = arr[j];
				k++;
				j++;
			}
		}
		while(i<=mid){
			temp[k] = arr[i];
			i++;
			k++;
		}
		while(j<=end){
			temp[k] = arr[j];
			j++;
			k++;
		}
		for(int l=0;l<k;l++){
			arr[start+l] = temp[l];
		}
	}
	
	
		
}

void merge(int *arr,int start,int end){
	if(end>start){
		int mid = (end+start)/2;
		merge(arr,start,mid);
		merge(arr,mid+1,end);
		merging(arr,start,mid,end);
	}
}

int main(){
	int arr []={5,9,0,1,3,2,6}; 
	int size = sizeof(arr)/sizeof(arr[0]);
	merge(arr,0,size-1);
	print_arr(arr,size);
	return 0;
}
