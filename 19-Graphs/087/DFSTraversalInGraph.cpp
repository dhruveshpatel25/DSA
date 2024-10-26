#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

void dfs( unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited,int node,vector<int> &component){
    visited[node]=1;
    component.push_back(node);

    for(auto i:adjList[node]){
        if(!visited[i]){
            dfs(adjList,visited,i,component);
        }
    }
}

vector<vector<int>> DFS(vector<pair<int,int>> &edges,int vertex,int edge){
    unordered_map<int,list<int> > adjList;
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int,bool> visited;
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(adjList,visited,i,component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main() {
    vector<pair<int,int>> edges = {{5, 4}, {0, 2}, {0, 1}, {1, 2}, {3, 4}};
    int vertex = 6;
    int edge = 5;

    vector<vector<int>> components = DFS(edges, vertex, edge);

    cout << "Connected Components:\n";
    for (int i = 0; i < components.size(); ++i) {
        cout << "Component " << i+1 << ": ";
        for (int j = 0; j < components[i].size(); ++j) {
            cout << components[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}