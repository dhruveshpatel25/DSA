#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;
    q.push(11);
    cout<<"Front element is: "<<q.front()<<endl;
    cout<<"Back element is: "<<q.back()<<endl;
    
    q.push(22);
    cout<<"Front element is: "<<q.front()<<endl;
    cout<<"Back element is: "<<q.back()<<endl;

    q.push(33);
    cout<<"Front element is: "<<q.front()<<endl;
    cout<<"Back element is: "<<q.back()<<endl;

    cout<<"Size after pop: "<<q.size()<<endl;

    q.pop();

    cout<<"Size after pop: "<<q.size()<<endl;

    if(q.empty()){
        cout<<"The queue is empty"<<endl;
    }else{
        cout<<"The queue is not empty"<<endl;
    }
}