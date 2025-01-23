/*Shortest Path in Directed Graph for Negative value usingBellman Ford
You have been given a directed weighted graph of ‘N’ vertices labeled from 1 to 'N' and ‘M’ edges. Each edge connecting two nodes 'u' and 'v' has a weight 'w' denoting the distance between them.
Your task is to calculate the shortest distance of all vertices from the source vertex 'src'.

Note:
If there is no path between 'src' and 'ith' vertex, the value at 'ith' index in the answer array will be 10^8.
https://www.naukri.com/code360/problems/bellmon-ford_2041977*/
#include <bits/stdc++.h>
using namespace std;

int bellmonFord(int vertex, int edges, int src,int destination, vector<vector<int>> &graph) {

    //make a distance array starting with infinity
    vector<int> distance(vertex+1,1e9);

    //make the distance of source node as 0
    distance[src]=0;

    //iterate (vertex-1) times for all edges
    for(int i=1;i<vertex;i++){

        //iterate through all the edges in graph
        for(int j=0;j<vertex;j++){

            //node1
            int u=graph[j][0];

            //node2
            int v=graph[j][1];

            //weight of the edge
            int wt=graph[j][2];

            //if the distance of node1 is not infinity and the new distance is smaller than the old
            if(distance[u]!=1e9 && distance[u]+wt<distance[v]){

                //update the weight in node2
                distance[v]=distance[u]+wt;
            }
        }
    }

    //check for negative cycle
    bool flag=0;
    for(int j=0;j<vertex;j++){

        //node1
        int u=graph[j][0];

        //node2
        int v=graph[j][1];

        //weight of the edge
        int wt=graph[j][2];

        //if the value is getting smaller and smaller than it is negative cycle
        if(distance[u]!=1e9 && distance[u]+wt<distance[v]){
            flag=1;
        }
    }

    //if flag is 0 means there is no negative cycle
    if(flag==0){
        return distance[destination];
    }
}


int main() {
    // Input the number of vertices and edges
    int V, E;
    cout << "Enter the number of vertices (V) and edges (E): ";
    cin >> V >> E;

    // Input the graph
    vector<vector<int>> graph(E);
    cout << "Enter the edges (u v w) where u -> v with weight w:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[i] = {u, v, w};
    }

    // Input source and destination
    int src, destination;
    cout << "Enter the source node and destination node: ";
    cin >> src >> destination;

    // Calculate shortest path
    int result = bellmonFord(V, E, src, destination, graph);

    if (result == -1) {
        cout << "No path exists from " << src << " to " << destination << endl;
    } else {
        cout << "Shortest path from " << src << " to " << destination << " is: " << result << endl;
    }

    return 0;
}