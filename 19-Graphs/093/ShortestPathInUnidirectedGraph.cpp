#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int,int>> edges,int vertex, int edge,int src,int dest){
    unordered_map<int,list<int>> adjList;
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
    }

    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    queue<int> que;
    que.push(src);
    visited[src]=true;
    parent[src]=-1;
    while(!que.empty()){
        int front = que.front();
        que.pop();
        for(auto neighbours:adjList[front]){
            if(!visited[neighbours]){
                visited[neighbours]=true;
                parent[neighbours]=front;
                que.push(neighbours);
            }
        }
    }

    //shortest path
    vector<int> ans;
    int currentNode=dest;
    ans.push_back(dest);
    while(currentNode!=src){
        currentNode=parent[currentNode];
        ans.push_back(currentNode);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    vector<pair<int, int>> edgeList(edges);
    cout << "Enter the edges (format: source destination):" << endl;
    for (int i = 0; i < edges; ++i) {
        cin >> edgeList[i].first >> edgeList[i].second;
    }

    int source, destination;
    cout << "Enter source and destination vertices: ";
    cin >> source >> destination;

    vector<int> shortest = shortestPath(edgeList, vertices, edges, source, destination);

    cout << "Shortest path from " << source << " to " << destination << " is: ";
    for (int vertex : shortest) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}