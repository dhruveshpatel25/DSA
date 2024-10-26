#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>>&vec,int vertices, int edges,int src){
    unordered_map<int,list<pair<int,int>>> adjList;
    for(int i=0;i<edges;i++){
        int u=vec[i][0]; // first node
        int v=vec[i][1]; // second node 
        int w=vec[i][2]; //distance

        adjList[u].push_back(make_pair(v,w));
        adjList[v].push_back(make_pair(u,w));
    }

    //
    vector<int> dist(vertices);
    for(int i=0;i<vertices;i++){
        dist[i]=INT_MAX;
    }
    set<pair<int,int>> st;
    dist[src]=0;
    st.insert(make_pair(0,src));

    while(!st.empty()){
        auto top=*(st.begin());
        int nodeDistance=top.first;
        int topNode=top.second;

        st.erase(st.begin());

        for(auto neighbour:adjList[topNode]){
            if(nodeDistance+neighbour.second<dist[neighbour.first]){
                auto record=st.find(make_pair(dist[neighbour.first],neighbour.first));
                if(record!=st.end()){
                    st.erase(neighbour);
                }
                dist[neighbour.first]=nodeDistance+neighbour.second;
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