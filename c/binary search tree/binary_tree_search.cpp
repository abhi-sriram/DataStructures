#include <stdio.h>
#include <stdlib.h>
#define COUNT 10 

struct tree{
	int e;
	struct tree * left;
	struct tree * right;
};

struct queue{
	struct tree * arr[10];
	int f;
	int r;
};

void enqueue(struct queue * q,struct tree * temp){
	q->r++;
	q->arr[q->r] = temp;
}

struct tree * dequeue(struct queue * q){
	struct tree * temp;
	if(q->f==q->r){
		printf("queue is empty\n");
		return NULL;
	}
	temp = q->arr[0];
	q->r--;
	for(int i=0;i<q->r+1;i++){
		q->arr[i] = q->arr[i+1];
	}
	return temp;
}

struct tree * deleteNode(struct tree * root,int ele);

struct tree * insert(struct tree * root,int ele){
	if(root==NULL){
		root = (struct tree *)malloc(sizeof(struct tree));
		root->e = ele;
		root->left = NULL;
		root->right = NULL;
	}else{
		struct tree * nn,* temp;
		nn = (struct tree *)malloc(sizeof(struct tree));
		nn->e = ele;
		nn->left = NULL;
		nn->right = NULL;
		temp = root;
		while(1){
			if(temp->e>ele){
//				left node
				if(temp->left==NULL){
					temp->left = nn;
					break;
				}
				temp = temp->left;
			}else{
				if(temp->right==NULL){
					temp->right = nn;
					break;
				}
				temp = temp->right;
//				right node
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

//printing tree structure

void print2DUtil(struct tree *root, int space) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtil(root->right, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->e); 
  
    // Process left child 
    print2DUtil(root->left, space); 
}

int caseCondition(struct tree * root,int num){
	struct queue *q ;
	q  = (struct queue *)malloc(sizeof(struct queue));
	q->f = -1;
	q->r =-1;
	enqueue(q,root);
	while(!isEmpty(q)){
		root = dequeue(q);
		if(root->left!=NULL){
			enqueue(q,root->left);
		}
		if(root->right!=NULL){
			enqueue(q,root->right);
		}
		if(root->e==num){
			if(root->left==NULL && root->right==NULL){
//				leaf node
				return 1;
			}
			else if(root->left==NULL || root->right==NULL){
//				only one child
				return 2;
			}
			else{
//				two childs
				return 3;
			}
		}
	}
//	element not found
	return 0;
	
}

//traverse upto the element
struct tree * traverseUptoElement(struct tree * root,int ele){
	struct queue *q ;
	q  = (struct queue *)malloc(sizeof(struct queue));
	q->f = -1;
	q->r =-1;
	enqueue(q,root);
	while(!isEmpty(q)){
		root = dequeue(q);
		if(root->left!=NULL){
			enqueue(q,root->left);
		}
		if(root->right!=NULL){
			enqueue(q,root->right);
		}
		if(root->e==ele){
			return root;
		}
	}
}
//traverse upto parent of element
struct tree * traverseUptoParent(struct tree * root,struct tree * child){
	struct queue *q ;
	q  = (struct queue *)malloc(sizeof(struct queue));
	q->f = -1;
	q->r =-1;
	enqueue(q,root);
	while(!isEmpty(q)){
		root = dequeue(q);
		if(root->left==child){
			return root;
		}
		if(root->right==child){
			return root;
		}
		if(root->left!=NULL){
			enqueue(q,root->left);
		}
		if(root->right!=NULL){
			enqueue(q,root->right);
		}
	}
}

struct tree * leafNode(struct tree * root,int ele){
	if(root->e==ele){
		printf("%d is deleted from tree\n",root->e);
		return NULL;
	}
	struct tree* child,*parent;
	child = traverseUptoElement(root,ele);
	parent = traverseUptoParent(root,child);
	if(parent->left==child){
		printf("%d is deleted from tree\n",child->e);
		parent->left = NULL;
		
	}else{
		printf("%d is deleted from tree\n",child->e);
		parent->right = NULL;
	}
	return root;
}

//single node, either left or right

struct tree * singleNode(struct tree * root,int ele){
//	check root is the ele
//check parent of the ele is root
	struct tree * child,* parent;
	child = traverseUptoElement(root,ele);
	if(child==root){
		if(root->left!=NULL){
			root = root->left;
			printf("%d is deleted from tree\n",child->e);
			return root;
		}else{
			root = root->right;
			printf("%d is deleted from tree\n",child->e);
			return root;
		}
	}
	parent = traverseUptoParent(root,child);
	if(parent->left==child){
		if(child->left!=NULL){
			parent->left = child->left;
		}else{
			parent->left = child->right;
		}
	}else{
		if(child->left!=NULL){
			parent->right = child->left;
		}else{
			parent->right = child->right;
		}
	}
	printf("%d is deleted from tree\n",child->e);
	return root;
}

//doubleNode, both left and right node present
struct tree * doubleNode(struct tree * root,int ele){
//	check ele == root
	struct tree * child,* right;
	child = traverseUptoElement(root,ele);
	right = child->right;
	while(right->left!=NULL){
		right = right->left;
	}
	root = deleteNode(root,right->e);
	child->e = right->e;
	printf("%d is deleted from tree and replaced by %d\n",ele,right->e);
	return root;
}


struct tree * deleteNode(struct tree * root,int ele){
	if(root==NULL){
		printf("Tree is empty\n");
		return NULL;
	}
	int condition = caseCondition(root,ele);
	if(condition==0){
		printf("Number is not found\n");
		return root;
	}else if(condition==1){
		root = leafNode(root,ele);
		return root;
	}
	else if(condition==2){
		root = singleNode(root,ele);
		return root;
	}else{
		root= doubleNode(root,ele);
		return root;
	}
	
	
	
}
void inorderTraversal(struct tree * root){
	if(root->left){
		inorderTraversal(root->left);
	}
	printf("%d\n",root->e);
	if(root->right){
		inorderTraversal(root->right);
	}
	
}

void preorderTraversal(struct tree * root){
	printf("%d\n",root->e);
	if(root->left){
		preorderTraversal(root->left);
	}
	if(root->right){
		preorderTraversal(root->right);
	}
}

void postorderTraversal(struct tree * root){
	if(root->left)
		postorderTraversal(root->left);
	if(root->right)
		postorderTraversal(root->right);
	printf("%d\n",root->e);
}
//
//void print(struct tree * root){
//	printf("------------\n");
//	if(root==NULL){
//		printf("Empty tree\n");
//	}else{
//		struct queue *q ;
//		struct tree * temp;
//		temp = root;
//		q  = (struct queue *)malloc(sizeof(struct queue));
//		q->f = -1;
//		q->r =-1;
//		enqueue(q,root);
//		while(!isEmpty(q)){
//			temp = dequeue(q);
//			if(temp->left!=NULL){
//				enqueue(q,temp->left);
//			}
//			if(temp->right!=NULL){
//				enqueue(q,temp->right);
//			}
//			printf("%d\n",temp->e);
//			
//		}
//	}
//	
//	printf("------------\n");
//}


int main(){
	struct tree * root = NULL;
	int ch,ele;
	do{
		printf("Menu\n1. Insert\n2. Print\n3. Delete\n4. Inorder Traversal\n5. Postorder Traversal\n6. Preorder Traversal\n0. Exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter number: ");
				scanf("%d",&ele);
				root = insert(root,ele);
				break;
			case 2:
				print2DUtil(root,0);
				break;	
			case 3:
				printf("Enter number to delete: ");
				scanf("%d",&ele);
				root = deleteNode(root,ele); 
				break;
			case 4:
				inorderTraversal(root);
				break;
			case 5:
				postorderTraversal(root);
				break;
			case 6:
				preorderTraversal(root);
				break;
			case 0:
				break;
			default: 
				printf("Invalid input\n");
		}
	}while(ch!=0);
}
