#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<pair<int,int>>> adjList;
    void addEdge(int u,int v,int weight){
        pair<int,int> p=make_pair(v,weight);
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
        visited[node]=true;
        for(auto neighbour:adjList[node]){
            if(!visited[neighbour.first]){
                dfs(neighbour.first,visited,stk);
            }
        }
        stk.push(node);
    }

    void getShortestPath(int src,vector<int>& dist,stack<int>& stk){
        dist[src]=0;
        while(!stk.empty()){
            int top=stk.top();
            stk.pop();

            if(dist[top]!=INT_MAX){
                for(auto i:adjList[top]){
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

    unordered_map<int,bool> visited;
    stack<int> stk;
    int vertex=6;
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
           g.dfs(i,visited,stk);
        }
    }

    int src=1;
    vector<int> dist(vertex);
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