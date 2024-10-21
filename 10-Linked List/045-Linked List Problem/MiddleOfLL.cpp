#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
    }
};

void InsertAtTail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}

int getlength(Node* head){
    int len=0;
    while(head!=NULL){
        len++;
        head=head->next;
    }
    return len;
}

Node *Middle(Node* &head){
    int len=getlength(head);
    int ans= (len/2);
    Node* temp = head;
    int count=0;
    while(count<ans){
        temp=temp->next;
        count++;
    }
    return temp;
}


int main(){
    Node* node1=new Node(1);
    int ans;
    Node* head=node1;
    Node* tail=node1;
    InsertAtTail(tail,2);
    InsertAtTail(tail,3);
    InsertAtTail(tail,4);
    InsertAtTail(tail,5);
    InsertAtTail(tail,6);
    Middle(head);
    Node* middleNode = Middle(head);
    if (middleNode != NULL) {
        cout << "Middle node value: " << middleNode->data << endl;
    } else {
        cout << "List is empty." << endl;
    }
}