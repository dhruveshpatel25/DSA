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

void InsertAtTail1(Node* &tail,Node* temp){
    tail->next=temp;
    tail=temp;
}

Node * SortWithoutReplacing(Node * head){
    Node* zerohead=new Node(-1);
    Node* zerotail=zerohead;
    Node* onehead=new Node(-1);
    Node* onetail=onehead;
    Node* twohead=new Node(-1);
    Node* twotail=twohead;

    Node* temp=head;
    while(temp!=NULL){
        int value=temp->data;
        if(value==0){
            InsertAtTail1(zerotail,temp);
        }
        else if(value==1){
            InsertAtTail1(onetail,temp);
        }
        else if(value==2){
            InsertAtTail1(twotail,temp);
        }
        temp=temp->next;
    }
    if(onehead->next!=NULL){
        zerotail->next = onehead->next;
    }else{
        zerotail->next= twohead->next;
    }
    onetail->next=twohead->next;
    twotail->next=NULL;

    head=zerohead->next;
    delete zerohead;
    delete onehead;
    delete twohead;

    return head;
}

void InsertAtTail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}


void print(Node* &head){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node* node1= new Node(1);
    Node* head=node1;
    Node* tail=node1;
    InsertAtTail(tail,0);
    InsertAtTail(tail,2);
    InsertAtTail(tail,1);
    InsertAtTail(tail,2);
    print(head); 
    head=SortWithoutReplacing(head);
    print(head);
}