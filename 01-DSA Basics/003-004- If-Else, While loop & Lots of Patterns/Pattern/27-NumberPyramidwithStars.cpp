/*
1234554321
1234**4321
123****321
12******21
1********1
*/#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the no.of times "<<endl;
    cin>>n;
    int i=0;
    while(i+1<=n){
        int j=0;
        int space=0;
         while(j<n-i){
            cout<<""<<j+1;
            j++;
        }
        j=1;
        while(j<=i*2){
            cout<<"*";
            j++;
        }
        j=n-i;
        while(j>0){
            cout<<""<<j;
            j=j-1;
        }
        cout<<endl;
        i++;
    }
}