#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

class graph{
    public:

    // int(node) list(nodes connected to it)
    unordered_map<int,list<int> > adj;

    //direction->1=unidirected graph
    //direction->0=directed graph
    void addEdge(int u,int v,bool direction){

        //push the node2 connected in the adjacency list for node1
        adj[u].push_back(v);

        //if the direction is 1(meaning the graph is unidirected) push the node node1 connected to node2 adjacnecy list
        if(direction){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){

        //for the node
        for(auto i:adj){
            cout<<i.first<<"-> ";

            //its connected node
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};

int main(){
    int nodes;
    cout<<"Enter the no.of nodes: ";
    cin>>nodes;

    int edge;
    cout<<"Enter the no.of edges: ";
    cin>>edge;

    graph g;
    for(int i=0;i<edge;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }

    g.printAdjList();
}