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
https://www.naukri.com/code360/problems/rat-in-a-maze_1215030*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//check if the condition to move is safe or not
bool issafe(int newx, int newy,vector<vector<int>> &m,vector<vector<int>> visited,int n,int p){

    //check if the new box is within the maze
    //check if visited box has 0(so no loop)
    //check if the box in maze has 1 so we can move
    if((newx>=0 && newx<p) && (newy>=0 && newy<n) && visited[newx][newy]==0 && m[newx][newy]==1){
        return true;
    }else{
        return false;
    }
}

//solve the maze
void solve(vector<vector<int>>& m,int srcx, int srcy, vector<vector<int>> visited,vector<string>& ans,int n,string path,int p){

    //base condition-when it reaches the destination box
    if(srcx==p-1 && srcy==n-1){
        ans.push_back(path);
        return;
    }

    //make the current box in visited as 1
    visited[srcx][srcy]=1;

    //Down
    int newx=srcx+1;
    int newy= srcy;

    //check if it is possible to make move
    if(issafe(newx,newy,m,visited,n,p)){
        path.push_back('D');

        //recursivly iterating for moves ahead
        solve(m,newx,newy,visited,ans,n,path,p);
        path.pop_back();
    }
    
    //Left
    newx=srcx;
    newy= srcy-1;

    //check if it is possible to make move
    if(issafe(newx,newy,m,visited,n,p)){
        path.push_back('L');

        //recursivly iterating for moves ahead
        solve(m,newx,newy,visited,ans,n,path,p);
        path.pop_back();
    }

    //Top
    newx=srcx-1;
    newy= srcy;

    //check if it is possible to make move
    if(issafe(newx,newy,m,visited,n,p)){
        path.push_back('T');

        //recursivly iterating for moves ahead
        solve(m,newx,newy,visited,ans,n,path,p);
        path.pop_back();
    }

    //Right
    newx=srcx;
    newy= srcy+1;

    //check if it is possible to make move
    if(issafe(newx,newy,m,visited,n,p)){
        path.push_back('R');

        //recursivly iterating for moves ahead
        solve(m,newx,newy,visited,ans,n,path,p);
        path.pop_back();
    }

    //backtracking-make visited box of the visited 0 so making it unvisited
    visited[srcx][srcy]=0;
}

vector<string> path(vector<vector<int>>& m, int n,int p){

    //ans array to store all tracks
    vector<string> ans;

    //if source is 0
    if(m[0][0]==0){
        return ans;
    }

    int srcx=0;
    int srcy=0;

    //vector same as map for storing the visited entry
    vector<vector<int>> visited = m;
    for(int i=0;i<p;i++){
        for(int j=0;j<n;j++){
            visited[i][j]=0;
        }
    }

    //to store path in each iteration
    string path="";
    solve(m,srcx,srcy,visited,ans,n,path,p);
    return ans;
}

int main() {

    vector<vector<int>> m = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1,}
    };
    int n = m[0].size();
    int p = m.size();
    vector<string> paths = path(m, n,p);
    if(paths.empty()) {
        cout << "No paths found." << endl;
    } else {
        cout << "Paths found:" << endl;
        for(const string& path : paths) {
            cout << path << endl;
        }
    }
    return 0;
}
