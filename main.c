/**
 * @author - Arashdeep Singh
 * @date - 7 feb 2021
 * @version - 1.0
 */
//This programs checks the validity of Sudoku game. It checks if the given sudoku is valid or not(both by rows and columns).
//It also asks the user if he has a pre made solution and the programs again tells the validity of the Sudoku grid.
#include <stdio.h>
#include "logic.h"
int main() {
    int userGrid[][9]={0};
    //User interaction start.

    int n = userInputRowWise(userGrid);

    randomSudokuGenerator(userGrid,n);
    printSudoku(userGrid);

    return 0;
}

