#include<iostream>
using namespace std;

class Hero{
    public:
    int health;

    private:
    char level;
    void print(){
        cout<<level; //private modifier can we accesed in the class 
    }

    public:

    //to get private modifiers
    char getlevel(){
        return level;
    }

    //to set private modifiers
    void setlevel(char ch){
        level=ch;
    }

    
};

int main(){
    Hero Ramesh;
    cout<<"Ramesh Health: "<<Ramesh.health<<endl; //will not throw error as it is public modifier

    //cout<<"Ramesh level: "<<Ramesh.level; //will throw error as it is private modifier

    cout<<"Ramesh Level: "<<Ramesh.getlevel()<<endl; //private modifier can be accessed using getter

    Ramesh.setlevel('A');

    cout<<"Ramesh Level after setting: "<<Ramesh.getlevel()<<endl;
}