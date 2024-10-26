#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

int detectCycleInDirectedGraph(int vertex,vector<pair<int,int>>& edges){
    unordered_map<int,list<int>> adjList;
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first -1;
        int v = edges[i].second -1;

        adjList[u].push_back(v);
    }

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