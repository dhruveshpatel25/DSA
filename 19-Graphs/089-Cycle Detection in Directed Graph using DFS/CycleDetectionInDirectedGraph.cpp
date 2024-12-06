/*Detect Cycle In A Directed Graph
You are given a directed graph having ‘N’ nodes. A matrix ‘EDGES’ of size M x 2 is given which represents the ‘M’ edges such that there is an edge directed from node EDGES[i][0] to node EDGES[i][1].

Find whether the graph contains a cycle or not, return true if a cycle is present in the given directed graph else return false.
Note :
1. The cycle must contain at least two nodes.
2. It is guaranteed that the given graph has no self-loops in the graph.
3. The graph may or may not be connected.
4. Nodes are numbered from 1 to N.
5. Your solution will run on multiple test cases. If you are using global variables make sure to clear them.
https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar*/
#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

bool isCyclicDFS(int node,unordered_map<int,bool>& visited,unordered_map<int,bool>& dfsvisited,unordered_map<int,list<int>>& adjList){

    //marking it visited
    visited[node]=true;

    //marking it visited in that traversal
    dfsvisited[node]=true;
    for(auto neighbour:adjList[node]){

        //checking if next node is visited for not
        if(!visited[neighbour]){
            bool cycledetected=isCyclicDFS(neighbour,visited,dfsvisited,adjList);
            if(cycledetected){

                //if cycle detected
                return true;
            }
        }

        //checking if the next node is visited in that traversal or not
        else if(dfsvisited[neighbour]){

            //if the next node is visited in traversal so making it cycle
            return true;
        }
    }

    //after iteration making it unvisited for next traversal
    dfsvisited[node]=false;
    return false;
}

int detectCycleInDirectedGraph(int vertex,vector<pair<int,int>>& edges){

    // int(node) list(nodes connected to it)
    unordered_map<int,list<int>> adjList;

    //iterate for all node
    for(int i=0;i<edges.size();i++){

        //retrieving from the data given
        //node1
        int u = edges[i].first;

        //node2
        int v = edges[i].second;

        //node1->node2
        adjList[u].push_back(v);
    }

    //int(node) bool(visited or not)
    unordered_map<int,bool> visited;

    //int(node) bool(visited or not) it is used to check whether the node is in cycle or not of the traversal
    unordered_map<int,bool> dfsvisited;

    //now traversing for all node
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
