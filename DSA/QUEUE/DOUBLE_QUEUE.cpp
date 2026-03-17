//queue using arrays
#include <iostream>
using namespace std;

class CircularQueue{

    int* arr;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int n){
        size=n;
        arr = new int[size];
        front=rear=-1;
    }

    bool isempty(){
        if(front==rear){
            return true;
        }
        else{
            return false;
        }
    }

//adding number or int in last in the queue can only add is there is extra space else cant add
bool enqueue(int value){
    // to check whether queue is full
    if( (front==0 && rear==size-1) || (rear==(front-1)%(size-1)) ) {
        cout<<"queue is full"<<endl;
        return false;
    }
    else if(front==-1){//first element to add
        front=rear=0;
        arr[rear]=value;
    }
    else if(rear==size-1 && front!=0){
        rear=0;
        arr[rear]=value;
    }
    else{
        rear++;
    }
    //pushing inside the value
    arr[rear]=value;
    return true;
}

//pop
int dequeue(){
    if(front==-1){// to check queue is empty
        cout<<"queue is empty"<<endl;
        return -1;
    }
    int ans=arr[front];
    arr[front]=-1;
    if (front==rear){
        front=rear=-1;
    }
    else if (front==size-1){
        front=0;//to maintain cyclic nature
    }
    else{
        front++;
    }
    return ans;
}
};

int main(){

}