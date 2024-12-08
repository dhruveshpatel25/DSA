/*Articulation Points Using Tarjan's Algorithm
Given an undirected graph G, find all the articulation points in the graph.

For a connected undirected graph, an articulation point or a cut vertex is a vertex in the graph removing which disconnects the graph.
 
For a disconnected undirected graph, an articulation point or a cut vertex is a vertex removing which increases the number of connected components.
https://www.naukri.com/code360/library/articulation-points-in-a-graph*/
#include <bits/stdc++.h>
using namespace std;

void dfs(int node,int parent,int &timer,vector<int>& discovery,vector<int>& low, vector<int>& ans,unordered_map<int,list<int> > &adjList,unordered_map<int,bool>& visited){

    //we make the node visited
    visited[node]=true;

    //we update the low and discovery to the timer
    discovery[node]=low[node]=timer++;

    //used for edge case when the start node is the articulation point
    int child=0;

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

            //if we remove the node then it forms two different graph as there would be no way to reach the neighbour
            if(low[neighbour]>=discovery[node] && parent!=-1){

                //marking for node in answer array as true
                ans[node]=1;
            }

            //speacially for the edge case
            child++;
        }
        //backedge case-as we got a optimal way to reach that node so we find the optimal way to reach by updating with the discovery of neighbour
        else{
            low[node]=min(low[node],discovery[neighbour]);
        }
    }

    //checking for starting node
    if(parent==-1 && child>1){
        
        //marking for node in answer array as true
        ans[node]=1;
    }
}
vector<int> FindArticulationPoints(vector<vector<int>> &graph, int vertex, int edges){
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

    vector<int> ans(vertex,0);

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

    // Find articulation points
    vector<int> articulationPoints = FindArticulationPoints(graph, V, E);

    // Output articulation points
    cout << "Articulation points in the graph are:" << endl;
    for (int i = 0; i < articulationPoints.size(); i++) {
        if (articulationPoints[i]) {
            cout << i << endl;
        }
    }

    return 0;
}
