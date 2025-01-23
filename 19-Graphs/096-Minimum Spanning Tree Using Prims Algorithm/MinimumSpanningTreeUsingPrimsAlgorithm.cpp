/*Prim's MST
You are given an undirected connected weighted graph having ‘N’ nodes numbered from 1 to 'N'. A matrix ‘E’ of size M x 2 is given which represents the ‘M’ edges such that there is an edge directed from node E[i][0] to node E[i][1]. You are supposed to return the minimum spanning tree where you need to return weight for each edge in the MST.
https://www.naukri.com/code360/problems/prim-s-mst_1095633*/
#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int,int>,int>> Prim(int vertex,int edges,vector<pair<pair<int,int>,int>> &graph){

    //int(node) int(next node) int(weight)
    unordered_map<int,list<pair<int,int>>> adjList;
    for(int i=0;i<graph.size();i++){

        //first node
        int u=graph[i].first.first; 

        //second node
        int v=graph[i].first.second;

        //weight
        int w=graph[i].second;

        //node1->node2
        adjList[u].push_back(make_pair(v,w));

        //node2->node1
        adjList[v].push_back(make_pair(u,w));
    }

    //int(shortest distance) to store the distance
    vector<int> key(vertex+1);

    //bool(present in MST or not) to check whether the node in present in MST or not
    vector<bool> mst(vertex+1);

    //int(parent of that node) to store the parent of the node
    vector<int> parent(vertex+1);

    //iterate for all the nodes    
    for(int i=0;i<=vertex;i++){

        //make the key of all nodes to infinity
        key[i]=INT_MAX;

        //make the parent of all the nodes to -1
        parent[i]=-1;

        //make the nodes present in MST as false
        mst[i]=false;
    }

    //make the source node with distance as 0
    key[1]=0;

    //make the parent of source node as -1
    parent[1]=-1;

    //iterate for all the nodes
    for(int i=0;i<=vertex;i++){

        //for shortest distance
        int mini=INT_MAX;

        //for the node os shortest distance
        int u;

        //now we iterate to find the 'u'
        for(int v=1;v<=vertex;v++){

            //if the node is not present in MST and the distance is shorter
            if(mst[v]==false && key[v]<mini){

                //we found the node
                u=v;

                //the distance is updated
                mini=key[v];
            }
        }

        //mark the node as true in MST
        mst[u]=true;

        //check for its next node
        for(auto it:adjList[u]){

            //the node
            int v=it.first;

            //the distance
            int w=it.second;

            //if the node is not present in MST and the distance is shorter
            if(mst[v]==false && w<key[v]){

                //make the next nodes parent as 'u'
                parent[v]=u;

                //enter the shorter distance
                key[v]=w;
            }
        }
    }

    //int(node) int(next node) int(weight)
    vector<pair<pair<int,int>,int>> ans;

    //as the array is 0-index so we cannot use i=0
    //and the parent of 1st index is -1 so i=1 cannot be used
    for(int i=2;i<=vertex;i++){

        //parent-node , distance
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