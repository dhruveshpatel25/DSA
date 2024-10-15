#include<iostream>
using namespace std;

class Animal{
    public:
    void bark(){
        cout<<"Bark"<<endl;
    }
};

class Dogs: public Animal{};

class GermanShepherd: public Dogs{};

int main(){
    GermanShepherd g1;
    g1.bark();
}