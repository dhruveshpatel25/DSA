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
    for(int row=0;row<size;row++){
        for(int col=0;col<size;col++){
            if(sudoku[row][col]==0){
                for(int val=0;val<=9;val++){
                    if(isSafe(row,col,sudoku,val)){
                        sudoku[row][col]=val;
                        bool morePossibleSolution = solve(sudoku);
                        if(morePossibleSolution){
                            return true;
                        }else{
                            sudoku[row][col]=0;
                        }  
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku){
    solve(sudoku);
}

void printSudoku(const vector<vector<int>>& sudoku) {
    for (const auto& row : sudoku) {
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