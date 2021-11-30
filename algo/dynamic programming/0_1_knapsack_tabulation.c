#include<stdio.h>

int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

int main(){
    int w[] = {0,3,3,4,5};
    int v[] = {0,30,50,40,10};
    int n = 4;
    int totalWeight = 10;
    int table[n+1][totalWeight+1];

    int i,j;

    for(i=0;i<=n;i++){
        for(j=0;j<=totalWeight;j++){

        table[i][j] = 0;
        }
    }

    

    for(i=1;i<=n;i++){
        for(j=1;j<=totalWeight;j++){
            if(j-w[i]>=0)
            table[i][j] = max(table[i-1][j],(table[i-1][j-w[i]]+v[i]));
        }
    }
    for(i=0;i<=n;i++){
        for(j=0;j<=totalWeight;j++){
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }

}
