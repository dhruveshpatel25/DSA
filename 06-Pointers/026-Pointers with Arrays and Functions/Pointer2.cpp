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

    //&arr returns the address of first block
    cout<<"adress of first block "<<&arr<<endl;  

    //&arr[0] will return the address of the first block
    cout<<"adress of first block "<<&arr[0]<<endl; 

    //arr will return the address of the first block
    cout<<"adress of first block "<<arr<<endl; 

    //(*arr) will return the value of first block
    cout<<"element on first block "<<*arr<<endl; 

    //(*arr+1) will return the value of second block
    cout<<"element on second block "<<*arr+1<<endl; 

    //(*(arr+2)) will return the value of second block
    cout<<"element on second block "<<*(arr+1)<<endl; 

    //arr[n] will return the value of n block
    cout<<"element on third block "<<arr[2]<<endl; 

    int i=4;

    //i[arr] will return the same as arr[i]
    cout<<"arr[i] can be written as i[arr] "<<i[arr]<<endl;

    //sizeof(arr) will return the size of the array
    cout<<"size of array "<<sizeof(arr)<<endl;

    //sizeof(*arr) will return the size block of array
    cout<<"size of block in array "<<sizeof(*arr)<<endl;

    //sizeof(&arr) will return the size block of array 
    cout<<"size of block in array "<<sizeof(&arr)<<endl;

    int *ptr=&arr[0];

    //sizeof(ptr) will return the size of the ptr
    cout<<"size of pointer "<<sizeof(ptr)<<endl;

    //sizeof(*ptr) will return the size of the value
    cout<<"size of value "<<sizeof(*ptr)<<endl;

    //sizeof(&ptr) will return size of the block of ptr
    cout<<"size of pointer "<<sizeof(&ptr)<<endl;

    //ptr will return the address of the block its pointing
    cout<<"address of block pointed by pointer "<<ptr<<endl;

    //(*ptr) will return the element it is pointing
    cout<<"element of block pointed by pointer "<<*ptr<<endl;

    //&ptr will return the address of the ptr
    cout<<"address of pointer "<<&ptr<<endl;

    ptr=ptr+1;

    //will return the address of incremeneted value
    cout<<"address of block pointed by pointer incremented "<<ptr<<endl;

    //character array
    int arr1[5]={1,2,3,4,5};
    char ch[5]= "abcd";

    //arr1 will return the address of first block of array
    cout<<"address of first block for int type array"<<arr1<<endl;

    //ch will return the complete array if it is char type array
    cout<<"for char type array, complete array "<<ch<<endl;

    char *c=&ch[0];

    //will still return the complete array
    cout<<"prints complete array "<<c<<endl;

    //function array
    int value=5;
    int *q=&value;
    cout<<q<<endl;
    update(q);

    //will return same before function because only copy of the pointer is updated not the real
    cout<<"same as before the function as copy of array is sent to function "<<q<<endl;

    int arr2[2]={1,2};

    //will return the value of the function
    cout<<"Sum of array "<<sum(arr2,2);
}

