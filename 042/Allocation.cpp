#include<iostream>
using namespace std;

class Hero{
    public:
    int health;
    char level;
};

int main(){
    //Static Allocation
    Hero Static;
    cout<<"Static Health: "<<Static.health<<endl;
    cout<<"Static Level: "<<Static.level<<endl;

    //Dynamic Allocation
    Hero *Dynamic= new Hero;
    cout<<"Dynamic Health: "<<(*Dynamic).health<<endl;
    cout<<"Dynamic Level: "<<(*Dynamic).level<<endl;

    cout<<"Dynamic Health: "<<Dynamic->health<<endl;
    cout<<"Dynamic Level: "<<Dynamic->level<<endl;
}