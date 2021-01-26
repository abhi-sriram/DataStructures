#include <stdio.h>
#include <stdlib.h>

struct doubleLink{
	struct doubleLink ** prev;
	int ele;
	struct doubleLink ** next;
};

void insertAtBegining(struct doubleLink ** head){
	int e;
	printf("Enter element: ");
	scanf("%d",&e);
	if(head==NULL){
		**head = (struct doubleLink *)malloc(sizeof(struct doubleLink));
		*head->prev = NULL;
		*head->ele = e;
		*head->next = NULL;
	}else{
		struct doubleLink * temp;
		temp = (struct doubleLink *)malloc(sizeof(struct doubleLink));
		temp->ele = e;
		temp->prev = NULL;
		temp->next = *head;
		
	}
}

void print(struct doubleLink ** head){
	if(head==NULL){
		printf("Empty list\n");
		
	}else{
		while(*head!=NULL){
			printf("%d\n",*head->ele);
			*head = *head->next;
		}
	}
}

int main(){
	struct doubleLink ** head = NULL;
	int ch;
	
	do{
		printf("- - - - - - - -\n");
		printf("Menu\n");
		printf("1. Insert at begin\n");
		printf("2. Print\n");
		
		scanf("%d",&ch);
		printf("- - - - - - - -\n");
		switch(ch){
			case 1:
				insertAtBegining(head);
				break;
			case 2:
				print(head);
				break;
			default:
				printf("Incorrect input\n");
				break;
		}
	}while(ch!=0);
}
