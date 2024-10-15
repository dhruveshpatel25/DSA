#include<iostream>
#include<vector>
using namespace std;

//check if the condition to move is safe or not
bool isSafe(int newX,int newY,vector<vector<bool>>& visited,vector<vector<int>>&arr,int n){
    if((newX>=0 && newX<n) && (newY>=0 && newY<n) && visited[newX][newY]!=1 && arr[newX][newY]!=0){
        return true;
    }
    else{
        return false;
    }
}

//solve the maze
void solve(int x,int y,vector<vector<int>>&arr,int n,vector<string>& ans,vector<vector<bool>>& visited,string path){
    //base condition
    if(x==n-1 && y==n-1){
        ans.push_back(path);
    }

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
    visited[x][y]=0;    
}

vector<string> searchMaze(vector<vector<int>>&arr,int n){
    vector<string> ans;
    vector<vector<bool>> visited(n,vector<bool>(n,0));
    string path="";
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