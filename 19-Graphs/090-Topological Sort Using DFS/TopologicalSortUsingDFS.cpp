/*Topological Sort
A Directed Acyclic Graph (DAG) is a directed graph that contains no cycles.

Topological Sorting of DAG is a linear ordering of vertices such that for every directed edge from vertex ‘u’ to vertex ‘v’, vertex ‘u’ comes before ‘v’ in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

Given a DAG consisting of ‘V’ vertices and ‘E’ edges, you need to find out any topological sorting of this DAG. Return an array of size ‘V’ representing the topological sort of the vertices of the given DAG.
https://www.naukri.com/code360/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar*/
#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

void topSort(int node,vector<bool>& visited,stack<int>& stk,unordered_map<int,list<int>>& adjList){

    //marking the node as visited
    visited[node]=1;

    //iterating for all the next node
    for(auto neighbours:adjList[node]){

        //if not visited then recursivly iterate it
        if(!visited[neighbours]){
            topSort(neighbours,visited,stk,adjList);
        }
    }

    //when going back push in stack
    stk.push(node);
}

vector<int> topologicalSort(vector<vector<int>>& edges,int vertex,int edge){

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
    }

    //visited array
    vector<bool> visited(vertex);

    //stack to retrieve in LIFO format
    stack<int> stk;

    //now traversing for all node
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            topSort(i,visited,stk,adjList);
        }
    }

    //to store the answer
    vector<int> ans;
    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }
    return ans;
}

int main() {
    int vertices = 6;
    int edges = 6;
    vector<vector<int>> graphEdges = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};

    vector<int> result = topologicalSort(graphEdges, vertices, edges);

    cout << "Topological sorting order: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

