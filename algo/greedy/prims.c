#include<stdio.h>
#include<math.h>

int checkKeys(int keys[],int check,int n){
    for (int i = 0; i <=n; i++)
    {
        if(keys[i]==check){
            return 1;
        }
    }
    return 0;
    
}
int sum = 0;
void prims(int v,int graph[v][v],int keys[]){
    int count = 0;
    while (count!=v-1)
    {
        int min = 999999;
        int v1,v2;
        for (int i = 0; i <= count; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if(graph[keys[i]][j]!=-1 && graph[keys[i]][j]!=0 && keys[i]!=j && !checkKeys(keys,j,count) && graph[keys[i]][j]<min){
                    min = graph[keys[i]][j];
                    v1 = keys[i];
                    v2 = j;
                }
            }
        }
        count++;
        if(!checkKeys(keys,v1,count)){
            keys[count] = v1;
        }else{
            keys[count] = v2;
        }
        printf("%d %d: %d\n",v1,v2,graph[v1][v2]);
        sum+=graph[v1][v2];
        graph[v1][v2] = -1;
        graph[v2][v1] = -1;
    }
    
    
}

int main(){

    int V, E=0;
    printf("V: ");
    scanf("%d", &V);
    int w;
    int graph[V][V];
    int keys[V];
    for (int i = 0; i < V; i++)
    {
        keys[i] = -1;
        for (int j = i; j < V; j++)
        {
            
            if (i != j)
            {
                printf("%d %d: ", i, j);
                scanf("%d", &w);
                graph[i][j] = w;
                graph[j][i] = w;
                E++;
            }
            else
            {
                graph[i][j] = 0;
                graph[j][i] = 0;
            }
        }
    }
    printf("\n\n");
    keys[0] = 0;
    prims(V,graph,keys);
    // krushkal(V, graph,E);
    // printf("\n\n");
    printf("MIN SUM: %d\n\n",sum);
    // for (int i = 0; i < V; i++)
    // {
    //     printf("%d ",keys[i]);
    // }
    
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            // if(graph[i][j]==-1){
            //     printf("( %d, %d)\n",i,j);
            // }
            printf("%d\t",graph[i][j]);
        }
        printf("\n");
    }
}
