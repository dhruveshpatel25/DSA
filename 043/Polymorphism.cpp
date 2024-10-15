#include<iostream>
using namespace std;

class FunOver{ //Function Overloading
    public:
    void sayhello(){
        cout<<"Hello"<<endl;
    }

    void sayhello(string name){  //same function can be written twice by different arguments
        cout<<"Hello "<<name<<endl;
    }

    void sayhello(string name1,string name2){ //same function can be written with different no.of arguments
        cout<<"Hello "<<name1<<" "<<name2<<endl;
    }

    /*int sayhello(){  // return type cannot distinguish function with same name
        cout<<"Hello"<<endl;
        return 1;
    }*/

    /*void sayhello(){  // same function cannot be written twice
        cout<<"Hello"<<endl;
    }*/
};

class OpOver{ //Operator Overloading
    public:
    int a;
    int b;
    int add(){
        return a+b;
    }
    int operator+ (OpOver &obj){
        int value1 = this->a;
        int value2 = obj.b;
        cout<<value2-value1<<endl;
    }
};

class MetOver{
    public:
    void speak(){
        cout<<"Speaking"<<endl;
    }
 };

class MetOver2: public MetOver{
    public:
    void speak(){
        cout<<"Barking"<<endl;
    }
};

int main(){
    FunOver obj;
    obj.sayhello("A","B");

    OpOver obj1;
    obj1.a=4;
    obj1.b=7;
    obj1+obj1;

    MetOver2 obj2;
    obj2.speak();
}