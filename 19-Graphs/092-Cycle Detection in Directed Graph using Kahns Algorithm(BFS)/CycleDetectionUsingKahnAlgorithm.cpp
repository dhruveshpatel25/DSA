/*/*Detect Cycle In A Directed Graph
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

int detectCycleInDirectedGraph(int vertex,vector<pair<int,int>>& edges){

    //int(node) list(nodes connected to it)
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

    //to calculate indegrees of each node
    vector<int> indegrees(vertex);

    //getting the value of indegrees
    for(auto i:adjList){
        for(auto j:i.second){
            indegrees[j]++;
        }
    }   

    queue<int> que;
    //pushing the elements with 0 indegrees
    for(int i=0;i<vertex;i++){
        if(indegrees[i]==0){
            que.push(i);
        }
    }
    int count=0;
    //removing the 0 degree elements and decresing the indegrees of it's neighbours
    while(!que.empty()){
        int front=que.front();
        que.pop();
        count++;
        for(auto neighbours:adjList[front]){
            indegrees[neighbours]--;
            if(indegrees[neighbours]==0){
                que.push(neighbours);
            }
        }
    }

    //if the no.of nodes counted in queue is more then it means we counted a node more than 1 meaning cycle was present
    if(count==vertex){
        return false; //cycle is not present
    }else{
        return true; //cycle is present
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