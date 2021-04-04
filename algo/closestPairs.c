

#include <stdio.h>
#include <math.h>

// CLosest pair algorithm using brute force method

struct Point
{
    int x, y;
};

double distanceBetweenTwoPoints(struct Point po1,struct Point po2){
    double d = sqrt(pow((po2.x-po1.x),2)+pow((po2.y-po1.y),2));
    return d;
}

int main()
{
    struct Point p[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int len = sizeof(p)/sizeof(struct Point);
    double minDistance = 9999.99;
    struct Point p1 = p[0],p2=p[1];
    for(int i=0;i<len-1;i++){
        for(int j=i+1;j<len;j++){
           double d = distanceBetweenTwoPoints(p[i],p[j]);
           if(minDistance>d){
               minDistance = d;
               p1 = p[i];
               p2 = p[j];
           }
        }
    }
    printf("minDistance: %f\n",minDistance);
    printf("p1.x: %d p1.y: %d]n",p1.x,p1.y);
    printf("p2.x: %d p2.y: %d",p2.x,p2.y);

    return 0;
}
