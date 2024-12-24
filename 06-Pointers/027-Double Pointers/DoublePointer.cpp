#include<iostream>
using namespace std;

void update(int **ptr2){
    //ptr2=ptr2+1; // will not cause any change

    //*ptr2=*ptr2+1; //will change the adress of ptr

    **ptr2=**ptr2+1; //will change i value
}

int main(){
    int i=5;
    int *ptr=&i;
    int **ptr2=&ptr;

    //will return value of i 
    cout<<"Value of i"<<i<<endl;

    //will return value of pointer pointing(i.e. i)
    cout<<"Value of pointer pointing "<<*ptr<<endl;

    //will return value of pointer pointing at pointer pointing(i.e. i) 
    cout<<"Value of pointer pointing at pointer pointing "<<**ptr2<<endl;

    //will return address of i
    cout<<"Address of i "<<&i<<endl;

    //will return adsress of pointer pointing(i.e. i)
    cout<<"Address of pointer pointing "<<ptr<<endl;

    //will return address of pointer pointing at pointer pointing(i.e. i) 
    cout<<"Address of pointer pointing at pointer pointing "<<*ptr2<<endl;

    //will return the address of ptr1
    cout<<"Address of pointer "<<&ptr<<endl;

    //will return address of ptr1 by pointing by pointer
    cout<<"Address of pointer pointing "<<ptr2<<endl;

    //functions with double pointer
    cout<<"before "<<i<<endl;
    cout<<"before "<<ptr<<endl;
    cout<<"before "<<ptr2<<endl;
    update(ptr2);

    //updated value
    cout<<"after "<<i<<endl;
    cout<<"after "<<ptr<<endl;
    cout<<"after "<<ptr2<<endl;
}