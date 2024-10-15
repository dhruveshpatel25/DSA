#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

bool isCyclicBFS(int src,unordered_map<int,bool>& visited,unordered_map<int,list<int>>& adjList){
    unordered_map<int,int> parent;
    parent[src]=-1;
    visited[src]=1;
    queue<int> que;
    que.push(src);

    while(!que.empty()){
        int front = que.front();
        que.pop();
        for(auto neighbour: adjList[front]){
            if(visited[neighbour]==true && neighbour!=parent[front]){
                return true;
            }
            else if(!visited[neighbour]){
                que.push(neighbour);
                visited[neighbour]=1;
                parent[neighbour]=front;
            }
        }
    }
    return false;
}

string cyclicDetection(vector<vector<int>> &edges,int vertex, int edge){
    unordered_map<int,list<int>> adjList;
    for(int i=0;i<edge;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    unordered_map<int,bool> visited;
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bool ans=isCyclicBFS(i,visited,adjList);
            if(ans==1){
                return"Yes";
            }else{
                return"No";
            }
        }
    }
}

int main() {
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    int vertex = 3;
    int edge = 3;

    string result = cyclicDetection(edges, vertex, edge);
    cout << "Graph contains cycle? " << result << endl;

    return 0;
}
