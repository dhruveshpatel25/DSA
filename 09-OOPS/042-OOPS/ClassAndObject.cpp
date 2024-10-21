#include<iostream>
using namespace std;

class Hero{
    int health;
    char level;
};

class Herokhali{

};

int main(){
    Hero ramesh;
    cout<<"Size of: "<<sizeof(ramesh)<<endl;

    Herokhali suresh;
    cout<<"Size of: "<<sizeof(suresh)<<endl;
}