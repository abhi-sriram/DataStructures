#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct  Point
{
    int x,y;
};

int flag;

void merge(struct Point p[],int start,int mid,int end){
    int len = end-start;
    struct Point temp[len];
    int i=start,j=mid+1,k=0;
    while (i<=mid && j<=end)
    {
        if(flag==0){
            if(p[i].x<p[j].x){
                temp[k] = p[i];
                i++;
            }else{
                temp[k] = p[j];
                j++;
            }
        }else{
            // sort according to y cord
            if(p[i].y<p[j].y){
                temp[k] = p[i];
                i++;
            }else{
                temp[k] = p[j];
                j++;
            }
        }
        k++;
    }
    while (i<=mid)
    {
        temp[k] = p[i];
        i++;
        k++;
    }

    while (j<=end)
    {
        temp[k] = p[j];
        j++;
        k++;
    }
    
    for (int i = 0; i < k; i++)
    {
        p[start+i] = temp[i];
    }
    
    
}

void mergeing(struct Point p[],int start,int end){
    if(end-start>1){
        int mid = (start+end)/2;
        mergeing(p,start,mid);
        mergeing(p,mid+1,end);
        merge(p,start,mid,end);
    }
}

float min(float x,float y){
    return x<y?x:y;
}

float distance(struct Point p1,struct Point p2){
    double d = sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2));
    return d;
}

float stripClosest(struct Point strip[],int size,float d){
    float min = d;
    flag = 1;
    mergeing(strip,0,size);
    for (int i = 0; i < size; i++)
    {
        for (int  j = i+1; j <= (size && (strip[j].y-strip[i].y)<min); j++)
        {
            if(distance(strip[j],strip[i])<min){
                min = distance(strip[j],strip[i]);
            }
        }
        
    }
    return min;
    
}

float bruteForce(struct Point p[],int n){
    float min = INFINITY;
    for (int i = 0; i <n; i++)
    {
        for (int j = i+1; j <=n; j++)
        {
            float d = distance(p[i],p[j]);
            if(d<min){
                min = d;
            }
        }
        
    }

    return min;
    
}


float closestUtil(struct Point p[],int n){
    if(n<=3){
        return bruteForce(p,n);
    }

    int mid = n/2;
    float dl = closestUtil(p,mid);
    float dr = closestUtil(p+mid,n-mid);

    float d = min(dl,dr);
    struct Point strip[n];
    int k=0;
    for (int i = 0; i <=n; i++)
    {
        if(abs(p[i].x-p[mid].x)<d && i!=mid){
            strip[k] = p[i];
            k++;
        }
    }

    return min(d,stripClosest(strip,k-1,d));
    
    
}

int main(){
    struct Point p[] = {{2,3},{12,30},{40,50},{5,1},{12,10},{3,4}};
    int len = sizeof(p)/sizeof(struct Point);
    flag=0;
    mergeing(p,0,len-1);
    float min = closestUtil(p,len-1);
    printf("\nMIN: %f",min);
    // for (int i = 0; i < len; i++)
    // {
    //     printf("%d, %d\n",p[i].x,p[i].y);
    // }
    
}
