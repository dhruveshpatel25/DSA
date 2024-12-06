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

vector<int> topologicalSort(vector<vector<int>>& edges,int vertex,int edge){

    //int(node) list(nodes connected to it)
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
    vector<int> ans;
    //removing the 0 degree elements and decresing the indegrees of it's neighbours
    while(!que.empty()){
        int front=que.front();
        que.pop();
        ans.push_back(front);
        for(auto neighbours:adjList[front]){
            indegrees[neighbours]--;
            if(indegrees[neighbours]==0){
                que.push(neighbours);
            }
        }
    }
    return ans;
}

int main() {
    // Sample input
    int vertex = 6; // Number of vertices
    int edge = 6;   // Number of edges
    vector<vector<int>> edges = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};

    // Call topologicalSort function
    vector<int> result = topologicalSort(edges, vertex, edge);

    // Output the result
    cout << "Topological order: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
