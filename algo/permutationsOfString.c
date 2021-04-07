#include<stdio.h>

// Permutations of string

void swap(char *x,char *y){
	char temp = *x;
	*x = *y;
	*y = temp;
}

void permute(char *str,int l,int r){
	if(l==r){
		printf("%s\n",str);
	}else{
		int i;
		for(i=l;i<=r;i++){
			
			swap((str+l),(str+i));
			permute(str,l+1,r);
			swap((str+l),(str+i));
		}
	}
}

int main(){
	char str[] = "ABC";
	permute(str,0,2);
	
}

// Output 

// ABC
// ACB
// BAC
// BCA
// CBA
// CAB
