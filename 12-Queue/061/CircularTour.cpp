#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[],int number){
    int balance=0;
    int deficient=0;
    int start=0;

    for(int i=0;i<number;i++){
        balance+=p[i].petrol-p[i].distance;
        if(balance<0){
            deficient=deficient+balance;
            start=i+1;
            balance=0;
        }
    }

    if(balance+deficient>=0){
        return start;
    }else{
        return -1;
    }
}

int main() {
    petrolPump pumps[] = {
        {4, 6}, 
        {6, 5}, 
        {7, 3},
        {4, 5}  
    };

    int number = sizeof(pumps) / sizeof(pumps[0]);

    int startPoint = tour(pumps, number);

    if (startPoint == -1) {
        cout << "No solution exists";
    } else {
        cout << "Start Point: " << startPoint;
    }

    return 0;
}
