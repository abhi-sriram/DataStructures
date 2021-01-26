#include<stdio.h>
#include<stdlib.h>

struct Stack{
	int arr[20];
	int max;
	int top;
};

void push(struct Stack *s){
	if(s->top==s->max-1){
		printf("Stack is full\n");
	}else{
		int elem;
		printf("Enter element");
		scanf("%d",&elem);
		s->top++;
		s->arr[s->top] = elem;
	}
}
void pop(struct Stack *s){
	if(s->top==-1){
		printf("Stack is empty\n");
	}else{
		printf("%d\n",s->arr[s->top]);
		s->top--;
	}
}

int main(){
//	stack with pointers using functions
	struct Stack *s;
	s = (struct Stack *)malloc(sizeof(struct Stack));
	s->top = -1;
	printf("Enter max elements <= 20 ");
	scanf("%d",&s->max);
	
	int op;
	do{
		printf("1.push 2.pop 3.exit\n");
		scanf("%d",&op);
		switch(op){
			case 1:
				push(s);
				
				break;
			case 2:
				pop(s);
				
				break;
			case 3:
				break;
			default:
				printf("Enter valid input\n");
		}
	}while(op!=3);
}
