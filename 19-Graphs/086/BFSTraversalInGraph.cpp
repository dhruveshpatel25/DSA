#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

void prepareAdjlist(unordered_map<int, list<int>> &adjList, vector<pair<int,int>> &edges){
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void bfs(unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited,vector<int> &ans,int node){
    queue<int> que;
    que.push(node);
    visited[node]=1;

    while(!que.empty()){
        int frontNode=que.front();
        que.pop();
        ans.push_back(frontNode);
        for(auto i:adjList[frontNode]){
            if(!visited[i]){
                que.push(i);
                visited[i]=1;
            }
        }
    }
}

vector<int> BFS(vector<pair<int,int>> edges,int vertex){
    unordered_map<int,list<int> > adjList;
    vector<int> ans;
    unordered_map<int,bool> visited;

    prepareAdjlist(adjList,edges);

    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i);
        }
    }
    return ans;
}

int main() {
    vector<pair<int,int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}, {3, 4}, {4, 5}};
    int vertex = 6; // Number of vertices in the graph

    vector<int> traversal = BFS(edges, vertex);

    cout << "BFS Traversal: ";
    for (int node : traversal) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
