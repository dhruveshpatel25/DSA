#include<iostream>
using namespace std;

class heap{
    public:
    int arr[1000];
    int size=0;

    heap(){
        arr[0]=-1;
        size=0;
    }

    void insert(int data){
        size=size+1;
        int index=size;
        arr[index]=data;

        if(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
            }else{
                return;
            }
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deleteFromHeap(){
        if(size==0){
            cout<<"Heap is Empty";
        }

        arr[1]=arr[size];
        size--;

        int i=1;
        while(i<size){
            int leftindex=2*i;
            int rightindex=2*i+1;

            if(leftindex<size && arr[leftindex]>arr[i]){
                swap(arr[i],arr[leftindex]);
                i=leftindex;
            }
            else if(rightindex<size && arr[i]<arr[rightindex]){
                swap(arr[i],arr[rightindex]);
                i=rightindex;
            }else{
                return;
            }
        }
    }
};

int main(){
    heap h;
    h.insert(50);
    h.insert(40);
    h.insert(20);
    h.insert(60);
    h.insert(80);
    h.print();

    h.deleteFromHeap();
    h.print();
    return 0;
}