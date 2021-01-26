// Stack program using without functions and without pointers

#include<stdio.h>

struct Stack {
	int arr[20];
	int top;
	int max;
};

int main(){
//	stack with structure
	struct Stack s;
	printf("Enter max elements <= 20 ");
	scanf("%d",&s.max);
	s.top = -1;
	int op,elem;
	do{
		printf("1.push 2.pop 3.exit\n");
		scanf("%d",&op);
		switch(op){
			case 1:
				if(s.top==s.max-1){
					printf("Stack is full\n");
				}else{
					printf("Enter element");
					scanf("%d",&elem);
					s.top++;
					s.arr[s.top] = elem;
				}
				break;
			case 2:
				if(s.top==-1){
					printf("Stack is empty\n");
				}else{
					printf("%d\n",s.arr[s.top]);
					s.top--;
				}
				break;
			case 3:
				break;
			default:
				printf("Enter valid input\n");
		}
	}while(op!=3);
	
}
