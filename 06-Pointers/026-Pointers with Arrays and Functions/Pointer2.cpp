#include<iostream>
#include<vector>
using namespace std;

void update(int *q){
    q=q+1;  //does not do anything
    *q=*q+1;
    cout<<"updates the value "<<q<<endl;
}

int sum(int *arr,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}

int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,0};
    cout<<"adress of first block "<<&arr<<endl;
    cout<<"adress of first block "<<&arr[0]<<endl;
    cout<<"adress of first block "<<arr<<endl;
    cout<<"element on first block "<<*arr<<endl;
    cout<<"element on second block "<<*arr+1<<endl;
    cout<<"element on second block "<<*(arr+1)<<endl;
    cout<<"element on third block "<<arr[2]<<endl;

    int i=4;
    cout<<"arr[i] can be written as i[arr] "<<i[arr]<<endl;

    cout<<"size of array "<<sizeof(arr)<<endl;
    cout<<"size of block in array "<<sizeof(*arr)<<endl;
    cout<<"size of block in array "<<sizeof(&arr)<<endl;

    int *ptr=&arr[0];
    cout<<"size of pointer "<<sizeof(ptr)<<endl;
    cout<<"size of pointer "<<sizeof(*ptr)<<endl;
    cout<<"size of pointer "<<sizeof(&ptr)<<endl;

    cout<<"address of block pointed by pointer "<<ptr<<endl;
    cout<<"element of block pointed by pointer "<<*ptr<<endl;
    cout<<"address of pointer "<<&ptr<<endl;

    ptr=ptr+1;
    cout<<"address of block pointed by pointer incremented "<<ptr<<endl;

    //character array
    int arr1[5]={1,2,3,4,5};
    char ch[5]= "abcd";
    cout<<"address of first block for int type array"<<arr1<<endl;
    cout<<"for char type array, complete array "<<ch<<endl;

    char *c=&ch[0];
    cout<<"prints complete array "<<c<<endl;

    //function array
    int value=5;
    int *q=&value;
    cout<<q<<endl;
    update(q);
    cout<<"same as before the function as copy of array is sent to function "<<q<<endl;

    int arr2[2]={1,2};
    cout<<"Sum of array "<<sum(arr2,2);
}

