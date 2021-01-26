#include <stdio.h>
#include <stdlib.h>

struct CLink{
	struct CLink * prev;
	int ele;
	struct CLink * next;
};

struct CLink * insertAtBegin(struct CLink * head){
	int ele;
	printf("Enter element: ");
	scanf("%d",&ele);
	if(head == NULL){
		head = (struct CLink*)malloc(sizeof(struct CLink));
		head->prev = head;
		head->ele = ele;
		head->next = head;
		return head;
	}else{
		struct CLink * nn,* temp;
		nn = (struct CLink *)malloc(sizeof(struct CLink));
		temp = head;
		while(temp->next!=head){
			temp = temp->next;
		}
		temp->next = nn;
		head->prev = nn;
		nn->ele = ele;
		nn->next = head;
		nn->prev = temp;
		head = nn;
		return head;
		
	}
}

struct CLink * insertAtEnd(struct CLink * head){
	int ele;
	printf("Enter element: ");
	scanf("%d",&ele);
	if(head == NULL){
		head = (struct CLink*)malloc(sizeof(struct CLink));
		head->prev = head;
		head->ele = ele;
		head->next = head;
		return head;
	}else{
		struct CLink * nn,* temp;
		nn = (struct CLink *)malloc(sizeof(struct CLink));
		temp = head;
		while(temp->next!=head){
			temp = temp->next;
		}
		temp->next = nn;
		nn->ele = ele;
		nn->prev = temp;
		nn->next = head;
		head->prev = nn;
		return head;
	}
}

void print(struct CLink * head){
	printf("- - - - - - - -\n");
	struct CLink * temp;
	temp = head;
	if(head==NULL){
		printf("Empty list");
	}else{
		printf("%d\n",temp->ele);
		temp = temp->next;
		while(temp!=head){
			printf("%d\n",temp->ele);
			temp = temp->next;
		}
	}
	printf("\n- - - - - - - -\n");
}


int main(){
	struct CLink * head = NULL;
	int ch;
	do{
		printf("Menu\n1. Insert at begining\n2. Insert at end\n3. Print\n");
		
		scanf("%d",&ch);
		switch(ch){
			case 1:
				head = insertAtBegin(head);
				break;
			case 2:
				head = insertAtEnd(head);
				break;
			case 3:
				print(head);
				break;
		}
	}while(ch!=0);
}
