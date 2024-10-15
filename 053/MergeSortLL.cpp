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
};

Node* getmid(Node* head){
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right){
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }
    Node* ans=new Node(-1);
    Node* temp=ans;
    while(left!=NULL && right!=NULL){
        if(left->data<right->data){
            temp->next=left;
            temp=left;
            left=left->next;
        }else{
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }
    while(left!=NULL){
        temp->next=left;
        temp=left;
        left=left->next;
    }
    while(right!=NULL){
        temp->next=right;
        temp=right;
        right=right->next;
    }
    ans=ans->next;
    return ans;
}

Node * mergesort(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* middle=getmid(head);
    Node* left=head;
    Node* right=middle->next;
    middle->next=NULL;

    left=mergesort(left);
    right=mergesort(right);

    Node* result=merge(left,right);
    return result;
}

void InsertAtTail(Node* &head,Node* &tail,int d){
    Node* temp=new Node(d);
    if(head==NULL){
        head=temp;
        tail=temp;
        return;
    }else{
        tail->next=temp;
        tail=temp;
    }
}

void print(Node* head){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node* node1= new Node(5);
    Node* head=node1;
    Node* tail=node1;
    InsertAtTail(head,tail,3);
    InsertAtTail(head,tail,2);
    InsertAtTail(head,tail,4);
    InsertAtTail(head,tail,1);
    print(head);
    head=mergesort(head);
    print(head); 
    return 0;
}