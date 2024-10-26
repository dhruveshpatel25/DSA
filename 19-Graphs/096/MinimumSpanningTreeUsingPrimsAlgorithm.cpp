#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int,int>,int>> Prim(int vertex,int edges,vector<pair<pair<int,int>,int>> &graph){
    unordered_map<int,list<pair<int,int>>> adjList;
    for(int i=0;i<graph.size();i++){
        int u=graph[i].first.first; //first node
        int v=graph[i].first.second; //second node
        int w=graph[i].second;  //weight

        adjList[u].push_back(make_pair(v,w));
        adjList[v].push_back(make_pair(u,w));
    }

    vector<int> key(vertex+1);
    vector<bool> mst(vertex+1);
    vector<int> parent(vertex+1);

    for(int i=0;i<=vertex;i++){
        key[i]=INT_MAX;
        parent[i]=-1;
        mst[i]=false;
    }

    key[1]=0;
    parent[1]=-1;
    for(int i=0;i<=vertex;i++){
        int mini=INT_MAX;
        int u;
        for(int v=1;v<=vertex;v++){
            if(mst[v]==false && key[v]<mini){
                u=v;
                mini=key[v];
            }
        }
        mst[u]=true;
        for(auto it:adjList[u]){
            int v=it.first;
            int w=it.second;
            if(mst[v]==false && w<key[v]){
                parent[v]=u;
                key[v]=w;
            }
        }
    }
    vector<pair<pair<int,int>,int>> ans;
    for(int i=2;i<=vertex;i++){
        ans.push_back({{parent[i],i},key[i]});
    }
    return ans;
}

int main() {
    int vertex = 5;
    int edges = 14; // Number of edges
    vector<pair<pair<int,int>,int>> graph; // { {start node, end node}, weight }

    // Add edges to the graph
    graph.push_back({{1, 2}, 2});
    graph.push_back({{1, 4}, 6});
    graph.push_back({{2, 1}, 2});
    graph.push_back({{2, 3}, 3});
    graph.push_back({{2, 4}, 8});
    graph.push_back({{2, 5}, 5});
    graph.push_back({{3, 2}, 3});
    graph.push_back({{3, 5}, 7});
    graph.push_back({{4, 1}, 6});
    graph.push_back({{4, 2}, 8});
    graph.push_back({{4, 5}, 9});
    graph.push_back({{5, 2}, 5});
    graph.push_back({{5, 3}, 7});
    graph.push_back({{5, 4}, 9});

    // Call Prim's algorithm
    vector<pair<pair<int,int>,int>> result = Prim(vertex, edges, graph);

    // Print the Minimum Spanning Tree (MST)
    cout << "Minimum Spanning Tree Edges:\n";
    for(auto edge : result) {
        cout << edge.first.first << " - " << edge.first.second << " : " << edge.second << endl;
    }

    return 0;
}