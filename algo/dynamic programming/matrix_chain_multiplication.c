#include<stdio.h>
#include<limits.h>

int MCM(int arr[],int i,int j){
    if(i==j){
        return 0;
    }
    int min = INT_MAX,temp,k;
    for ( k = i; k < j; k++)
    {
        temp = MCM(arr,i,k)+MCM(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        if(temp<min){
            min = temp;
        }
    }
    return min;
    
}

int main(){
    int n,v;
    printf("No.of matrices: ");
    scanf("%d",&n);
    int arr[n+1];
    for (int i = 0; i <=n; i++)
    {
        printf(": ");
        scanf("%d",&v);
        arr[i] = v;
    }
    printf("\n\n");
    // i = 1
    // j = N
    int res = MCM(arr,1,n);
   
    
    printf("Min: %d",res);
    
}

// 40 20 30 10 30 = 26000
// 10 20 30 40 30 = 30000
// 10 20 30 = 6000
