#include<iostream>
#include<vector>
using namespace std;

void addSolution(vector<vector<int>> &board,vector<vector<int>> &ans,int n){
    vector<int> temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);
        }
    }
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
        y--;
    } 
    //col checking not required as we move to new col after placing queens

    //diagonal-checking(checking in piche diagonal)
    x=row;
    y=col;
    while(x>=0 && y>=0){ //upper checking
        if(board[x][y]==1){
            return false;   
        }
        y--;
        x--;
    }

    x=row;
    y=col;
    while(x<n && y>=0){  //lower checking
        if(board[x][y]==1){
            return false;
        }
        y--;
        x++;
    }

    return true;
}

void solve(int col,vector<vector<int>> &ans,vector<vector<int>> &board, int n){
    //base case
    if(col==n){
        addSolution(board,ans,n);
        return;
    }
    //for 1st col
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]=1; 
            solve(col+1,ans,board,n); //recursion for other col
            board[row][col]=0; //backtracking
        }
    }
}

vector<vector<int>> nQueens(int n){
    vector<vector<int>> board(n, vector<int>(n,0));
    vector<vector<int>> ans;
    solve(0,ans,board,n);
    return ans;
}

void printSolution(vector<vector<int>>& solution) {
    for (const auto& row : solution) {
        for (int col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
}

int main() {
    int n ; // Size of the chessboard
    cout<<"Enter the no. of queens: ";
    cin>>n;
    vector<vector<int>> solution = nQueens(n);
    printSolution(solution);
    return 0;
}