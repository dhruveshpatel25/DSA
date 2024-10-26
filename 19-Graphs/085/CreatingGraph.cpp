#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

class graph{
    public:
    unordered_map<int,list<int> > adj;
    void addEdge(int u,int v,bool direction){
        //direction->1=unidirected graph
        //direction->0=directed graph
        adj[u].push_back(v);
        if(direction){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<<"-> ";
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
        g.addEdge(u,v,1);
    }

    g.printAdjList();
}