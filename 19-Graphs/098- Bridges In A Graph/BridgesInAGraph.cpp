/*Bridges In A Graph
Given an undirected graph of V vertices and E edges. Your task is to find all the bridges in the given undirected graph. A bridge in any graph is defined as an edge which, when removed, makes the graph disconnected (or more precisely, increases the number of connected components in the graph).
https://www.naukri.com/code360/problems/bridges-in-graph_893026?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar*/
#include <bits/stdc++.h>
using namespace std;
void dfs(int node,int parent,int &timer,vector<int>& discovery,vector<int>& low, vector<vector<int>>& ans,unordered_map<int,list<int> > &adjList,unordered_map<int,bool>& visited){

    //we make the node visited
    visited[node]=true;

    //we update the low and discovery to the timer
    discovery[node]=low[node]=timer++;

    //now we iterate for the next nodes
    for(auto neighbour:adjList[node]){

        //if the next node is parent node skip the iteration
        if(neighbour == parent){
            continue;
        }

        //if it is non-visited node
        if(!visited[neighbour]){

            //recursivly iterate to the next node of this particular node
            dfs(neighbour,node,timer,discovery,low,ans,adjList,visited);

            //when backtracking check for the node whether there is back edge of any child node
            low[node]=min(low[node],low[neighbour]);

            //check whether the child node can be a bridge
            if(low[neighbour]>discovery[node]){

                //it is a bridge then push it in result
                vector<int> result;
                result.push_back(node);
                result.push_back(neighbour);

                //push the result in answer
                ans.push_back(result);
            }
        }

        //backedge case-update the low of the node because we can trace back to neigbour without intermediatry
        else{
            low[node]=min(low[node],discovery[neighbour]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &graph, int vertex, int edges){
    //int(node) int(next node) int(weight)
    unordered_map<int,list<int> > adjList;
    for(int i=0;i<graph.size();i++){

        //first node
        int u=graph[i][0]; 

        //second node
        int v=graph[i][1];

        //node1->node2
        adjList[u].push_back(v);

        //node2->node1
        adjList[v].push_back(u);
    }

    int timer=0;

    //to store when the node was discovered in the with the help of timer
    vector<int> discovery(vertex);

    //to store the lowest time to reach that node
    vector<int> low(vertex);
    int parent=-1;

    //int(bool) bool(visited or not) to store whether they are visited
    unordered_map<int,bool> visited;

    //for all nodes
    for(int i=0;i<vertex;i++){

        //make the discovery array of all nodes to -1
        discovery[i]=-1;

        //make the low array of all nodes to -1
        low[i]=-1;
    }

    vector<vector<int>> ans;

    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            dfs(i,parent,timer,discovery,low,ans,adjList,visited);
        }
    }
    return ans;
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

    // Find bridges
    vector<vector<int>> bridges = findBridges(graph, V, E);

    // Output results
    cout << "Bridges in the graph are:" << endl;
    for (auto bridge : bridges) {
        cout << bridge[0] << " - " << bridge[1] << endl;
    }

    return 0;
}
