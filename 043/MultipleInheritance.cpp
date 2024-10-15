#include<iostream>
using namespace std;

class Animal{
    public:
    void bark(){
        cout<<"Bark"<<endl;
    }
};

class Human{
    public:
    void speak(){
        cout<<"Speak"<<endl;
    }
};

class Dogs: public Animal,public Human{};

int main(){
    Dogs d1;
    d1.bark();
    d1.speak();
}