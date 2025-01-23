/*Minimum Spanning Tree Using Kruskal Algorithm
You are given an undirected, connected and weighted graph G(V, E), consisting of V number of vertices (numbered from 0 to V-1) and E number of edges.

Find and print the total weight of the Minimum Spanning Tree (MST) using Kruskal's algorithm.

By definition, a minimum weight spanning tree is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices together, without any cycles and with the minimum possible total edge weight.
https://www.naukri.com/code360/problems/minimum-spanning-tree_631769*/
#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a,vector<int> &b){
    return a[2]<b[2];
}

void makeSet(vector<int> &parent,vector<int> &rank,int vertex){
    for(int i=0;i<vertex;i++){

        //the parent of each node will be itself
        parent[i]=i;

        //the rank of each node will be 0
        rank[i]=0;
    }
}

int findParent(vector<int> &parent,int vertex){

    //root node of that particular tree
    if(parent[vertex]==vertex){
        return vertex;
    }

    //recursivly call for parent above to find the root
    //and also path compresion so the nodes below will always always point to the root making it faster
    return parent[vertex]=findParent(parent,parent[vertex]);
}

void unionSet(int u,int v,vector<int> &parent,vector<int> &rank){

    //find the parent of the first node
    u=findParent(parent,u);

    //find the parent of the second node
    v=findParent(parent,v);

    //check the rank of both node
    if(rank[u]<rank[v]){

        //second node has higher rank so second node becomes parent of first node
        parent[u]=v;
    }
    else if(rank[v]<rank[u]){

        //first node has higher rank so first node becomes parent of second node
        parent[v]=u;
    }else{

        //if they are same
        //make anyone the parent
        parent[v]=u;

        //and increase the rank of that particular parent node
        rank[u]++;
    }
}

int minispanningKrushkal(vector<vector<int>> &edges,int vertex){

    //arrange the edges on basis of their weight
    sort(edges.begin(),edges.end(),cmp);

    //parent array to store parent of each node
    vector<int> parent(vertex);

    //rank array to store rank of each node
    vector<int> rank(vertex);
    makeSet(parent,rank,vertex);

    int minWeight=0;

    for(int i=0;i<edges.size();i++){

        //find the parents of the first node
        int u=findParent(parent,edges[i][0]);

        //find the parents of the second node
        int v=findParent(parent,edges[i][1]);

        //find the weight of the edges of both the node
        int wt=edges[i][2];

        //if they dont have same parents
        if(u!=v){

            //add the weight
            minWeight+=wt;

            //make the union of both the node
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
