//
// Created by Arashdeep Singh on 2/7/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "logic.h"

/**
 *
 * @param grid
 * @return int
 * returns TRUE(1) if the grid is valid, otherwise returns FALSE(2).
 */
int gridValidator(int grid[][9]){
    int isValid=TRUE;
    int originalElementR=0;
    int toBeCheckElementR=0;
    int originalElementC=0;
    int toBeCheckElementC=0;
    int lastElement=grid[8][8];//This element is not covered in my for loop(only for range validation)
    if(lastElement>9||lastElement<1){
        isValid=FALSE;
        return isValid;
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            originalElementR=grid[i][j];
            originalElementC=grid[j][i];
            if(originalElementC>9||originalElementC<1||originalElementR>9||originalElementR<1){
                isValid=FALSE;
                return isValid;
            }
            for(int k=j+1;k<9;k++){
                toBeCheckElementR=grid[i][k];
                toBeCheckElementC=grid[k][i];
                if(originalElementR==toBeCheckElementR||originalElementC==toBeCheckElementC){
                    isValid=FALSE;
                    return isValid;
                }//if-statement ends
            }//inner for-loop ends
        }//middle for-loop ends
    }//outer for-loop ends
    return isValid;
}//gridValidator ends

/**
 *
 * @param arr
 * It simply prints the sudoku and also validates it.
 */
void printSudoku(int arr[][9]){
    puts("-----------Sudoku Grid-----------");
    for(int row=0;row<9;row++){
        for(int col=0;col<9;col++){
            printf("%d   ",arr[row][col]);
        }
        puts(" ");
    }
    puts(" ");
    int result=gridValidator(arr);
    if(result){
        puts("Given Sudoku grid is valid.");
    }else{
        puts("Given Sudoku grid is invalid.");
    }
}

/**
 *
 * @param arr - 1D array
 * @param noOfElements - number of elements in the array.
 * @return - TRUE(1) if the array is valid, otherwise returns FALSE(2).
 * Checks for any dupicate value in the 1D array.
 */
int duplicityValidation(int arr[9],int noOfElements){
    int isValid=TRUE;
    for(int i=0;i<noOfElements;i++){
        for(int j=i+1;j<noOfElements;j++){
            if(arr[i]==arr[j]) {
                isValid = FALSE;
                return isValid;
            }
        }
    }
    return isValid;
}

/**
 *
 * @param arr - 1D array
 * @param noOfElements - number of elements in the array.
 * @return - TRUE(1) if the array is valid, otherwise returns FALSE(2).
 * Checks for any out-of-range value in the 1D array.
 */
int rangeValidation(int arr[9],int noOfElements){
    int isValid=TRUE;
    for(int i=0;i<noOfElements;i++){
        if(arr[i]<1||arr[i]>9){
            isValid=FALSE;
            return isValid;
        }
    }
    return isValid;
}

/**
 *
 * @param grid - 2D array
 */
int userInputRowWise(int grid[][9]){
    char buffer[80];
    int n=4;
    int duplicityResult=FALSE;
    int rangeResult=FALSE;
    int row=0;
    int checkSkip=0;
    printf("Use Space/Tab/Return key to enter the next values\nand press 'Return' after entering nine integers.\n");
    printf("Remember, to make a valid row of Sudoku grid,\nall integers should be distinct and range from 1 to 9\n");
    printf("Remember, you can skip manual entry and go for random generated values by entering '9'\n");
    for(int i=0;i<9;i++){
        while(n!=9&&checkSkip!=9){
            printf("Enter row %d of your Sudoku grid\n",row+1);
            fgets(buffer,sizeof(buffer),stdin);
            n=sscanf(buffer,"%d%d%d%d%d%d%d%d%d",&grid[row][0],&grid[row][1],&grid[row][2],&grid[row][3],
                     &grid[row][4],&grid[row][5],&grid[row][6],&grid[row][7],&grid[row][8]);
            if(n==1&&grid[row][0]==9){
                printf("Generating random values...\n");
                i=10;
                checkSkip=9;
            }
            if(n!=9&&checkSkip!=9){
                printf("Enter exactly nine INTEGERS separated by Space/Tab followed by Enter key to end\n");
            }
            int rowArray[9]={grid[row][0],grid[row][1],grid[row][2],grid[row][3],
                             grid[row][4],grid[row][5],grid[row][6],grid[row][7],grid[row][8]};
            duplicityResult=duplicityValidation(rowArray,n);
            if(duplicityResult==FALSE){
                printf("There is a duplicate entry\n\nEnter nine distinct integers, No duplicates please!\n");
                n=1;
            }

            rangeResult=rangeValidation(rowArray,n);
            if(rangeResult==FALSE){
                printf("One or more entries are outside the range 1 to 9!\n");
                n=1;
            }
        }
        n=4;
        row++;
    }
    return row-1;
}

/**
 *
 * @param arr - 2D array
 * @param n - to know from which row to start.
 * It populate the 2D sudoku array with random values.
 */
void randomSudokuGenerator(int arr[][9], int n){
    int range=8;
    int offset=1;
    int random=0;
    int unique;
    for(int row=n;row<9;row++){
        for(int col=0;col<9;col++){
            do{
                unique = 1;
                random= rand()%(range+1)+offset;
                for(int k=0;k<col&&unique==1;k++){
                    if(arr[row][k]==random){
                        unique = 0;
                    }
                }
            }while(unique != 1);
            arr[row][col] = random;
        }
    }
    srand(time(NULL));
}
