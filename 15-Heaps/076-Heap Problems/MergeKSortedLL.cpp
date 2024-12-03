/*Merge k sorted lists
Given 'k' sorted linked lists, each list is sorted in increasing order. You need to merge all these lists into one single sorted list. You need to return the head of the final linked list.
https://www.naukri.com/code360/problems/merge-k-sorted-lists_992772?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar*/#include <bits/stdc++.h> 
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
};

class compare{
    public:
    bool operator()(Node* a,Node* b){
        return a->data>b->data;
    }
};

Node* mergeKSortedLL(vector<Node*> &kLL){

    //priority queue in ascending order
    priority_queue<Node*,vector<Node*>, compare>pq;
    int k=kLL.size();
    for(int i=0;i<k;i++){

        //pushing all the heads of the linked list if they are not NULL
        if(kLL[i]!=NULL){
            pq.push(kLL[i]);
        }
    }


    Node* head=NULL;
    Node* tail=NULL;
    while(pq.size()>0){
        Node* temp = pq.top();
        pq.pop();

        //first element
        if(head==NULL){
            head=temp;
            tail=temp;
        }
        else{ //if not the first
            tail->next=temp;
            tail=temp;
        }

        //push the next element of the original linked list
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
