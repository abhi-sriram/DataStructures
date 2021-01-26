#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct tree{
	struct tree * left;
	int e;
	struct tree * right;
};

struct queue{
	struct tree * add[20];
	int f;
	int r;
};

void enqueue(struct queue * q,struct tree * temp){

		q->add[q->r] = temp;
		q->r++;
	
}
struct tree * dequeue(struct queue * q){
	struct tree * temp;
	if(q->r==q->f){
		printf("Queue is empty.\n");
	}else{
		temp = q->add[q->f];
		for(int i=0;i<q->r-1;i++){
			q->add[i] = q->add[i+1];
		}
		q->r--;
	}
	return temp;
}

struct tree * insert(struct tree * root){
	int ele;
	printf("Enter element: ");
	scanf("%d",&ele);
	if(root == NULL){
		root = (struct tree *)malloc(sizeof(struct tree));
		root->e = ele;
		root->left = NULL;
		root->right = NULL;
		
	}else{
		struct tree * temp,* nn;
		struct queue * q;
		q = (struct queue *)malloc(sizeof(struct queue));
		nn = (struct tree *)malloc(sizeof(struct tree));
		nn->e = ele;
		nn->left = NULL;
		nn->right = NULL;
		q->f = 0;
		q->r = 0;
		temp = root;
		enqueue(q,temp);
		while(1){
			temp = dequeue(q);
			if(temp->left==NULL){
				temp->left = nn;
				break;
			}else{
				enqueue(q,temp->left);
			}
			if(temp->right==NULL){
				temp->right = nn;
				break;
			}else{
				enqueue(q,temp->right);
			}
		}	
	}
	return root;
}

bool isEmpty(struct queue * q){
	if(q->f==q->r){
		return true;
	}else{
		return false;
	}
}

int length(struct tree * root){
	if(root == NULL){
		return 0;
	}else{
		int len = 0;
		struct queue * q;
		q = (struct queue *)malloc(sizeof(struct queue));
		q->r = 0;
		q->f = 0;
		enqueue(q,root);
		while(!isEmpty(q)){
			root = dequeue(q);
			len++;
			if(root->left!=NULL){
				enqueue(q,root->left);
			}
			if(root->right!=NULL){
				enqueue(q,root->right);
			}
		}
		return len;
		
	}
}

struct tree * find(struct tree * root,int ele){
	if(root==NULL){
		return NULL;
	}else{
		struct queue * q;
		q = (struct queue *)malloc(sizeof(struct queue));
		q->f = 0;
		q->r = 0;
		enqueue(q,root);
		while(!isEmpty(q)){
			root = dequeue(q);
			if(root->e==ele){
				return root;
			}
			if(root->left!=NULL){
				enqueue(q,root->left);
			}
			if(root->right!=NULL){
				enqueue(q,root->right);
			}
		}
		return NULL;
	}
}

struct tree * findLast(struct tree * root){
	struct queue * q;
	struct tree * temp;
	q = (struct queue *)malloc(sizeof(struct queue));
	q->f = 0;
	q->r = 0;
	enqueue(q,root);
	while(!isEmpty(q)){
		temp = dequeue(q);
		if(temp->left!=NULL){
			enqueue(q,temp->left);
		}
		if(temp->right!=NULL){
			enqueue(q,temp->right);
		}
	}
	return temp;
}

struct tree * findLastParent(struct tree * root,struct tree * child){
	struct tree * temp;
	struct queue * q;
	q = (struct queue *)malloc(sizeof(struct queue));
	q->f = 0;
	q->r = 0;
	enqueue(q,root);
	while(!isEmpty(q)){
		temp = dequeue(q);
		if(temp->left==child){
			return temp;
		}
		if(temp->left!=NULL){
			enqueue(q,temp->left);
		}
		
		if(temp->right==child){
			return temp;
		}
		if(temp->right!=NULL){
			enqueue(q,temp->right);
		}
	}
}

struct tree * deleteElement(struct tree * root,int ele){
	struct tree * temp,* temp1, * temp2;
	temp = find(root,ele);
	if(temp!=NULL){
		
		temp1 = findLast(root);
		if(temp==temp1){
			root = NULL;
			return root;
		}
		temp2 = findLastParent(root,temp1);
		if(temp2->left==temp1){
			temp->e = temp1->e;
			temp2->left = NULL;
//			printf("........%d\n",temp2->left->e);
		}else{
			temp->e = temp1->e;
			temp2->right = NULL;
//			printf("........%d\n",temp2->right->e);
		}
		
	}
	return root;
}

void print(struct tree * root){
	printf("---------------\n");
	if(root==NULL){
		printf("Empty tree\n");
	}else{
		struct tree * temp;
		struct queue * q;
		q = (struct queue *)malloc(sizeof(struct queue));
		q->f = 0;
		q->r = 0;
		temp = root;
		enqueue(q,temp);
		while(!isEmpty(q)){
			temp = dequeue(q);
			printf("%d\n",temp->e);
			if(temp->left!=NULL){
				enqueue(q,temp->left);
			}
			
			if(temp->right!=NULL){
				enqueue(q,temp->right);
			}

		}
			
	}
	printf("---------------\n");
}

int main(){
	struct tree * root = NULL,* temp;
	int ch,ele;
	
	do{
		printf("Menu\n1. Insert\n2. Print\n3. Length\n4. Find\n5. Delete\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				root = insert(root);
				break;
			case 2:
				print(root);
				break;
			case 3:
				printf("Length: %d\n",length(root));
				break;
			case 4:
				printf("Enter element to search: ");
				scanf("%d",&ele);
				temp = find(root,ele);
				if(temp != NULL){
					printf("Element is present\n");
				}else{
					printf("Element is not present\n");
				}
				break;
			case 5:
				printf("Enter element to delete: ");
				scanf("%d",&ele);
				root = deleteElement(root,ele);
				break;
		}
	}while(ch!=0);
}
