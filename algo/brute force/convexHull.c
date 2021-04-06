#include<stdio.h>

// Convex hull using brute force method

struct Point{
	int x,y;
	
};

void print(struct Point points[],int len){
	int i;
	for(i=0;i<len;i++){
		printf("x: %d y: %d\n",points[i].x,points[i].y);
	}
	printf("-----\n");
}

void convexHull(struct Point points[],int len){
	int i,j;
	for( i=0;i<len-1;i++){
		for( j=i+1;j<len;j++){
			int a,b,c;
			a = points[j].y - points[i].y;
			b = points[i].x - points[j].x;
			c = (points[i].x * points[j].y) - (points[i].y * points[j].x);
			int l = 0,r = 0,k;
			
			for( k=0;k<len;k++){
				if(k!=i && k!=j){
					int d = (a*points[k].x)+(b*points[k].y);
					if(d>=c){
						r++;
					}
					if(d<c){
						l++;
					}
					
				}
				if(l>0 && r>0){
					break;
				}
			}
			if(!(l>0 && r>0)){
				printf("x: %d y: %d\n",points[i].x,points[i].y);
				printf("x: %d y: %d\n",points[j].x,points[j].y);
			}
//			print(points,len);
		}
	}
}

int main(){
	struct Point points[] = {
//		{1,1
//		},
//		{3,1
//		},
//		{3,3
//		}
		
//		{1,5
//		},
//		{1,1
//		},
//		{2,2
//		},
//		{2,3
//		},
//		{3,3
//		},
//		{5,1
//		},
//		{4,4
//		},
//		{5,5
//		}

		{0,0
		},
		{0,4
		},
		{-4,0
		},
		{5,0
		},
		{0,-6
		},
		{1,0
		}
	};
	
    int len = sizeof(points)/sizeof(points[0]);
//    printf("%d",len);
    convexHull(points,len);
//    print(points,len);
}

