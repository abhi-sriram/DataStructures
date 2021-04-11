
#include <stdio.h>

struct DistanceBwCities{
	int city1;
	int city2;
	int distance;
};

int *minDistanceCities = NULL;
int minDistanceBwCities = 9999999;
int startLocation = NULL;

void print(int len){
	
	printf("min dist: %d\n",minDistanceBwCities);
	printf("%d ",startLocation);
	int i=0;
	while(i<=len){
		printf("%d ",*(minDistanceCities+i));
		i++;
	}
	printf("%d\n",startLocation);
	
}

int distanceOfTwoCities(int *c1,int *c2,struct DistanceBwCities d[],int count){
	int i;
	for(i=0;i<count;i++){
		if((d[i].city1==*c1 && d[i].city2==*c2) || (d[i].city1==*c2 && d[i].city2==*c1)){
			return d[i].distance;
		}
	}
	return 0;
}

void minDistance(int *cty,struct DistanceBwCities distance[],int len,int count){
	int i=0,totalDis=0;
	totalDis += distanceOfTwoCities(&startLocation,(cty+0),distance,count);
	while(i<=len){
		totalDis += distanceOfTwoCities((cty+i),(cty+i+1),distance,count);
		i++;
	}
	totalDis += distanceOfTwoCities(&startLocation,(cty+len),distance,count);
	if(totalDis<=minDistanceBwCities){
		minDistanceBwCities = totalDis;
		minDistanceCities = cty;
		print(len);
	}
}

void swap(int *c1,int *c2){
	int temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}


void permute(int *cty,int l,int r,struct DistanceBwCities distance[],int count){
	if(l==r){
		minDistance(cty,distance,r,count);
	}else{
		int i;
		for(i=l;i<=r;i++){
			swap((cty+l),(cty+i));
			permute(cty,l+1,r,distance,count);
			swap((cty+l),(cty+i));
		}
	}

}

int main(){
	int nCities;
	printf("Number of cities: ");
	scanf("%d",&nCities); // total number of cities
	
	
	// taking distances between cities
	int i,j,k=0,count = ((nCities-1)*nCities)/2;
	struct DistanceBwCities cities[count];
	for(i=0;i<nCities-1;i++){ 
		for(j=i+1;j<nCities;j++){
			printf("Distance between city %d and city %d :",i+1,j+1);
			cities[k].city1 = i+1;
			cities[k].city2 = j+1;
			scanf("%d",&cities[k].distance);
			k++;
		}
	}
	
	
	// From which city salesman starts his journey
	int startingCity;
	printf("Enter your starting city number: ");
	scanf("%d",&startingCity);
	startLocation = startingCity;
	
	int cty[nCities-1];
	k=0;
	for(i=0;i<nCities;i++){
		if(startingCity==i+1){  // to permute without salesman starting city
			
			continue;
		}
		cty[k]=i+1;
		k++;
	}

	permute(cty,0,nCities-2,cities,count);
}
