#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

bool isCyclicDFS(int node,unordered_map<int,bool>& visited,unordered_map<int,bool>& dfsvisited,unordered_map<int,list<int>>& adjList){
    visited[node]=true;
    dfsvisited[node]=true;
    for(auto neighbour:adjList[node]){
        if(!visited[neighbour]){
            bool cycledetected=isCyclicDFS(neighbour,visited,dfsvisited,adjList);
            if(cycledetected){
                return true;
            }
        }
        else if(dfsvisited[neighbour]){
            return true;
        }
    }
    dfsvisited[node]=false;
    return false;
}

int detectCycleInDirectedGraph(int vertex,vector<pair<int,int>>& edges){
    unordered_map<int,list<int>> adjList;
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
    }

    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsvisited;
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bool ans=isCyclicDFS(i,visited,dfsvisited,adjList);
            if(ans==1){
                return true;
            }else{
                return false;
            }
        }
    }
}

int main() {
    int vertices = 5; // Number of vertices in the graph
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {2, 4}}; // Example edges
    
    if (detectCycleInDirectedGraph(vertices, edges)) {
        cout << "Graph contains a cycle." << endl;
    } else {
        cout << "Graph does not contain a cycle." << endl;
    }
    
    return 0;
}
