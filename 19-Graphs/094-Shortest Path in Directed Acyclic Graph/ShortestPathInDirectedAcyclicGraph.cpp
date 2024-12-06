/*shortest path in a directed acyclic graph
What do we mean by the Shortest Path in a directed acyclic graph?

Well, it’s a trivial question, but still, for the sake of clarity, we’ll define that let

G = (V, E) be a directed graph with E edges and V vertices.

Let T be the shortest path between any 2 vertices in the graph such that there is no other path in the graph between any 2 vertices whose sum of edge weights is less than T’s sum of edge weights. 

NOTE: shortest path between 2 vertices is defined only when the vertices are in the same graph, i.e., the graph should not be disconnected.

https://www.naukri.com/code360/library/shortest-path-in-a-directed-acyclic-graph*/
#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:

    //int(node) int(next node) int(weight)
    unordered_map<int,list<pair<int,int>>> adjList;
    void addEdge(int u,int v,int weight){

        //pair of next node and its weight
        pair<int,int> p=make_pair(v,weight);

        //node1
        adjList[u].push_back(p);
    }

    void printAdj(){
        for(auto i:adjList){
            cout<<i.first<<"->";
            for( auto j:i.second){
                cout<<"("<<j.first<<","<<j.second<<")";
            }
            cout<<endl;
        }
    }

    void dfs(int node,unordered_map<int,bool>& visited,stack<int>& stk){

        //marking the node as visited
        visited[node]=true;
        for(auto neighbour:adjList[node]){

            //if node is not visited
            if(!visited[neighbour.first]){

                //recursivly call for next node
                dfs(neighbour.first,visited,stk);
            }
        }

        //when returning put it in stack
        stk.push(node);
    }

    void getShortestPath(int src,vector<int>& dist,stack<int>& stk){

        //making the distance of source node as 0
        dist[src]=0;

        //till the stack gets empty
        while(!stk.empty()){
            int top=stk.top();
            stk.pop();

            //if the distance is not infinity(meaning it is used to the node which is not needed)
            if(dist[top]!=INT_MAX){

                //all the next node
                for(auto i:adjList[top]){

                    //to check whether the new distance is smaller or not
                    //i.second = the distance of that node
                    //i.first = the next node
                    if(dist[top]+i.second<dist[i.first]){
                        dist[i.first]=dist[top]+i.second;
                    }
                }
            }
        }
    }
};

int main(){
    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    //int(node) bool(visited or not)
    unordered_map<int,bool> visited;
    stack<int> stk;
    int vertex=6;

    //topological sorting
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
           g.dfs(i,visited,stk);
        }
    }

    //source node
    int src=1;

    //distance array to save the shortest distance
    vector<int> dist(vertex);

    //initialising each vertex with distance infinity
    for(int i=0;i<vertex;i++){
        dist[i]=INT_MAX;
    }
    g.getShortestPath(src,dist,stk);
    cout << "answer is: " << endl;

    for(int i=0; i<dist.size(); i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}