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

    cout<<"Value of i"<<i<<endl;
    cout<<"Value of pointer pointing "<<*ptr<<endl;
    cout<<"Value of pointer pointing at pointer pointing "<<**ptr2<<endl;

    cout<<"Address of i "<<&i<<endl;
    cout<<"Address of pointer pointing "<<ptr<<endl;
    cout<<"Address of pointer pointing at pointer pointing "<<*ptr2<<endl;

    cout<<"Address of pointer "<<&ptr<<endl;
    cout<<"Address of pointer pointing "<<ptr2<<endl;

    //functions with double pointer
    cout<<"before "<<i<<endl;
    cout<<"before "<<ptr<<endl;
    cout<<"before "<<ptr2<<endl;
    update(ptr2);
    cout<<"after "<<i<<endl;
    cout<<"after "<<ptr<<endl;
    cout<<"after "<<ptr2<<endl;
}