#include<stdio.h>
#include<stdlib.h>

struct Stack{
	int arr[20];
	int max;
	int top;
};

int main(){
//	stack with pointers
	struct Stack *s;
	s = (struct Stack *)malloc(sizeof(struct Stack));
	s->top = -1;
	printf("Enter max elements <= 20 ");
	scanf("%d",&s->max);
	
	int op,elem;
	do{
		printf("1.push 2.pop 3.exit\n");
		scanf("%d",&op);
		switch(op){
			case 1:
				if(s->top==s->max-1){
					printf("Stack is full\n");
				}else{
					printf("Enter element");
					scanf("%d",&elem);
					s->top++;
					s->arr[s->top] = elem;
				}
				break;
			case 2:
				if(s->top==-1){
					printf("Stack is empty\n");
				}else{
					printf("%d\n",s->arr[s->top]);
					s->top--;
				}
				break;
			case 3:
				break;
			default:
				printf("Enter valid input\n");
		}
	}while(op!=3);
}
