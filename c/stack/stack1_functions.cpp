#include <stdio.h>

struct Stack{
	int arr[20];
	int max;
	int top;
};

struct Stack push(struct Stack s){
	if(s.top==s.max-1){
		printf("Stack is full\n");
	}else{
		int elem;
		s.top++;
		printf("Enter element: ");
		scanf("%d",&elem);
		s.arr[s.top]=elem;
	}
	return s;
}

struct Stack pop(struct Stack s){
	if(s.top==-1){
		printf("Stack is empty");
	}else{
		printf("%d\n",s.arr[s.top]);
		s.top--;
	}
	return s;
}

int main(){
//	stack with struct using functions
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
				s = push(s);
				break;
			case 2:
				s = pop(s);
				break;
			case 3:
				break;
			default:
				printf("Enter valid input\n");
		}
	}while(op!=3);
}
