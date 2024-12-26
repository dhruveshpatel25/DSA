#include<iostream>
using namespace std;

class Student{
    private:
    string name;
    int age;
    int height;

    public:
    //only way to acess private data
    int getAge(){
        return this->age;
    }
};

int main(){
    Student Ramesh;
    cout<<"Everything is OK"<<endl;
}