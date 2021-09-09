//circular queue
#include<stdio.h>
#include<stdlib.h>
struct Queue {
    int rear;
    int front;
    int arr[3];
    int max;
};

void insert(struct Queue * q){
    int ele;
    if(q->rear+1==q->front || (q->front==0 && q->rear==q->max)){
        printf("Queue is full\n");
    }else{
        printf("Enter a number: \n");
        scanf("%d",&ele);
        if(q->rear==q->max){
            q->rear = -1;
        }
        if(q->front==-1){
            q->front = 0;
        }
        q->rear++;
        q->arr[q->rear] = ele;
    }
}

void dequeue(struct Queue * q){
    if(q->front==-1){
        printf("Queue is empty\n");
    }else{
        if(q->front==q->max){
            printf("Deleted: %d\n",q->arr[q->front]);
            q->front = 0;
        }
        else if(q->front==q->rear){
            printf("Deleted: %d\n",q->arr[q->front]);
            q->rear = -1;
            q->front = -1;
        }
        else{
            printf("Deleted: %d\n",q->arr[q->front]);
            q->front++;
        }
    }
}

void print(struct Queue * q){
    if(q->front==-1){
        printf("Queue is empty\n");
    }else{
        if(q->front<=q->rear){
            for (int i = q->front; i <= q->rear; i++)
            {
                printf("%d ",q->arr[i]);
            }
        }else{
            for (int i = 0; i<= q->rear;i++){
                printf("%d ",q->arr[i]);
            }
            for (int i = q->front; i <= q->max; i++)
            {
                printf("%d ",q->arr[i]);
            }
        }
    }
    printf("\n");
}

void p(struct Queue * q){
    printf("rear: %d\n",q->rear);
    printf("front: %d\n",q->front);
}

int main(){
    struct Queue * q;
    q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front=-1;
    q->rear=-1;
    q->max=2;
    int ch=4;
    do
    {
        printf("1.insert 2.pop 3.print 4.exit \n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                insert(q);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                print(q);
                break;
            case 5:
                p(q);
                break;
            case 4:
                break;
            default:
                printf("Enter valid choice");
        }
    } while (ch!=4);
    
}
