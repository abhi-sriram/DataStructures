#include <stdio.h>
#include<limits.h>


int main()
{
    int mergeArr[] = {2,3,4,5,6,7};
    int n = sizeof(mergeArr)/sizeof(int);
    int sum = 0;
    int k;
    for (k = 0; k <n-1; k++)
    {
        int val = 0;
        int min1=INT_MAX,min2=INT_MAX,min1_index=-1,min2_index=-1,i,j;
        for (i = 0; i < n; i++)
        {
            if(mergeArr[i] != -1 && mergeArr[i]<min1){
                if(min1!=INT_MAX){
                    min2 = min1;
                    min2_index = min1_index;
                }
                min1 = mergeArr[i];
                min1_index = i;
                continue;
            }
            if(mergeArr[i]!=-1 && mergeArr[i]<min2 && i!=min1_index){
                min2 = mergeArr[i];
                min2_index = i;
            }
        }
        val = (mergeArr[min1_index]+mergeArr[min2_index]);
        mergeArr[min1_index] = -1;
        mergeArr[min2_index] = val;
        sum+=val;
    }
    
    printf("\nSUM: %d",sum);
    
}


        
