#include<stdio.h>

// DFS - Depth First Search

void dfs(int map[][7],int *visited,int node,int len){
	if(visited[node]==0){
		visited[node] = 1;
		printf("%d\n",node);
		for(int i=0;i<len;i++){
			if(map[node][i]==1 && visited[i]==0){
				dfs(map,visited,i,len);
			}
		}
	}
}

int main(){
	
//	int map[][5] = { 
//		{0,0,1,0,0},
//		{0,0,1,0,1},
//		{1,1,0,1,0},
//		{0,0,1,0,1},
//		{0,1,0,1,0},
//	};
//	int n = 5;
//	int visited[] = {0,0,0,0,0};
	int map[][7] = { 
		{0,1,1,0,0,0,0},
		{1,0,0,1,1,0,0},
		{1,0,0,0,0,1,1},
		{0,1,0,0,0,0,0},
		{0,1,0,0,0,0,0},
		{0,0,1,0,0,0,0},
		{0,0,1,0,0,0,0},
	};
	int n = 7;
	int visited[] = {0,0,0,0,0,0,0};
	dfs(map,visited,0,n);
}
