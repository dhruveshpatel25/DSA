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

Node * sort(Node * head){
    int zerocount=0;
    int onecount=0;
    int twocount=0;

    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            zerocount++;
        }
        else if(temp->data==1){
            onecount++;
        }
        else if(temp->data==2){
            twocount++;
        }
        temp=temp->next;
    }
        temp=head;
        while(temp!=NULL){
            if(zerocount!=0){
                temp->data=0;
                zerocount--;
            }
            else if(onecount!=0){
                temp->data=1;
                onecount--;
            }
            else if(twocount!=0){
                temp->data=2;
                twocount--;
            }
            temp=temp->next;
        }
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
    sort(head);
    print(head);
}