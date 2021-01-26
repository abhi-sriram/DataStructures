#include <stdio.h>

struct Stack{
	char arr[50];
	int top;
	int max;
};

struct Stack push(struct Stack s,char c){
	if(s.top==s.max-1){
		printf("\nstack is full");
	}else{
		s.top++;
		s.arr[s.top] = c;
	}
	
	return s;
}

struct Stack pop(struct Stack s){
	if(s.top==-1){
		printf("\nstack is empty");
	}
	else if(s.arr[s.top]=='('){
		s.top--;
	}
	else{
		printf("%c ",s.arr[s.top]);
		s.top--;
	}
	return s;
}

char top(struct Stack s){
	return s.arr[s.top];
}



int priority(char c){
	if(c=='('){
		return 0;
	}
	else if(c=='+' || c=='-'){
		return 1;
	}
	else if(c=='*' || c=='/'){
		return 2;
	}
	else{
		return 3;
	}
}

int main(){
	char exp[20];
	char *e = exp;
	struct Stack s;
	s.max = 50;
	s.top = -1;
	
	scanf("%s",exp);

	while(*e != '\0'){
		if(*e == '('){
			s = push(s,*e);
		}
		else if(*e=='+' || *e=='-'){
			
				while(s.top>-1 && priority(top(s))>=priority(*e)){
					
					s = pop(s);	
				}	
			
			
			s = push(s,*e);
		}
		else if(*e=='*' || *e=='/'){
		
				while(s.top>-1 && priority(top(s))>=priority(*e)){
					s = pop(s);
			
			}
			
			s = push(s,*e);
		}
		else if(*e==')'){
			while(s.arr[s.top]!='('){
				
				s = pop(s);
			}
			s = pop(s);
			
		}
		else{
			
			printf("%c ",*e);
		}
		e++;
	}
	
	while(s.top!=-1){
		s = pop(s);
	}
	
}
