#include<iostream>
using namespace std;

class Hero{
    public:

    //available to all the members in the class
    static int timetocomplete; //static keyword

    //can onlu access static members
    static int random(){ //static function
        return timetocomplete;
    }
};

int Hero::timetocomplete = 5;

int main(){
    cout<< Hero::timetocomplete <<endl;
    cout<< Hero::random()<<endl;
}