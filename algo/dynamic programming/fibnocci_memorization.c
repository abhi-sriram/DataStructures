#include<stdio.h>


int fib(int n,int mem[]){

    if(mem[n]!=-1){
        return mem[n];
    }
    mem[n] = fib(n-1,mem)+fib(n-2,mem);
    return mem[n];
}

int main(){
    int n;
    printf(": ");
    scanf("%d",&n);
    int mem[n];
    for (int i = 0; i < n; i++)
    {
        mem[i] = -1;
    }
    mem[0] = 0;
    mem[1] = 1;
    int m = fib(n-1,mem);
    printf("%d\n",m);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",mem[i]);
    }
    

}
