// quick sort
#include <stdio.h>

void swap(int *arr,int a,int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    
}

void print(int *arr){
    for(int i=0;i<12;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}

void quickSort(int *arr,int start,int end){
//     printf("Start: %d End: %d\n",start,end);
    if(end-start>1){
        int pivot = arr[start];
        int i = start+1, j = end;
        
        
        while(i<j){
            while(arr[i]<pivot && i<=end){
                i++;
            }
            while(arr[j]>pivot && j>=0) {
                j--;
            }
            if(i<j){
            	swap(arr,i,j);
			}
            
        }
        swap(arr,start,j);
        quickSort(arr,start,j-1);
        quickSort(arr,j+1,end);
    }else{
        if(start<end){
        	if(arr[start]>arr[end]){
            swap(arr,start,end);
        }
		}
    }
}



int main() {
    int arr[] = {3,8,9,1,6,2,0,4,7,-2,10,11};
    int start = 0,end = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,start,end-1);
    print(arr);
    
    
    return 0;
}
