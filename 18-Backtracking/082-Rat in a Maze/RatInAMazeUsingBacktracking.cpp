/*Rat In A Maze
You are given a starting position for a rat which is stuck in a maze at an initial point (0, 0) (the maze can be thought of as a 2-dimensional plane). The maze would be given in the form of a square matrix of order 'N' * 'N' where the cells with value 0 represent the maze’s blocked locations while value 1 is the open/available path that the rat can take to reach its destination. The rat's destination is at ('N' - 1, 'N' - 1). Your task is to find all the possible paths that the rat can take to reach from source to destination in the maze. The possible directions that it can take to move in the maze are 'U'(up) i.e. (x, y - 1) , 'D'(down) i.e. (x, y + 1) , 'L' (left) i.e. (x - 1, y), 'R' (right) i.e. (x + 1, y).

Note:
Here, sorted paths mean that the expected output should be in alphabetical order.
For Example:
Given a square matrix of size 4*4 (i.e. here 'N' = 4):
1 0 0 0
1 1 0 0
1 1 0 0
0 1 1 1 
Expected Output:
DDRDRR DRDDRR 
i.e. Path-1: DDRDRR and Path-2: DRDDRR

The rat can reach the destination at (3, 3) from (0, 0) by two paths, i.e. DRDDRR and DDRDRR when printed in sorted order, we get DDRDRR DRDDRR.
https://www.naukri.com/code360/problems/rat-in-a-maze_1215030?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar*/
#include<iostream>
#include<vector>
using namespace std;

//check if the condition to move is safe or not
bool isSafe(int newX,int newY,vector<vector<bool>>& visited,vector<vector<int>>&arr,int n){

    //check if the new box is within the maze
    //check if visited box has 0(so no loop)
    //check if the box in maze has 1 so we can move
    if((newX>=0 && newX<n) && (newY>=0 && newY<n) && visited[newX][newY]!=1 && arr[newX][newY]!=0){
        return true;
    }else{
        return false;
    }
}

//solve the maze
void solve(int x,int y,vector<vector<int>>&arr,int n,vector<string>& ans,vector<vector<bool>>& visited,string path){

    //base condition-when it reaches the destination box
    if(x==n-1 && y==n-1){
        ans.push_back(path);
    }

    //make the current box in visited as 1
    visited[x][y]=1;
    //Down
    if(isSafe(x+1,y,visited,arr,n)){
        solve(x+1,y,arr,n,ans,visited,path+'D');
    }

    //Left
    if(isSafe(x,y-1,visited,arr,n)){
        solve(x,y-1,arr,n,ans,visited,path+'L');
    }

    //Right
    if(isSafe(x,y+1,visited,arr,n)){
        solve(x,y+1,arr,n,ans,visited,path+'R');
    }

    //Up
    if(isSafe(x-1,y,visited,arr,n)){
        solve(x-1,y,arr,n,ans,visited,path+'U');
    }

    //make visited box of the visited 0 so making it unvisited
    visited[x][y]=0;    
}

vector<string> searchMaze(vector<vector<int>>&arr,int n){

    //ans array to store all tracks
    vector<string> ans;

    //vector same as map for storing the visited entry
    vector<vector<bool>> visited(n,vector<bool>(n,0));

    //to store path in each iteration
    string path="";

    //if source is 0
    if(arr[0][0]==0){
        return ans;
    }
    solve(0,0,arr,n,ans,visited,path);
    return ans;
}

int main() {
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};
    int n = maze.size();
    vector<string> paths = searchMaze(maze, n);
    
    if (paths.empty()) {
        cout << "No path found!" << endl;
    } else {
        cout << "Paths found:" << endl;
        for (const string& path : paths) {
            cout << path << endl;
        }
    }
    
    return 0;
}