/*DFS Traversal
Given an undirected and disconnected graph G(V, E), containing 'V' vertices and 'E' edges, the information about edges is given using 'GRAPH' matrix, where i-th edge is between GRAPH[i][0] and GRAPH[i][1]. print its DFS traversal.

V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 

E is the number of edges present in graph G.
Note :
The Graph may not be connected i.e there may exist multiple components in a graph.
https://www.naukri.com/code360/problems/dfs-traversal_630462*/
#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

void dfs( unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited,int node,vector<int> &component){

    //making the node as visited
    visited[node]=1;

    //pushing it in component
    component.push_back(node);

    //for all the nodes in adjacency list
    for(auto i:adjList[node]){

        //if not visited
        if(!visited[i]){
            dfs(adjList,visited,i,component);
        }
    }
}

vector<vector<int>> DFS(vector<pair<int,int>> &edges,int vertex,int edge){

    // int(node) list(nodes connected to it)
    unordered_map<int,list<int> > adjList;

    //iterate for all node
    for(int i=0;i<edges.size();i++){

        //retrieving from the data given
        //node1
        int u = edges[i].first;

        //node2
        int v = edges[i].second;
        
        //node1->node2
        adjList[u].push_back(v);

        //node2->node1
        adjList[v].push_back(u);
    }

    //storing the traversal
    vector<vector<int>> ans;

    //int(node) bool(visited or not)
    unordered_map<int,bool> visited;

    //now traversing for all node
    for(int i=0;i<vertex;i++){
        if(!visited[i]){

            //storing the traversal
            vector<int> component;
            dfs(adjList,visited,i,component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main() {
    vector<pair<int,int>> edges = {{0, 2}, {0, 1}, {1, 2}, {3, 4}};
    int vertex = 5;
    int edge = 4;

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