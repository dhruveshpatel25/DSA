/*/*Cycle Detection In Undirected Graph Using DFS
You have been given an undirected graph with 'N' vertices and 'M' edges. The vertices are labelled from 1 to 'N'.

Your task is to find if the graph contains a cycle or not.

A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called a cycle.Note:

1. There are no parallel edges between two vertices.

2. There are no self-loops(an edge connecting the vertex to itself) in the graph.

3. The graph can be disconnected.
For Example :

Input: N = 3 , Edges =  [[1, 2], [2, 3], [1, 3]].
Output: Yes

Explanation : There are a total of 3 vertices in the graph. There is an edge between vertex 1 and 2, vertex 2 and 3 and vertex 1 and 3. So, there exists a cycle in the graph. 
https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670*/
#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

bool isCyclicDFS(int node,int parent, unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adjList){

    //marking it visited
    visited[node]=true;
    for(auto neighbour:adjList[node]){

        //checking for all the non-visted nodes
        if(!visited[node]){
            bool cycledetected=isCyclicDFS(neighbour,node,visited,adjList);
            if(cycledetected){

                //if cycle detected
                return true;
            }
        }

        //check if next node is not parent
        else if(neighbour!=parent){

            //if next node is not parent cycle detected
            return true;
        }
    }

    //if cycle not found
    return false;
}
string cyclicDetection(vector<vector<int>> &edges,int vertex, int edge){

    // int(node) list(nodes connected to it)
    unordered_map<int,list<int>> adjList;

    //iterate for all node
    for(int i=0;i<edge;i++){

        //retrieving from the data given
        //node1
        int u = edges[i][0];

        //node2
        int v = edges[i][1];

        //node1->node2
        adjList[u].push_back(v);

        //node2->node1
        adjList[v].push_back(u);
    }

    //int(node) bool(visited or not)
    unordered_map<int,bool> visited;

    //now traversing for all node
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bool ans=isCyclicDFS(i,-1,visited,adjList);
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
