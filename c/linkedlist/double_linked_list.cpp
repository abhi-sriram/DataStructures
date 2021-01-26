#include <stdio.h>
#include <stdlib.h>

struct doubleLink{
	struct doubleLink *prev;
	int ele;
	struct doubleLink *next;
};



int length(struct doubleLink * head){
	int length = 0;
	if(head==NULL){
		return length;
	}
	else{
		while(head!=NULL){
			length++;
			head = head->next;
		}
		return length;
	}
}

struct doubleLink * insertAtBegining(struct doubleLink * head){
	int e;
	printf("Enter element: ");
	scanf("%d",&e);
	if(head==NULL){
		head = (struct doubleLink *)malloc(sizeof(struct doubleLink));
		head->prev = NULL;
		head->ele = e;
		head->next = NULL;
	}
	else{
		struct doubleLink * temp;
		temp = (struct doubleLink *)malloc(sizeof(struct doubleLink));
		temp->prev = NULL;
		temp->ele = e;
		head->prev = temp;
		temp->next = head;
		head = temp;
	}
	return head;
}

struct doubleLink * insertAtEnd(struct doubleLink * head){
	struct doubleLink * temp,* temp1;
	int e;
	printf("Enter element: ");
	scanf("%d",&e);
	
	temp = head;
	temp1 = (struct doubleLink *)malloc(sizeof(struct doubleLink));
	
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp1->ele = e;
	temp1->next = NULL;
	temp1->prev = temp;
	temp->next = temp1;
	return head;
}

struct doubleLink * insertAtPosition(struct doubleLink * head){
	int pos,len;
	printf("Enter position to enter element: ");
	scanf("%d",&pos);
	len = length(head);
	if(pos>len){
		printf("Position out of range\n");
		return head;
	}
	else if(pos==1){
		head = insertAtBegining(head);
		return head;
	}else if(pos==len){
		head = insertAtEnd(head);
		return head;
	}else{
		struct doubleLink * temp,* temp1;
		temp = head;
		temp1 = (struct doubleLink *)malloc(sizeof(struct doubleLink));
		while(pos>1){
			temp = temp->next;
			pos--;
		}
		int e;
		printf("Enter element: ");
		scanf("%d",&e);
		temp1->ele = e;
		temp->prev->next = temp1;
		temp1->prev = temp->prev;
		temp1->next = temp;
		temp->prev = temp1;
		return head;
	}
}

struct doubleLink * removeAtFirst(struct doubleLink * head){
	if(head==NULL){
		printf("List is empty\n");
		return head;
	}else{
		if(head->next==NULL){
			head = NULL;
			return head;
		}
		head = head->next;
		head->prev = NULL;
//		head->prev->next = NULL;
		return head;
	}
}

struct doubleLink * removeAtLast(struct doubleLink * head){
	struct doubleLink * temp;
	if(head==NULL){
		printf("List is empty\n");
	}else{
		temp = head;
		if(head->next==NULL){
			head = NULL;
			return head;
		}
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->prev->next = NULL;
		return head;
	}
}

struct doubleLink * removeByElement(struct doubleLink * head){
	int ele,index = 1,len;
	printf("Enter element to remove: ");
	scanf("%d",&ele);
	struct doubleLink * temp;
	temp = head;
	len = length(head);
	while(temp->ele!=ele){
		temp = temp->next;
		index++;
	}
	if(index==1){
		head = removeAtFirst(head);
		return head;
	}
	else if(index==len){
		head = removeAtLast(head);
		return head;
	}
	if(temp->ele==ele){
		struct doubleLink * temp1;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		return head;
	}else{
		printf("Element not found\n");
		return head;
	}
	
}

void print(struct doubleLink * head){
	if(head==NULL){
		printf("Empty list\n");
	}else{
		printf("- - - - - - - -\n");
		while(head!=NULL){
			printf("%d\n",head->ele);
			head = head->next;
		}
		printf("- - - - - - - -\n");
	}
	
}

int main(){
	struct doubleLink * head = NULL;
	int ch,len;
	do{
		printf("- - - - - - - -\n");
		printf("Menu\n");
		printf("1. Insert at begin\n");
		printf("2. Insert at end\n");
		printf("3. Insert at position\n");
		printf("4. Remove at first\n");
		printf("5. Remove at last\n");
		printf("6. Remove an element\n");
		printf("7. Length\n");
		printf("8. Print\n");
		scanf("%d",&ch);
		printf("- - - - - - - -\n");
		switch(ch){
			case 1:
				head = insertAtBegining(head);
				break;
			case 2:
				head = insertAtEnd(head);
				break;
			case 3:
				head = insertAtPosition(head);
				break;
			case 4:
				head = removeAtFirst(head);
				break;
			case 5:
				head = removeAtLast(head);
				break;
			case 6:
				head = removeByElement(head);
				break;
			case 7:
				len = length(head);
				printf("Length: %d\n",len);
				break;
			case 8:
				print(head);
				break;
			default:
				printf("Incorrect input\n");
				break;
		}
	}while(ch!=0);
	
	
}
