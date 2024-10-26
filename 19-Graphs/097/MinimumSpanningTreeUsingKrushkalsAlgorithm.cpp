#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a,vector<int> &b){
    return a[2]<b[2];
}

void makeSet(vector<int> &parent,vector<int> &rank,int vertex){
    for(int i=0;i<vertex;i++){
        parent[i]=i;
        rank[i]=0;
    }
}

int findParent(vector<int> &parent,int vertex){
    if(parent[vertex]==vertex){
        return vertex;
    }
    return parent[vertex]=findParent(parent,parent[vertex]);
}

void unionSet(int u,int v,vector<int> &parent,vector<int> &rank){
    u=findParent(parent,u);
    v=findParent(parent,v);
    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[v]<rank[u]){
        parent[v]=u;
    }else{
        parent[v]=u;
        rank[u]++;
    }
}

int minispanningKrushkal(vector<vector<int>> &edges,int vertex){
    sort(edges.begin(),edges.end(),cmp);
    vector<int> parent(vertex);
    vector<int> rank(vertex);
    makeSet(parent,rank,vertex);

    int minWeight=0;

    for(int i=0;i<edges.size();i++){
        int u=findParent(parent,edges[i][0]);
        int v=findParent(parent,edges[i][1]);
        int wt=edges[i][2];

        if(u!=v){
            minWeight+=wt;
            unionSet(u,v,parent,rank);
        }
    }
    return minWeight;
}

int main() {
    // Example usage
    int vertex = 4; // Number of vertices
    vector<vector<int>> edges = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};
    // Each edge is represented as {source, destination, weight}

    int minWeight = minispanningKrushkal(edges, vertex);
    cout << "Minimum spanning tree weight: " << minWeight << endl;

    return 0;
}
