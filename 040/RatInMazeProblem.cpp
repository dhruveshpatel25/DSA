#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool issafe(int newx, int newy,vector<vector<int>> &m,vector<vector<int>> visited,int n,int p){
    if((newx>=0 && newx<p) && (newy>=0 && newy<n) && visited[newx][newy]==0 && m[newx][newy]==1){
        return true;
    }else{
        return false;
    }
}

void solve(vector<vector<int>>& m,int srcx, int srcy, vector<vector<int>> visited,vector<string>& ans,int n,string path,int p){
    if(srcx==p-1 && srcy==n-1){
        ans.push_back(path);
        return;
    }

    visited[srcx][srcy]=1;

    //Down
    int newx=srcx+1;
    int newy= srcy;
    if(issafe(newx,newy,m,visited,n,p)){
        path.push_back('D');
        solve(m,newx,newy,visited,ans,n,path,p);
        path.pop_back();
    }
    
    //Left
    newx=srcx;
    newy= srcy-1;
    if(issafe(newx,newy,m,visited,n,p)){
        path.push_back('L');
        solve(m,newx,newy,visited,ans,n,path,p);
        path.pop_back();
    }

    //Top
    newx=srcx-1;
    newy= srcy;
    if(issafe(newx,newy,m,visited,n,p)){
        path.push_back('T');
        solve(m,newx,newy,visited,ans,n,path,p);
        path.pop_back();
    }

    //Right
    newx=srcx;
    newy= srcy+1;
    if(issafe(newx,newy,m,visited,n,p)){
        path.push_back('R');
        solve(m,newx,newy,visited,ans,n,path,p);
        path.pop_back();
    }
    visited[srcx][srcy]=0;
}

vector<string> path(vector<vector<int>>& m, int n,int p){
    vector<string> ans;
    if(m[0][0]==0){
        return ans;
    }

    int srcx=0;
    int srcy=0;

    vector<vector<int>> visited = m;
    for(int i=0;i<p;i++){
        for(int j=0;j<n;j++){
            visited[i][j]=0;
        }
    }
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
