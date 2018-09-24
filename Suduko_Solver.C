#include<iostream>
#include<vector>

//2D array size
#define N 9

//When the Cell is not assigned
#define UNASSIGNED 0

using namespace std;

/* Function to check suduko game completed or not
    True - If game get completed
    False - If game not yet completed */
bool board_done(int grid[9][9],int *row,int *col)
{
    for(int i =0; i < N; i++)
    {
        for(int j = 0; j < N ; j++)
        {
            if(grid[i][j] == UNASSIGNED)
            {
                *row = i;
                *col = j;
                return false;
            }
        }
    }
    return true;
}

/* Function to Check Whether conflict is there
    Check Corresponding row,column and 3 X 3 cells
    True - If Conflict not there
    False - If Conflict there */
bool isnotconflict(int grid[9][9],int row,int col,int value)
{
    for(int i = 0 ; i < N; i++)
    {
        if(grid[row][i] == value){
            return false;
        }
         if(grid[i][col] == value){
            return false;
        }     
    }
    
    int Colm = (col / 3) *3;
    
    for(int i = 0 ; i < 3; i++)
    {
        if(row == 0 || row == 3 || row == 6)
            {
                if(grid[row][i+Colm] == value || grid[row+1][i+Colm] == value || grid[row+2][i+Colm] == value)
                {
                    return false;
                }
            }
         if(row == 1 || row == 4 || row == 7)
            {
                if(grid[row-1][i+Colm] == value || grid[row][i+Colm] == value || grid[row+1][i+Colm] == value)
                {
                    return false;
                }
            }
        
        if(row == 2 || row == 5 || row == 8)
            {
                if(grid[row-1][i+Colm] == value || grid[row-2][i+Colm] == value || grid[row][i+Colm] == value)
                {
                    return false;
                }
            }
    }
    return true;
}
/* Recursion function to solve the Suduko puzzle */

bool sudoku_solve(int grid[9][9]) {
   int row ,col ;
   if(board_done(grid,&row,&col))
   {
       return true;
   }
    for(int i = 1; i < 10; i++)
    {
        if(isnotconflict(grid,row,col,i))
        {
            grid[row][col] = i;
            if(sudoku_solve(grid))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

int main(void) {
    int n, board[9][9];
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<9;j++) {
            for(int k=0;k<9;k++) {
                board[j][k] = 0;
                cin >> board[j][k];
            }
        }
        sudoku_solve(board);
         for(int j=0;j<9;j++) {
            for(int k=0;k<9;k++) {
                printf("%d ",board[j][k]);
            }
             printf("\n");
        }
    }
    return 0;
}
