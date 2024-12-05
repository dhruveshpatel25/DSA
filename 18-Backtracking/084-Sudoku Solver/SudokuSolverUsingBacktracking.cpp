/* Sudoku Solver
You have been given a 9x9 2d integer matrix 'MAT' representing a Sudoku puzzle. The empty cells of the Sudoku are filled with zeros, and the rest of the cells are filled with integers from 1 to 9. Your task is to fill all the empty cells such that the final matrix represents a Sudoku solution.

Note:
A Sudoku solution must satisfy all the following conditions-
1. Each of the digits 1-9 must occur exactly once in each row.
2. Each of the digits 1-9 must occur exactly once in each column.
3. Each of the digits 1-9 must occur exactly once in each of the 9, 3x3 sub-grids of the grid.

You can also assume that there will be only one sudoku solution for the given matrix.
https://www.naukri.com/code360/problems/sudoku-solver_699919?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar*/
#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int row,int col,vector<vector<int>> &sudoku,int val){
    int size = sudoku[0].size();
    for(int i=0;i<size;i++){
        
        //checking in row 
        if(sudoku[row][i]==val){
            return false;
        }

        //checking in col
        if(sudoku[i][col]==val){
            return false;
        }

        //checking in 3*3 matrix
        if(sudoku[3*(row/3)+i/3][3*(col/3)+i%3]==val){
            return false;
        }
    }
}

bool solve(vector<vector<int>>& sudoku){
    int size = sudoku[0].size();

    //for every horizontal iteration
    for(int row=0;row<size;row++){

        //for every bit in that particular row
        for(int col=0;col<size;col++){

            //if there is 0 value then check further
            if(sudoku[row][col]==0){

                //for all the number that can be put
                for(int val=0;val<=9;val++){

                    //to check if we are able to put that value
                    if(isSafe(row,col,sudoku,val)){
                        sudoku[row][col]=val;

                        //to check for more cells with that particular value in that particular box
                        bool morePossibleSolution = solve(sudoku);

                        //if possible return true
                        if(morePossibleSolution){
                            return true;
                        }else{ //backtrack and reset the value to 0 for more possible value
                            sudoku[row][col]=0;
                        }  
                    }
                }
                //if not possible then return false
                return false;
            }
        }
    }

    //return true as we reached the solution
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku){
    solve(sudoku);
}

void printSudoku(const vector<vector<int>>& sudoku) {
    for (const auto& row : sudoku) {

        //for printing it in box shaped
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> sudoku = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Sudoku before solving:" << endl;
    printSudoku(sudoku);

    solveSudoku(sudoku);

    cout << "\nSudoku after solving:" << endl;
    printSudoku(sudoku);

    return 0;
}