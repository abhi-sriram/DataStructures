#include<stdio.h>
#include<math.h>

//int max(int n1,int n2){
//	if(n1>n2){
//		return n1;
//	}
//	return n2;
//}

int multiply(int n1,int n2){
	printf("n1 %d---n2 %d\n",n1,n2);
	if(n1<10 || n2<10){
		printf("ans- %d\n",n1*n2);
		return n1*n2;
	}
	int n1_len = log10(n1)+1, n2_len = log10(n2)+1;
	int n = (n1_len>n2_len) ? n1_len : n2_len;
	int nd = n/2;
	printf("n %d --- nd %d\n",n,nd);
	int div = pow(10,nd);
	int a1 = n1/div, a0 = n1%div;
	int b1 = n2/div, b0 = n2%div;
	printf("a1 %d a0 %d ---- b1 %d b0 %d\n",a1,a0,b1,b0);
	int c0 = multiply(a0,b0);
	int c2 = multiply(a1,b1);
	int k1 = a0+a1, k2 = b0+b1;
	int c1 = multiply(k1,k2)-c0-c2;
	printf("c0 %d\n",c0);
	printf("c1 %d\n",c1);
	printf("c2 %d\n",c2);
	int ans;
	if(n%2==1){
		n = n-1;
		 ans = c2*pow(10,n)+c1*pow(10,n/2)+c0;
		printf("%d\n",ans);
	}else{
		 ans = c2*pow(10,n)+c1*pow(10,nd)+c0;
		printf("ans %d\n",ans);
	}
	
	
	return ans;
	
}

int main(){
//	int n = 6;
//	int n1 = 123456789;
//	int nd = n/2;
//	int div = pow(10,nd);
//	int a1 = n1/div,a0=n1%div;
//	printf("%d : %d",a1,a0);
//	int count = log10(n1) + 1;
	int n1 = 123456,n2=78666;
	int n = multiply(n1,n2);
	printf("Mult : %d",n);
}
