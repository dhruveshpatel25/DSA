/*Count Strongly Connected Components (Kosaraju’s Algorithm)
You are given an unweighted directed graph having 'V' vertices and 'E' edges. Your task is to count the number of strongly connected components (SCCs) present in the graph.

A directed graph is said to be strongly connected if every vertex is reachable from every other vertex. The strongly connected components of a graph are the subgraphs which are themselves strongly connected.

Note :
Use zero-based indexing for the vertices.
The given graph doesn’t contain any self-loops.
https://www.naukri.com/code360/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar*/
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int,bool>& visited,stack<int>& stk,unordered_map<int,list<int> >& adjList){

    //mark the node as visited
    visited[node]=true;

    //iterate for all the neighbour of the node
    for(auto neighbour:adjList[node]){
        if(!visited[neighbour]){

            //recursivly call for its neighbour of the node
            dfs(neighbour,visited,stk,adjList);
        }
    }

    //when reached the last node-push it in stack (backtracking)
    stk.push(node);
}

void revDfs(int node,unordered_map<int,bool>& visited,unordered_map<int,list<int> >& transpose){

    //mark the node as visited
    visited[node]=true;

    //iterate for all the neighbour of the node
    for(auto neighbour:transpose[node]){
        if(!visited[neighbour]){

            //recursivly call for its neighbour of the node
            revDfs(neighbour,visited,transpose);
        }
    }
}

int stronglyConnectedComponents(int vertex, vector<vector<int>> &graph){
    //int(node) int(next node) int(weight)
    unordered_map<int,list<int> > adjList;
    for(int i=0;i<graph.size();i++){

        //first node
        int u=graph[i][0]; 

        //second node
        int v=graph[i][1];

        //node1->node2
        adjList[u].push_back(v);
    }

    //topological sort

    //stack to store from last node
    stack<int> stk;

    //for checking if the node is visited for not
    unordered_map<int,bool> visited;
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            dfs(i,visited,stk,adjList);
        }
    }

    //transpose of graph
    unordered_map<int,list<int>> transpose;
    for(int i=0;i<vertex;i++){

        //making the visited for all nodees false again
        visited[i]=0;

        //making the arrow reverse
        for(auto neighbour:adjList[i]){
            transpose[neighbour].push_back(i);
        }
    }

    //dfs call after new graph
    int count=0;
    while(!stk.empty()){
        int top=stk.top();
        stk.pop();
        if(!visited[top]){

            //whenever a unvisited node is found then increase the counter so we one component is counted
            count++;
            revDfs(top,visited,transpose);
        }
    }
    return count;
}

int main() {
    // Input number of vertices and edges
    int V, E;
    cout << "Enter the number of vertices (V) and edges (E): ";
    cin >> V >> E;

    // Input edges
    vector<vector<int>> graph;
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph.push_back({u, v});
    }

    // Find the number of strongly connected components
    int sccCount = stronglyConnectedComponents(V, graph);

    // Output result
    cout << "The number of strongly connected components is: " << sccCount << endl;

    return 0;
}
