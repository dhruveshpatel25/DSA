#include<iostream>
using namespace std;

//will throw warning
int& func(int n){
    int num=n;
    int& ans=num;
    return ans;
}

//will throw warning
int* func2(int n){ 
    int num=n;
    int* ptr=&num;
    return ptr;
}

//Pass by Reference-will return the value
int update2(int& n){ 
    n++;
    return n;
}

//Pass by Value-will not return the value
int update(int n){  
    n++;
    return n;
}

int main(){
    int i=5;
    int& j=i;
    cout<<i<<endl;
    i++;
    cout<<"Value of i after increment of i "<<i<<endl;
    j++;
    cout<<"Value of i after increment of j "<<i<<endl;
    cout<<j<<endl;

    int n=5;
    cout<<"Before update "<<n<<endl;
    update(n);
    update2(n);
    cout<<"After update "<<n<<endl;
    func(n);
    func2(n);
}