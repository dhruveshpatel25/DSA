#include<iostream>
using namespace std;

class heap{
    public:
    int arr[1000];
    int size=0;

    heap(){

        //first index of array should be 0
        arr[0]=-1;
        size=0;
    }

    //insertion function
    void insert(int data){

        //increase the size
        size=size+1;

        //last index
        int index=size;
        arr[index]=data;

        if(index>1){

            //get the parent of the node
            int parent=index/2;

            //check if parent is greater or not and if smaller then swap so maximum value goes the top
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
            }else{ //correct position
                return;
            }
        }
    }

    //print the heap
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    //function to delete the node
    void deleteFromHeap(){
        if(size==0){
            cout<<"Heap is Empty";
        }

        //swap the root node with the last leaf node
        arr[1]=arr[size];
        size--;

        //take the node to correct position
        int i=1;
        while(i<size){
            int leftindex=2*i;
            int rightindex=2*i+1;
            
            //check if the left value is in array and check if the left indexed value is greater than if root 
            //if so swap it with left child
            if(leftindex<size && arr[leftindex]>arr[i]){
                swap(arr[i],arr[leftindex]);
                i=leftindex;
            }
            //if so swap it with right child
            else if(rightindex<size && arr[i]<arr[rightindex]){
                swap(arr[i],arr[rightindex]);
                i=rightindex;
            }else{ //it is in correct position
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