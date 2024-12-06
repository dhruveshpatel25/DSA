/*Shortest path in an unweighted graph
The city of Ninjaland is analogous to the unweighted graph. The city has ‘N’ houses numbered from 1 to ‘N’ respectively and are connected by M bidirectional roads. If a road is connecting two houses ‘X’ and ‘Y’ which means you can go from ‘X’ to ‘Y’ or ‘Y’ to ‘X’. It is guaranteed that you can reach any house from any other house via some combination of roads. Two houses are directly connected by at max one road.

A path between house ‘S’ to house ‘T’ is defined as a sequence of vertices from ‘S’ to ‘T’. Where starting house is ‘S’ and the ending house is ‘T’ and there is a road connecting two consecutive houses. Basically, the path looks like this: (S , h1 , h2 , h3 , ... T). you have to find the shortest path from ‘S’ to ‘T’.
https://www.naukri.com/code360/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar*/
#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int,int>> edges,int vertex, int edge,int src,int dest){

    //int(node) list(nodes connected to it)
    unordered_map<int,list<int>> adjList;

    //iterate for all node
    for(int i=0;i<edges.size();i++){

        //retrieving from the data given
        //node1
        int u = edges[i].first;

        //node2
        int v = edges[i].second;

        //node1->node2
        adjList[u].push_back(v);
    }

    //int(node) bool(visited or not)
    unordered_map<int,bool> visited;

    //int(node) int(node's parent)
    unordered_map<int,int> parent;
    queue<int> que;
    que.push(src);

    //marking the the first node visited
    visited[src]=true;

    //parent of first node is -1
    parent[src]=-1;
    while(!que.empty()){
        int front = que.front();
        que.pop();

        //checking its child node
        for(auto neighbours:adjList[front]){

            //check if the next node are visited or not
            if(!visited[neighbours]){

                //if they are not then mark them visited
                visited[neighbours]=true;

                //make the node as their parent node
                parent[neighbours]=front;

                //and push the child node
                que.push(neighbours);
            }
        }
    }

    //shortest path
    vector<int> ans;

    //start with the destination node
    int currentNode=dest;
    ans.push_back(dest);

    //loop till you reach source
    while(currentNode!=src){

        //check for the parent node and make the parent node as current node
        currentNode=parent[currentNode];
        ans.push_back(currentNode);
    }

    //reverse the array
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    vector<pair<int, int>> edgeList(edges);
    cout << "Enter the edges (format: source destination):" << endl;
    for (int i = 0; i < edges; ++i) {
        cin >> edgeList[i].first >> edgeList[i].second;
    }

    int source, destination;
    cout << "Enter source and destination vertices: ";
    cin >> source >> destination;

    vector<int> shortest = shortestPath(edgeList, vertices, edges, source, destination);

    cout << "Shortest path from " << source << " to " << destination << " is: ";
    for (int vertex : shortest) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}