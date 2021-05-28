
#include<stdio.h>
#include<math.h>

int main(){
	int power_set_len;
	int sack_weights[] = {10,20,30};
	int weights_values[] = {62,100,120};
	power_set_len = pow(2,3);
	int total_weight=0,total_value=0;
	int sack_weight = 50;
	for(int counter=0;counter<power_set_len;counter++){
		int tw=0,tv=0;
		for(int j=0;j<3;j++){
			if((counter&(1<<j)) > 0){
				tw+=sack_weights[j];
				tv+=weights_values[j];
			}
		}
		if(tw<=sack_weight){
			if(tv>total_value){
				total_value = tv;
				total_weight = tw;
			}
		}
	}
	printf("Total weight %d\n",total_weight);
	printf("Total Value %d",total_value);
}
