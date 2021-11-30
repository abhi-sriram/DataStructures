#include <stdio.h>


int visited[100];

void setVisited(int v){
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }

}

int checkCycle(int v,int arr[v][v],int v1,int v2,int check){

    for (int i = 0; i < v && !check; i++)
    {
        if(!visited[i] && arr[v1][i]==-1){
            visited[i] = 1;
            if(i==v2){
                check = 1;
                return check;
            }else{
                check = checkCycle(v,arr,i,v2,check);
            }
        }

    }
    return check;

}

int sum=0;
int exclude[100][2];

int isExcluded(int v1,int v2,int n){
    for (int i = 0; i < n; i++)
    {
        if((exclude[i][0]==v1 && exclude[i][1]==v2) || (exclude[i][0]==v2 && exclude[i][1]==v1)){
            return 1;
        }
    }
    return 0;
}

void krushkal(int v, int graph[v][v],int edges)
{
    int count = 0;
    int k = 0;
    for (int k = 0; k < edges && count!=v-1; k++)
    {
        int v1 = -1, v2 = -1;
        int minWeight = 9999999;
        // printf("\n\t%d\n",k);
        for (int i = 0; i < v; i++)
        {
            for (int j = i+1; j < v; j++)
            {
                if (graph[i][j] != -1 && graph[i][j] != 0 && graph[i][j] < minWeight && !isExcluded(i,j,k))
                {
                    v1 = i;
                    v2 = j;
                    minWeight = graph[i][j];
                }
            }
        }
        setVisited(v);
        
        if (!checkCycle(v,graph,v1,v2,0) ){
            sum+= graph[v1][v2];
            graph[v1][v2] = -1;
            graph[v2][v1] = -1;
            printf("%d %d\n",v1,v2);
            count++;
            
        }else{
            exclude[k][0] = v1;
            exclude[k][1] = v2;
            k++;
            printf("ELSE: %d %d\n",v1,v2);
        }
    }
}

int main()
{
    int V, E=0;
    printf("V: ");
    scanf("%d", &V);
    // printf("E: ");
    // scanf("%d",&E);
    int v1, v2, w;
    int graph[V][V];
    for (int i = 0; i < V; i++)
    {
        for (int j = i; j < V; j++)
        {
            if (i != j)
            {
                printf("%d %d: ", i, j);
                scanf("%d", &w);
                graph[i][j] = w;
                graph[j][i] = w;
                if(w!=0){
                    E++;
                }
            }
            else
            {
                graph[i][j] = 0;
                graph[j][i] = 0;
            }
        }
    }
    printf("EDGES: %d\n\n",E);
    krushkal(V, graph,E);
    printf("\n\n");
    printf("MIN SUM: %d\n",sum);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if(graph[i][j]==-1){
                printf("( %d, %d)\n",i,j);
            }
        }
    }
}
// 5 1 0 2 6 3
// 4 0 0 0 0 0 8 0 8 0 0 0 0 11 0 7 0 4 0 0 2 9 14 0 0 0 10 0 0 0 2 0 0 1 6 7
