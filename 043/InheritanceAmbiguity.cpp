#include<iostream>
using namespace std;

class A{
    public:
    void func1(){
        cout<<"This is A"<<endl;
    }
};

class C{
    public:
    void func1(){
        cout<<"This is D"<<endl;
    }
};

class B: public A,public C{};

int main(){
    B obj;
    obj.A::func1();
    obj.C::func1(); //when same function exist in different class '::' is used
}