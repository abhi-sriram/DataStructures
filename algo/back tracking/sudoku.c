#include <stdio.h>

// 9x9 sudoku solver

int check(int table[9][9],  int v1, int v2, int num)
{

    // Row checking
    for (int k = 0; k < 9; k++)
    {
        if (table[v1][k] == num)
        {
            return 1;
        }
    }
    // Column checking
    for (int k = 0; k < 9; k++)
    {
        if (table[k][v2] == num)
        {
            return 1;
        }
    }

    // 3x3 box checking
    int i = v1/3, j = v2/3;
    for (int a = 0; a < 3; a++)
    {
        for (int b = 0; b < 3; b++)
        {
            if(table[i*3+a][j*3+b]==num){
                return 1;
            }
        }
    }
    return 0;
}

int count = 0;


void print(int table[9][9]){
    count++;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            
            printf("%d ",table[i][j]);
        }
        printf("\n");
        
    }
   
    printf("\n\n\n");
}

void sudoku(int table[9][9],int i,int j){
    if(i==8 && j==8){
        print(table);
        return;
    }

    if(table[i][j]==0){
        for (int k = 1; k <=9; k++)
        {
            if(!check(table,i,j,k)){
                table[i][j] = k;
                j++;
                if(j==9){
                    j=0;
                    i++;
                }
                sudoku(table,i,j);
                if(j==0){
                    i--;
                    j=8;
                }else{
                    j--;
                }
                table[i][j] = 0;
            }
        }  
    }
    else{
        j++;
        if(j==9){
            j=0;
            i++;
        }
        sudoku(table,i,j);
    }
}


// Another method to solve sudoku problem 
// void sudoku(int table[9][9]){
//     for (int i = 0; i < 9; i++)
//     {
//         for (int j = 0; j < 9; j++)
//         {
//             if(table[i][j]==0){
//                 for (int k = 1; k <=9; k++)
//                 {
//                     if(!check(table,i,j,k)){
//                         table[i][j] = k;
//                         sudoku(table);
//                         table[i][j] = 0;
//                     }
//                 }
//                 return;
//             }
//         }
        
//     }
//     print(table);
    
// }

int main()
{
    // int table[9][9] = {
    //     {5,3,0,0,7,0,0,0,0},
    //     {6,0,0,1,9,5,0,0,0},
    //     {0,9,8,0,0,0,0,6,0},
    //     {8,0,0,0,6,0,0,0,3},
    //     {4,0,0,8,0,3,0,0,1},
    //     {7,0,0,0,2,0,0,0,6},
    //     {0,6,0,0,0,0,2,8,0},
    //     {0,0,0,4,1,9,0,0,5},
    //     {0,0,0,0,8,0,0,7,9}
    // };

    int table[9][9] = {
        {0,0,0,0,9,1,4,0,0},
        {0,0,0,7,0,0,0,0,0},
        {5,0,3,0,0,4,9,0,0},
        {7,0,4,0,0,0,0,5,0},
        {9,0,0,0,2,0,0,0,1},
        {0,2,0,0,0,0,6,0,4},
        {0,0,6,3,0,0,0,0,7},
        {0,0,0,0,7,6,0,0,0},
        {0,0,7,8,1,0,0,0,0}
    };

    // int table[9][9] = {
    //     {0,0,0,0,0,0,0,0,0},
    //     {0,0,0,0,0,0,0,0,0},
    //     {0,0,0,0,0,0,0,0,0},
    //     {0,0,0,0,0,0,0,0,0},
    //     {0,0,0,0,0,0,0,0,0},
    //     {0,0,0,0,0,0,6,0,0},
    //     {0,0,0,0,0,0,0,0,0},
    //     {0,0,0,0,0,0,0,0,0},
    //     {0,0,0,0,0,0,0,0,0}
    // };

   

    // printf("%d",check(table,4,4,1));
    sudoku(table,0,0);
    printf("\n\nCOUNT = %d",count);
    // for (int i = 0; i < 9; i++)
    // {
    //     for (int j = 0; j < 9; j++)
    //     {
    //         printf("%d ",table[i][j]);
    //     }
    //     printf("\n");
        
    // }
    

}
