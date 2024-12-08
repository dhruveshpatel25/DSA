/* Dijkstra's shortest path
You have been given an undirected graph of ‘V’ vertices (labeled 0,1,..., V-1) and ‘E’ edges. Each edge connecting two nodes (‘X’,’Y’) will have a weight denoting the distance between node ‘X’ and node ‘Y’.

Your task is to find the shortest path distance from the source node, which is the node labeled as 0, to all vertices given in the graph.
https://www.naukri.com/code360/problems/dijkstra-s-shortest-path_920469?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar*/
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>>&vec,int vertices, int edges,int src){

    //int(node) int(next node) int(weight)
    unordered_map<int,list<pair<int,int>>> adjList;
    for(int i=0;i<edges;i++){

        // first node
        int u=vec[i][0];

        // second node  
        int v=vec[i][1];

        //distance
        int w=vec[i][2]; 

        //node1->node2
        adjList[u].push_back(make_pair(v,w));

        //node2->node1
        adjList[v].push_back(make_pair(u,w));
    }

    //distance array
    vector<int> dist(vertices);
    for(int i=0;i<vertices;i++){

        //set to infinity
        dist[i]=INT_MAX;
    }

    //use set to store(ascending order)
    //int(distance) int (next node) it is ordered by distance so shortest distance is iterated first
    set<pair<int,int>> st;

    //make the source node distance as 0
    dist[src]=0;

    //(distance,next node)-enter this in set
    st.insert(make_pair(0,src));

    //till set is emplty
    while(!st.empty()){

        //take the minimum value as per distance
        auto top=*(st.begin());

        //retrieve the distance
        int nodeDistance=top.first;

        //retrieve the node
        int topNode=top.second;

        //delete the pair form set
        st.erase(st.begin());

        //find the next nodes of the particular node
        for(auto neighbour:adjList[topNode]){

            //check whether the new distance is smaller or not
            if(nodeDistance+neighbour.second<dist[neighbour.first]){

                //check whether there exist any node indside the set
                auto record=st.find(make_pair(dist[neighbour.first],neighbour.first));

                //delete the old (distance,node) because the new node will have smaller distance
                if(record!=st.end()){
                    st.erase(neighbour);
                }

                //now make changes in distance array
                dist[neighbour.first]=nodeDistance+neighbour.second;

                //add (new distance,node) to set
                st.insert(make_pair(dist[neighbour.first],neighbour.first));
            }
        }
    }
    return dist;
}

int main() {
    // Example usage
    int vertices = 4; // Number of vertices
    int edges = 5; // Number of edges

    // Edge list representation: {source, destination, weight}
    vector<vector<int>> edgeList = {
        {0, 1, 5},
        {0, 2, 8},
        {1, 2, 9},
        {1, 3, 2},
        {2, 3, 6},
    };

    int source = 0; // Source vertex

    // Call Dijkstra's algorithm
    vector<int> shortest_distances = dijkstra(edgeList, vertices, edges, source);

    // Output shortest distances from source vertex
    cout << "Shortest distances from vertex " << source << ":\n";
    for (int i = 0; i < vertices; ++i) {
        cout << "Vertex " << i << ": " << shortest_distances[i] << endl;
    }

    return 0;
}