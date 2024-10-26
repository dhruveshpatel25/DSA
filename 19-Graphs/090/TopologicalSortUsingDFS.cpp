#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

void topSort(int node,vector<bool>& visited,stack<int>& stk,unordered_map<int,list<int>>& adjList){
    visited[node]=1;
    for(auto neighbours:adjList[node]){
        if(!visited[neighbours]){
            topSort(neighbours,visited,stk,adjList);
        }
    }
    stk.push(node);
}

vector<int> topologicalSort(vector<vector<int>>& edges,int vertex,int edge){
    unordered_map<int,list<int>> adjList;
    for(int i=0;i<edge;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }
    vector<bool> visited(vertex);
    stack<int> stk;
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            topSort(i,visited,stk,adjList);
        }
    }
    vector<int> ans;
    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }
    return ans;
}

int main() {
    int vertices = 6;
    int edges = 6;
    vector<vector<int>> graphEdges = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};

    vector<int> result = topologicalSort(graphEdges, vertices, edges);

    cout << "Topological sorting order: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

