#include<stdio.h>

int main(){
    int n;
    printf(": ");
    scanf("%d",&n);
    int table[n];
    table[0] = 0;
    table[1] = 1;
    for (int i = 2; i < n; i++)
    {
        table[i] = table[i-1]+table[i-2];
    }

    for (int i = 0; i <n; i++)
    {
        printf("%d ",table[i]);
    }
    
    
    
}
