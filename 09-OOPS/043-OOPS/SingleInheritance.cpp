#include<iostream>
using namespace std;

class Animal{
    public:
    void bark(){
        cout<<"Bark"<<endl;
    }
};

class Dogs: public Animal{};

int main(){
    Dogs d1;
    d1.bark();
}