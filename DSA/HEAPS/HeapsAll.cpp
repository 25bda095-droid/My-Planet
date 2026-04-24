// // Heaps -- its a complete binary tree which satisfies the heap property. 

// //It can be of two types:   """Max Heap""" and """Min Heap""". 
// //In Max Heap, for any given node C, if P is a parent node of C, then the key (the value) of P is greater than or equal to the key of C. 
// //In Min Heap, the key of P is less than or equal to the key of C. The node at the "top" of the heap (with no parents) is called the root node.
// // filled from left to right always.
// // Heaps are commonly used to implement priority queues, which are abstract data types that support the following operations:
// // insert an element with a given priority, and remove the element with the highest priority.
#include <iostream>
using namespace std;
class heap{
    public:
    int arr[100];
    int size;

    heap(){
        size=0;
        arr[0]=-1;
    }

    void insert(int val){   // Time complexity is O(log(n))
        size=size+1;
        int index = size;
        arr[index] = val;

        while(index > 1){

            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }

    void deletion(){  // time complexity is O(log(n))
        if(size==0){
            cout<<"Nothing To Delete"<<endl;
            return;
        }
        // step-01:putting last element to 1st position
        arr[1] = arr[size];
        // step2: reducing the size by 1
        size-=1;

        // taking root to its correct position
        int i=1;
        while(i <= size){
            int leftindex=2*i;
            int rightindex=2*i+1;

            if(leftindex <= size && arr[i]<arr[leftindex]){
                swap(arr[i],arr[leftindex]);
                i=leftindex;
            }
            else if(rightindex <= size && arr[i]<arr[rightindex]){
                swap(arr[i],arr[rightindex]);
                i=rightindex;
            }
            else{
                return;
            }
}
    }

    //Heapify Algorithm(Time Complexity is O(log(n)))
    void Heapify(int arr[],int n ,int i){ // array and n is the size of arr and i is the index position
        int largest=i; // just for checking we assign
        int left=2*i; //left
        int right=2*i+1; //right

        if(left <= n && arr[largest]<arr[left]){
            largest=left;
        }
        if(right <= n && arr[largest]<arr[right]){
            largest=right;
        }

        // checking if largest is changed or not if changed swap is required 
        if(i!=largest){
            swap(arr[largest],arr[i]);
            Heapify(arr,n,largest); // now going further after first swap to see if more swap possible or position change possible
        }
    }

    void print(){
        for (int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    //Heap Sort  Time Complexity is (nlog(n));
    void HeapSort(int arr[],int n){
        int size=n;

        while(size > 1){
            // step1: swap
            swap(arr[size],arr[1]);
            //step2: reducing the size
            size--;
        Heapify(arr,size,1);
    };
    }
};


int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();
    // h.deletion();
    // h.print();
    


    int arr[6] = {-1,54,53,55,52,50};
    int n=5;
    cout<<"Printing the array now"<<endl;
    for(int i=1;i<=n;i++){
        cout<< arr[i]<< " ";
    }
    cout<<endl;
    cout<<"heapified is"<<endl;
    for (int i=n/2; i>0;i--){  // in heap the leaf nodes is from (n/2 +1) to n  where n=last index position so we dont have to check leaf nodes...
        h.Heapify(arr,n,i);  // TIme complexity is O(N)
    }
    for(int i=1;i<=n;i++){
        cout<< arr[i]<< " ";
    }
    cout<<endl;

    //heapsort
    h.HeapSort(arr,n);
    for(int i=1;i<=n;i++){
        cout<< arr[i]<< " ";
    };
}
