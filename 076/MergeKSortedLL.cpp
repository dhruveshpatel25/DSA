#include <bits/stdc++.h> 
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

class compare{
    public:
    bool operator()(Node* a,Node* b){
        return a->data>b->data;
    }
};

Node* mergeKSortedLL(vector<Node*> &kLL){
    priority_queue<Node*,vector<Node*>, compare>pq;
    int k=kLL.size();
    for(int i=0;i<k;i++){
        if(kLL[i]!=NULL){
            pq.push(kLL[i]);
        }
    }

    Node* head=NULL;
    Node* tail=NULL;
    while(pq.size()>0){
        Node* temp = pq.top();
        pq.pop();


        if(head==NULL){
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
        if(tail->next!=NULL){
            pq.push(tail->next);
        }
    }
    return head;
}

int main() {
    // Creating sample linked lists
    Node* head1 = new Node(1);
    head1->next = new Node(4);
    head1->next->next = new Node(7);

    Node* head2 = new Node(2);
    head2->next = new Node(5);
    head2->next->next = new Node(8);

    Node* head3 = new Node(3);
    head3->next = new Node(6);
    head3->next->next = new Node(9);

    // Creating a vector of linked lists
    vector<Node*> kLL;
    kLL.push_back(head1);
    kLL.push_back(head2);
    kLL.push_back(head3);

    // Merging the sorted linked lists
    Node* mergedHead = mergeKSortedLL(kLL);

    // Printing the merged linked list
    cout << "Merged Linked List: ";
    Node* temp = mergedHead;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Freeing memory
    temp = mergedHead;
    while (temp != NULL) {
        Node* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }

    // Clearing the original linked lists from the vector
    for (int i = 0; i < kLL.size(); i++) {
        Node* current = kLL[i];
        while (current != NULL) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }

    return 0;
}
