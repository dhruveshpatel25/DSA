#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

vector<int> topologicalSort(vector<vector<int>>& edges,int vertex,int edge){
    unordered_map<int,list<int>> adjList;
    for(int i=0;i<edge;i++){
        int u = edges[i][0];
        int v = edges[i][1];

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
