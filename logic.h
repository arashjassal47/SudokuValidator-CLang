//
// Created by Arashdeep Singh on 2/7/2021.
//

#ifndef ARASHDEEPSINGHASSIGN1_LOGIC_H
#define ARASHDEEPSINGHASSIGN1_LOGIC_H

#define TRUE 1
#define FALSE 0
int gridValidator(int grid[][9]);
void printSudoku(int arr[][9]);
int duplicityValidation(int arr[9],int noOfElements);
int rangeValidation(int arr[9],int noOfElements);
int userInputRowWise(int grid[][9]);
void randomSudokuGenerator(int arr[][9], int n);
#endif //ARASHDEEPSINGHASSIGN1_LOGIC_H
