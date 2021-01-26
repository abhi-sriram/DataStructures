#include <stdio.h>
#include <stdlib.h>

// BFF - Breadth First Search
// Queue implementation

struct queue{
	int arr[10];
	int r;
	int f;
};

void enqueue(struct queue * q,int num){

		q->arr[q->r] = num;
		q->r++;
	
}
int dequeue(struct queue * q){
	int temp;
	if(q->r==q->f){
		printf("Queue is empty.\n");
	}else{
		temp = q->arr[q->f];
		for(int i=0;i<q->r-1;i++){
			q->arr[i] = q->arr[i+1];
		}
		q->r--;
	}
	return temp;
}

void print_q(struct queue * q){
	printf("queue: ");
	for(int i=0;i<q->r;i++){
		printf("%d ",q->arr[i]);
	}
	printf("\n");
}

bool isEmpty(struct queue * q){
	if(q->f==q->r){
		return true;
	}
	return false;
}

int main(){
	struct queue * q;
	q = (struct queue *)malloc(sizeof(struct queue));
	q->r = 0;
	q->f = 0;
//	int map[][5] = { 
//		{0,0,1,0,0},
//		{0,0,1,0,1},
//		{1,1,0,1,0},
//		{0,0,1,0,1},
//		{0,1,0,1,0},
//	};
//	int n = 5;
//	int visited[] = {0,0,0,0,0};
//int map[][7] = { 
//		{0,1,1,0,0,0,0},
//		{1,0,0,1,1,0,0},
//		{1,0,0,0,0,1,1},
//		{0,1,0,0,0,0,0},
//		{0,1,0,0,0,0,0},
//		{0,0,1,0,0,0,0},
//		{0,0,1,0,0,0,0},
//	};
int map[][6] = {{0,1,1,0,0,1},{1,0,0,1,1,0},{1,0,0,0,1,0},{0,1,0,0,0,1},{0,1,1,0,0,1},{1,0,0,1,1,0}};
	int n = 6;
	int visited[] = {0,0,0,0,0};
	enqueue(q,0);
	while(!isEmpty(q)){
//		print_q(q);
		int v = dequeue(q);
		
		if(visited[v]==0){
			printf("%d\n",v);
			visited[v] = 1;
			for(int j=0;j<n;j++){
				if(map[v][j]==1 && visited[j]==0){
					enqueue(q,j);
				}
			}	
		}
		
	}
	
}
