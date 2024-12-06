/*Cycle Detection In Undirected Graph Using BFS
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
https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar*/
#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

bool isCyclicBFS(int src,unordered_map<int,bool>& visited,unordered_map<int,list<int>>& adjList){

    //int(node) int(parent node)
    unordered_map<int,int> parent;

    //starting with the first node and storing its parent as -1
    parent[src]=-1;

    //marking it visited
    visited[src]=1;

    //for FIFO retrieval(BFS)
    queue<int> que;
    que.push(src);

    while(!que.empty()){
        int front = que.front();
        que.pop();
        for(auto neighbour: adjList[front]){

            //checking if the next node is visited and checking the next node is not parent node to avoid false parent looping
            if(visited[neighbour]==true && neighbour!=parent[front]){
                return true;
            }

            //if next node is not visited
            else if(!visited[neighbour]){

                //push the node in queue
                que.push(neighbour);

                //mark it visited
                visited[neighbour]=1;

                //and make the node as parent of next node
                parent[neighbour]=front;
            }
        }
    }
    //return false if no cycle
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
            bool ans=isCyclicBFS(i,visited,adjList);
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
