#include<iostream>
using namespace std;

class Hero{
    public:
    static int timetocomplete; //static keyword

    static int random(){ //static function
        return timetocomplete;
    }
};

int Hero::timetocomplete = 5;

int main(){
    cout<< Hero::timetocomplete <<endl;
    cout<< Hero::random()<<endl;
}