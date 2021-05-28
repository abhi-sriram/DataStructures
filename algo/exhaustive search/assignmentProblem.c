
#include <stdio.h>

int job_cost[][4] = {
	{
//		job0,job1,job2,job3 each job cost for 1st person
		5,2,4,8
	},
	{
//		each job cost for 2nd person
		6,5,3,5
	},
	{
		5,8,1,8
	},
	{
		3,3,9,7
	}
};
int order[] = {0,0,0,0};
int min_cost_to_complete_all_jobs = 9999999;

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void permute(int *arr,int l,int r){
	if(l==r){
		int total_cost = 0;
		for(int i=0;i<=r;i++){
//			printf("%d",arr[i]);
			total_cost += job_cost[i][arr[i]];
		}
		if(min_cost_to_complete_all_jobs>total_cost){
			
			for(int i=0;i<=r;i++){
				order[i] = arr[i];
			}
			min_cost_to_complete_all_jobs = total_cost;
		}
//		printf("\n");
	}else{
		for(int i=l;i<=r;i++){
			swap((arr+l),(arr+i));
			permute(arr,l+1,r);
			swap((arr+l),(arr+i));
		}
	}
}

int main(){
	int arr[] = {0,1,2,3};
	permute(arr,0,3);
	printf("Order of jobs so that cost is minimised is: ");
	for(int i=0;i<=3;i++){
		printf("%d ",order[i]);
	}
	printf("\n");
	printf("Cost of jobs is : %d",min_cost_to_complete_all_jobs);
}
