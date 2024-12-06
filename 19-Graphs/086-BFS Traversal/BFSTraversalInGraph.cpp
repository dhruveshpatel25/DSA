/*BFS in Graph
Problem statement
Given an adjacency list representation of a directed graph with ‘n’ vertices and ‘m’ edges. Your task is to return a list consisting of Breadth-First Traversal (BFS) starting from vertex 0.



In this traversal, one can move from vertex 'u' to vertex 'v' only if there is an edge from 'u' to 'v'. The BFS traversal should include all nodes directly or indirectly connected to vertex 0.



Note:
The traversal should proceed from left to right according to the input adjacency list.


Example:
Adjacency list: { {1,2,3},{4}, {5}, {},{},{}}

The interpretation of this adjacency list is as follows:
Vertex 0 has directed edges towards vertices 1, 2, and 3.
Vertex 1 has a directed edge towards vertex 4.
Vertex 2 has a directed edge towards vertex 5.
Vertices 3, 4, and 5 have no outgoing edges.

We can also see this in the diagram below.

BFS traversal: 0 1 2 3 4 5
https://www.naukri.com/code360/problems/bfs-in-graph_973002?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar*/
#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

void prepareAdjlist(unordered_map<int, list<int>> &adjList, vector<pair<int,int>> &edges){

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
}

void bfs(unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited,vector<int> &ans,int node){

    //queue for retrieving node in FIFO format
    queue<int> que;
    que.push(node);

    //marking the node as visited
    visited[node]=1;

    while(!que.empty()){
        int frontNode=que.front();
        que.pop();
        ans.push_back(frontNode);

        //checking for all the nodes connected in frontnode
        for(auto i:adjList[frontNode]){

            //if not visited
            if(!visited[i]){

                //push in queue
                que.push(i);

                //mark it visited
                visited[i]=1;
            }
        }
    }
}

vector<int> BFS(vector<pair<int,int>> edges,int vertex){

    // int(node) list(nodes connected to it)
    unordered_map<int,list<int> > adjList;

    //storing the traversal
    vector<int> ans;

    //int(node) bool(visited or not)
    unordered_map<int,bool> visited;

    //prepare adjancency list for all node
    prepareAdjlist(adjList,edges);

    //now traversing for all node
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i);
        }
    }
    return ans;
}

int main() {
    vector<pair<int,int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}, {3, 4}, {4, 5}};
    int vertex = 6; // Number of vertices in the graph

    vector<int> traversal = BFS(edges, vertex);

    cout << "BFS Traversal: ";
    for (int node : traversal) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
