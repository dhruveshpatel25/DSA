#include<iostream>
using namespace std;

int& func(int n){ //will throw warning
    int num=n;
    int& ans=num;
    return ans;
}

int* func2(int n){ //will throw warning
    int num=n;
    int* ptr=&num;
    return ptr;
}

int update2(int& n){ //Pass by Reference-will return the value
    n++;
    return n;
}

int update(int n){  //Pass by Value-will not return the value
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