#include<stdio.h>

#define ROWS 15
#define COLS 15


int array[ROWS][COLS];
int checkList[ROWS][COLS];
int rowSums[ROWS];
int colSums[COLS];


int main(){    
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            scanf(" %d", &array[row][col]);
        }
    }

   for(int i= 0;i<ROWS; i++){
    int rowSum = 0;
    int colSum = 0;
    for(int j = 0;j<COLS;j++){
        rowSum += array[i][j];
        colSum += array[j][i];
        checkList[i][j] = 0;
    }
    
    rowSums[i] = rowSum;
    colSums[i] = colSum;
   }

   int matchCount = 0;

   for(int i = 0; i<ROWS; i++){
    for(int j = 0; j<COLS; j++){
        

    }
   }

   for(int i = 0; i<ROWS; i++){
    for(int j = 0; j<COLS; j++){

        if(rowSums[i] == colSums[j]){
            checkList[i][j] = 1;
           
        }

        if(rowSums[i] == rowSums[j] && checkList[j][i] != 1&& i != j){
            checkList[i][j] = 1;
        }

        if(colSums[i] == colSums[j]  && checkList[j][i] != 1 && i != j){
            checkList[i][j] = 1;
        }
    }
   }

  
   for(int i = 0; i<ROWS; i++){
    for(int j = 0; j<COLS; j++){
        if(checkList[i][j] == 1 ){
            printf("%d %d\n",i,j);

        }
    }
   }

    return 0;
}