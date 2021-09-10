#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * left;
    struct Node * right;
};
struct Node *root = NULL;


struct queue{
	struct Node * add[20];
	int f;
	int r;
};

void enqueue(struct queue * q,struct Node * temp){

		q->add[q->r] = temp;
		q->r++;
	
}
struct Node * dequeue(struct queue * q){
	struct Node * temp;
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


void insert(){
    int d;
    printf("Enter a number : ");
    scanf("%d",&d);
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = d;
    temp->left = NULL;
    temp->right = NULL;
    if(root==NULL){
        root = temp;
    }
    else{
      struct Node *parent,*p;
      p = root;
      while (p!=NULL)
      {
          parent = p;
          if(p->data<d){
              p = p->right;
          }else{
              p = p->left;
          }
      }
      if(parent->data>d){
          parent->left = temp;
      }else{
          parent->right = temp;
      } 
    }
}

void delete(){
    if(root==NULL){
        printf("Tree is empty\n");
        return;
    }
    int d;
    printf("Enter a number to delete: ");
    scanf("%d",&d);
    struct Node * temp = root,*parent=root;
    while (temp->data!=d){
          parent = temp;
          if(temp->data<d){
              temp = temp->right;
          }else{
              temp = temp->left;
          }
    }
    if(temp->data==d){
        
        if(temp->left==NULL && temp->right==NULL){
            printf("1");

            // if root == temp
            if(root==temp){
                root = NULL;
                free(temp);
            }else{
                // no child
                if(parent->left==temp){
                    parent->left=NULL;
                }
                if(parent->right==temp){
                    parent->right=NULL;
                }
                free(temp);
            }
            
        }
        else if(temp->left==NULL && temp->right!=NULL){
            printf("2");

            //if temp==root
            if(temp==root){
                root = temp->right;
                return;
            }
            // left node is NULL and right node exists
            if(parent->left==temp){
                parent->left = temp->right;
            }
            if(parent->right==temp){
                parent->right = temp->right;
            }
            temp->right = NULL;
            free(temp);
        }
        else if(temp->left!=NULL && temp->right==NULL){
            printf("3");

            // temp==root
            if(temp==root){
                root = temp->left;
                return;
            }
            // left node exists and right node is NULL
            if(parent->left==temp){
                parent->left = temp->left;
            }
            if(parent->right==temp){
                parent->right = temp->left;
            }
            temp->left = NULL;
            free(temp);
        }
        else{
            printf("Zero");
            // RIGHT SIDE
            // both node exists
            struct Node *child = temp->right,*childParent=temp;
            while(child->left!=NULL){
                childParent = child;
                child = child->left;
            }
            if(child->left==NULL && child->right==NULL && childParent!=temp){
                printf("one");
                temp->data = child->data;
                childParent->left = NULL;
                free(child);
                return;
            }
            if(child->left==NULL && child->right==NULL && childParent==temp){
                printf("Two");
                temp->data = child->data;
                childParent->right = NULL;
                free(child);
                return;
            }
            //temp!=root and child->left doesn't exist and child==temp->right
            if(child==temp->right){
                printf("Three");
                struct Node *a = temp->left;
                if(temp==root){
                    root = temp->right;
                    root->left = a;
                    return;
                }
                
                if(parent->right==temp){
                    parent->right = child;
                    parent->right->left = temp->left;
                    temp->right=NULL;
                    temp->left = NULL;
                    free(temp);
                }else{
                    parent->left = child;
                    parent->left->left = temp->left;
                    temp->right=NULL;
                    temp->left = NULL;
                    free(temp);
                }
                return;
            }
            //temp!=root and child->left doesn't exist and child!=temp->right
            if(child!=temp->right){
                printf("Four");
                childParent->left = child->right;
                temp->data = child->data;
                return;
            }

            
        }
    }else{
        printf("Cannot find the data.\n");
    }
}

void inOrderDisplay(struct Node *temp){
    // in order -> left - parent - right
    // Ascending order
    if(temp==NULL){
        printf("Empty BST\n");
        return;
    }
    if(temp->left!=NULL){
        inOrderDisplay(temp->left);
    }
    printf("%d--",temp->data);
    if(temp->right!=NULL){
        inOrderDisplay(temp->right);
    }
}

void preOrderDisplay(struct Node *temp){
    if(temp==NULL){
        printf("Empty BST\n");
        return;
    }
    // pre order -> parent - left - right
    printf("%d--",temp->data);
    if(temp->left!=NULL){
        preOrderDisplay(temp->left);
    }
    if(temp->right!=NULL){
        preOrderDisplay(temp->right);
    }
}

void postOrderDisplay(struct Node *temp){
    if(temp==NULL){
        printf("Empty BST\n");
        return;
    }
    // Post order -> left - right - parent
    if(temp->left!=NULL){
        postOrderDisplay(temp->left);
    }
    if(temp->right!=NULL){
        postOrderDisplay(temp->right);
    }
    printf("%d--",temp->data);
}

int isEmpty(struct queue * q){
	if(q->f==q->r){
		return 1;
	}else{
		return 0;
	}
}

void levelOrderDisplay(struct Node *temp){
	if(root==NULL){
		printf("Empty tree\n");
	}else{
		struct Node * temp;
		struct queue * q;
		q = (struct queue *)malloc(sizeof(struct queue));
		q->f = 0;
		q->r = 0;
		temp = root;
		enqueue(q,temp);
		while(!isEmpty(q)){
			temp = dequeue(q);
			printf("%d",temp->data);
			if(temp->left!=NULL){
				enqueue(q,temp->left);
			}
			
			if(temp->right!=NULL){
				enqueue(q,temp->right);
			}

		}
			
	}
    
}

int main(){
   
    
    int ch;
    do
    {
        printf("\n--------------------\n\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Inorder Display\n");
        printf("4. Preorder Display\n");
        printf("5. Postorder Display\n");
        printf("6. Levelorder Display\n");
        printf("0. Exit\n");
        printf("\n--------------------\n\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            inOrderDisplay(root);
            break;
        case 4:
            preOrderDisplay(root);
            break;
        case 5:
            postOrderDisplay(root);
            break;
        case 6:
            levelOrderDisplay(root);
            break;
        case 0:
            break;
        default:
            printf("Invalid Input.\n");
            break;
        }

    } while (ch!=0);
    
}
