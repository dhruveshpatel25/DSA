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

    //will return 8 as it has 2 int
    cout<<"Size of: "<<sizeof(ramesh)<<endl;

    Herokhali suresh;

    //will return 1 as it does not have anything
    cout<<"Size of: "<<sizeof(suresh)<<endl;
}