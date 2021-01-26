//stack using linked list

#include <stdio.h>
#include <stdlib.h>

struct link{
	int ele;
	struct link * next;
};

struct link * insert(struct link * head){
	int ele;
	printf("Enter number: ");
	scanf("%d",&ele);
	if(head==NULL){
		head = (struct link *)malloc(sizeof(struct link));
		head->ele= ele;
		head->next = NULL;
		return head;
	}
	struct link * temp,*temp1;
	temp = head;
	temp1 = (struct link *)malloc(sizeof(struct link));
	temp1->ele =ele;
	temp1->next = NULL;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = temp1;
	return head;
}
struct link * deleteQ(struct link * head){
	if(head==NULL){
		printf("Stack is empty\n");
		return head;
	}else if(head->next==NULL){
		printf("%d is deleted from stack\n",head->ele);
		return NULL;
	}
	else{
		
		struct link * temp,*temp1;
		temp1 = head;
		while(true){
			if(temp1->next!=NULL){
				temp = temp1;
				temp1 = temp1->next;
			}else{
				break;
			}
		}
		
		printf("%d is deleted from stack\n",temp1->ele);
		temp->next = NULL;
	}
	return head;
}

void print(struct link * head){
	struct link * temp = head;
	if(head==NULL){
		printf("Stack is empty\n");
	}else{
		while(temp!=NULL){
			printf("%d\n",temp->ele);
			temp = temp->next;
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
