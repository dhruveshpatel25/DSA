/* The N - Queens Puzzle
Problem statement
The N Queens puzzle is the problem of placing N chess queens on an N * N chessboard such that no two queens attack each other.

Given an integer ‘N’, print all distinct solutions to the ‘N’ queen puzzle.

Two queens on the same chessboard can attack each other if any of the below condition satisfies:  
1. They share a row. 
2. They share a column. 
3. They share a diagonal. 
https://www.naukri.com/code360/problems/the-n-queens-puzzle_981286*/
#include<iostream>
#include<vector>
using namespace std;

void addSolution(vector<vector<int>> &board,vector<vector<int>> &ans,int n){

    //temporary vector to store the board
    vector<int> temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);
        }
    }

    //pushing it completely
    ans.push_back(temp);
}

bool isSafe(int row,int col,vector<vector<int>> &board,int n){

    //row checking(piche ke cols for particular row)
    int x=row;
    int y=col;
    while(y>=0){
        if(board[x][y]==1){
            return false;  
        }

        //go column wise behind
        y--;
    } 
    //col checking not required as we move to new col after placing queens

    //diagonal-checking(checking in piche diagonal)
    x=row;
    y=col;

    //upper checking
    while(x>=0 && y>=0){ 
        if(board[x][y]==1){
            return false;   
        }

        //go diagonally top left
        y--;
        x--;
    }

    x=row;
    y=col;

    //lower checking
    while(x<n && y>=0){  
        if(board[x][y]==1){
            return false;
        }

        //go diagonally bottom-left
        y--;
        x++;
    }

    return true;
}

void solve(int col,vector<vector<int>> &ans,vector<vector<int>> &board, int n){
    //base case-if we completed last column
    if(col==n){
        addSolution(board,ans,n);
        return;
    }
    //for 1st col
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]=1;

            //recursion for other col 
            solve(col+1,ans,board,n);

            //backtracking 
            board[row][col]=0; 
        }
    }
}

vector<vector<int>> nQueens(int n){

    //making board of n size starting from 0
    vector<vector<int>> board(n, vector<int>(n,0));

    //ans array for storing all the boards possible
    vector<vector<int>> ans;
    solve(0,ans,board,n);
    return ans;
}

void printSolution(vector<vector<int>>& solution) {

    //for printing in board wise
    for (const auto& row : solution) {
        for (int col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the value of N (size of the chessboard): ";
    cin >> n;

    // Solve the N-Queens problem
    vector<vector<int>> solutions = nQueens(n);

    // Print the solutions
    if (solutions.empty()) {
        cout << "No solutions exist for N = " << n << "." << endl;
    } else {
        cout << "Number of solutions for N = " << n << ": " << solutions.size() << endl;
        cout << "Solutions: " << endl;

        int solutionNumber = 1;
        for (const auto& solution : solutions) {
            cout << "Solution " << solutionNumber++ << ":" << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << solution[i * n + j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }

    return 0;
}
