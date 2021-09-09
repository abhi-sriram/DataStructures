#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Stack{
    char arr[100];
    int top;

};
// priority number starts from 0 and increase as priority
int priority(char c){
    if(c=='+' || c=='-'){
        return 0;
    }
    else if(c=='*' || c=='/'){
        return 1;
    }else if(c=='('){
        return 2;
    }else{
        // c==')'
        return 3;
    }
}
void pop(struct Stack *s){
    if(s->arr[s->top]!='(' && s->arr[s->top]!=')'){
        printf("%c",s->arr[s->top]);
    }
    s->top--;
}
void insert(struct Stack *s,char c){
    if(s->top==-1){
        s->top++;
        s->arr[s->top] = c;
    }
    else{
        char sChar = s->arr[s->top];
        
        int p1 = priority(sChar);
        int p2 = priority(c);
        if(p2==3){
            // closing parenthisis, pop all until ( paranthisis
            while(s->top>-1 && priority(s->arr[s->top])!=2){
                pop(s);
            }
            pop(s);
        }else if(p2==2 || p2>p1 || p1==2){
            s->top++;
            s->arr[s->top] = c;
        }
        else if(p2==p1){
            while (s->top>-1 && p2==priority(s->arr[s->top]))
            {
                pop(s);
            }
            
            s->top++;
            s->arr[s->top] = c;
        }
        else{
            // p2<p1 case
            while (s->top>-1 && (p2<priority(s->arr[s->top]) || p2==priority(s->arr[s->top])))
            {
                pop(s);
            }
            s->top++;
            s->arr[s->top] = c;
        }
    }
}

void main(){
    struct Stack *s;
    s = (struct Stack *)malloc(sizeof(struct Stack));
    s->top=-1;
    char string[] = "a/b-c+d*e-a*c";
    int len = strlen(string);
    if(len>200){
        printf("\nWe are not dealing with larger size infix strings.");
        return;
    }
    for (int i = 0; i < len; i++)
    {
        if(string[i]=='(' || string[i]==')' || string[i]=='+' || string[i]=='-' || string[i]=='*' || string[i]=='/'){
            insert(s,string[i]);
        }else{
            printf("%c",string[i]);
        }
    }
    while (s->top>-1)
    {
        printf("%c",s->arr[s->top]);
        s->top--;
    }
}
