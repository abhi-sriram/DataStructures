#include<stdio.h>

// finding if path exists or not in the graph 

void floyd(int n,int path[][n],int i,int j,int k){
    if(k==n){
        // base case
        return;
    }
    path[i][j] = path[i][j] || (path[i][k] && path[k][j]);
    j++;
    if(j==n){   
        j=0;
        i++;
    }
    if(i==n){
        i=0;
        k++;
    }
    floyd(n,path,i,j,k);
}

int main(){
    int n = 4;
    int graph[][4] = {
        {0,1,0,1},
        {0,0,1,0},
        {0,0,0,1},
        {0,0,0,0}
    };

    int path[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            path[i][j] = graph[i][j];
        }
        
    }
    floyd(n,path,0,0,0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t",path[i][j]);
        }
        printf("\n");
    }
    
}
