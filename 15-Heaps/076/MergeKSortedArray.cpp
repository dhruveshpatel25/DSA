#include <bits/stdc++.h> 
using namespace std;

class Node{
    public:
    int data;
    int row;
    int col;

    Node(int data,int row,int col){
        this->data=data;
        this->row=row;
        this->col=col;
    }
};

class compare{
    public:
    bool operator()(Node* a,Node* b){
        return a->data>b->data;
    }
};

vector<int> mergeKSorted(vector<vector<int>> &karray,int k){
    priority_queue<Node*, vector<Node*>, compare> pq;
    for(int i=0;i<k;i++){
        Node *temp = new Node(karray[i][0],i,0);
        pq.push(temp);
    }

    vector<int> ans;
    while(pq.size()>=1){
        Node* temp= pq.top();
        ans.push_back(temp->data);
        pq.pop();

        int i=temp->row;
        int j=temp->col;

        if(j+1<karray[i].size()){
            Node* next=new Node(karray[i][j+1],i,j+1);
            pq.push(next);
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> karray = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {0, 9, 10, 11},
        {12,13,14,15}
    };
    int k = karray.size();

    vector<int> result = mergeKSorted(karray, k);

    cout << "Merged Sorted Array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}