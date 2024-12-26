#include<iostream>
using namespace std;

class Hero{
    public:
    int health;

    //normal constructor
    Hero(){
        cout<<"Simple Consuctor"<<endl;
    }

    //takes parameter
    Hero(int health){
        cout<<"Parameterised Constructor"<<endl;
        this->health= health;
    }

    //copy data from other constructor
    Hero(Hero& temp){
        cout<<"Copy Constructor"<<endl;
        this->health=temp.health;
    }

    void print(){
        cout<<"Health: "<<this->health<<endl;
    }
};

int main(){
    Hero Suresh;

    Hero Ramesh(50);
    Ramesh.print();

    Hero Rohan(Ramesh);
    Rohan.print();
}