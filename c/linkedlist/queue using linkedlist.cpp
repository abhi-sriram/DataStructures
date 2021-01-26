//implementation of queue using linkedlist
#include <stdio.h>
#include <stdlib.h>

struct link{
	int ele;
	struct link * next;
};

struct link * insert(struct link * head){
	int num;
	printf("Enter number: ");
	scanf("%d",&num);
	if(head==NULL){
		head = (struct link *)malloc(sizeof(struct link));
		head->ele = num;
		head->next = NULL;
		return head;
	}
	struct link * temp= head,* temp1;
	temp1 = (struct link *)malloc(sizeof(struct link));
	temp1->ele = num;
	temp1->next = NULL;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = temp1;
	return head;
}

struct link * deleteQ(struct link * head){
	if(head==NULL){
		printf("Empty queue\n");
		return head;
	}else if(head->next==NULL){
		printf("%d is deleted from queue\n",head->ele);
		return NULL;
	}else{
		
		printf("%d is deleted from queue\n",head->ele);
		head = head->next;
		return head;
	}
}

void print(struct link * head){
	if(head==NULL){
		printf("Empty queue\n");
	}else{
		while(head!=NULL){
			printf("%d\n",head->ele);
			head = head->next;
		}
	}
}

int main(){
	struct link * head = NULL;
	int op;
	do{
		printf("1. Insert\n2. Delete\n3. Print\n0. Exit\n");
		scanf("%d",&op);
		switch(op){
			case 1:
				head = insert(head);
				break;
			case 2:
				head = deleteQ(head);
				break;
			case 3:
				 print(head);
				break;
			case 0:
				break;
			default:
				printf("Invalid input\n");
		}
	}while(op!=0);
}
