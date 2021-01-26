#include <stdio.h>
#include <stdlib.h>

// working with linkedlist using functions 

struct Link{
	int ele;
	struct Link *next;
};

struct Link * addAtBegin(struct Link * head){
	int element;
	struct Link * temp;
	printf("Enter element: ");
	scanf("%d",&element);
	if(head == NULL){
		head = (struct Link *)malloc(sizeof(struct Link));
		head->ele = element;
		head->next = NULL;
	}else{
		temp = (struct Link *)malloc(sizeof(struct Link));
		temp->ele =  element;
		temp->next = head;
		head = temp;
	}
	return head;
}

struct Link * addAtEnd(struct Link * head){
	int element;
	struct Link * temp, * extra;

	extra = head;
	printf("Enter element: ");
	scanf("%d",&element);
	if(head == NULL){
		head = (struct Link *)malloc(sizeof(struct Link));
		head->ele = element;
		head->next = NULL;
	}else{
		while(head->next!=NULL){
			head = head->next;
		}
		temp = (struct Link *)malloc(sizeof(struct Link));
		temp->ele = element;
		temp->next = NULL;
		head->next = temp;
		head = extra;
	}
	return head;
}

int length(struct Link * head){
	int len = 0;
	if(head==NULL){
		return len;
	}
	len++;
	while(head->next!=NULL){
		len++;
		head = head->next;
	}
	return len;
}

struct Link * addAtPosition(struct Link * head){
	if(head==NULL){
		printf("List is empty. Adding element at position 1\n");
		head = addAtBegin(head);
		return head;
	}
	int element,pos,index=1,len;
	struct Link * temp,* temp1;
	temp1 = head;
	len = length(head);
	printf("Enter Position: ");
	scanf("%d",&pos);
	if(pos>len+1 || pos<1){
		printf("Cannot be deleted. Out of range [%d,%d]\n",1,len);
		return head;
	}
	else if(pos==1){
		head = addAtBegin(head);
		return head;
	}
	else if(pos==len+1){
		head = addAtEnd(head);
		return head;
	}
	else{
		printf("Enter element: ");
		scanf("%d",&element);
		temp = (struct Link *)malloc(sizeof(struct Link));
		temp->ele = element;
		temp->next = NULL;
		while(index<pos-1){
			temp1 = temp1->next;
			index++;
		}
		temp->next = temp1->next;
		temp1->next = temp;
		return head;
		
	}
}

struct Link * deleteAtPosition(struct Link * head){
	if(head==NULL){
		printf("List is empty\n");
		return head;
	}
	struct Link * temp;
	temp = head;
	int element,pos,len,index=1;
	printf("Enter position to delete: ");
	scanf("%d",&pos);
	len = length(head);
	if(pos>len || pos<1){
		printf("Cannot be deleted. Out of range [%d,%d]\n",1,len);
	}else if(pos==1){
		head = head->next;
		return head;
	}

	else{
		while(index<pos-1){
			temp = temp->next;
			index++;
		}
		if(pos==len){
			temp->next = NULL;
		}else{
			temp->next = temp->next->next;	
		}
		return head;
	}
}

struct Link * reverseList(struct Link * head){
	struct Link * temp,* add;
	int i=1;
	while(head!=NULL){
		temp = (struct Link *)malloc(sizeof(struct Link));
		if(i==1){
			temp->ele = head->ele;
			temp->next = NULL;
			add = temp;
			i++;
		}else{
			temp->ele = head->ele;
			temp->next = add;
			add = temp;
		}
		head = head->next;
	}
	return temp;
}
struct Link * swapTwoNodes(struct Link *head){
	int node1,node2,len,index=1;
	struct Link * temp,* temp1;
	
	len = length(head);
	printf("Enter position 1: ");
	scanf("%d",&node1);
	printf("Enter position 2: ");
	scanf("%d",&node2);
	if((node1>len || node1<1) || (node2>len || node2<1) || (node1==node2)){
		printf("Check the positions\n");
		return head;
	}else{
		temp = head;	
		if(node1>node2){
			while(index<node2){
				if(index<node2){
					temp = temp->next;
				}
				head = head->next;
				index++;
			}
			temp1 = temp;
			temp->next = head->next;
			temp->next->next = temp1->next->next;
			head->next = temp1->next;
			head->next->next = temp1->next->next;
			
		}
		return temp;
	}
}

struct Link * sort(struct Link * head){
	struct Link * temp;
	while()
}

void print(struct Link * head){

	if(head==NULL){
		printf("List is empty :(\n");
	}else{
		printf("----------\n");
		while(head!=NULL){
			printf("%d\n",head->ele);
			head = head->next;
		}
		printf("----------");
	}
}



int main(){
	struct Link *head = NULL;
	int ch,len;
	do{
		printf("\nMenu:\n");
		printf("1. Add at begin\n");
		printf("2. Add at end\n");
		printf("3. Print elements\n");
		printf("4. Add at position\n");
		printf("5. Length\n");
		printf("6. Delete element at position\n");
		printf("7. Reverse list\n");
		printf("8. Swap 2 positions\n");
		printf("9. Sort\n")
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
				head = addAtBegin(head);
				break;
			case 2:
				head = addAtEnd(head);
				break;
			case 3:
				print(head);
				break;
			case 4:
				head = addAtPosition(head);
				break;
			case 5:
				len = length(head);
				printf("Length of list is %d\n",len);
				break;
			case 6:
				head = deleteAtPosition(head);
				break;
			case 7:
				head = reverseList(head);
				break;
			case 8:
//				head = swapTwoNodes(head);
				break;
			case 9:
				head = sort(head);
				break;
				
		}
	}while(ch!=0);
	
}
