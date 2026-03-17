//queue using arrays
#include <iostream>
using namespace std;

class Queue{

    int* arr;
    int front;
    int rear;
    int size;

public:
    Queue(){
        size=10000;
        arr = new int[size];
        front=0;
        rear=0;
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
void enqueue(int data){
    if(rear==size){
        cout<<"queue is full"<<endl;
    }
    else{
        arr[rear]=data;
        rear++;
    }
}
//agar koi jayega toh pahle starting se jayega so remove in front and start value -1 to that index represent null or empty position
int dequeue(){
    if(isempty()){
        cout<<"its already empty"<<endl;
        return -1;
    }
    else{
        int ans=arr[front];
        arr[front]=-1;
        front++;
        if(front==rear){
            front=0;
            rear=0;
        }
        return ans;
    }
}

int qfront(){
    if(front==rear){
        return -1;
    }
    else{
        return arr[front];
    }
}
};

int main(){
    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    cout<<"Front elements is "<<q.qfront()<<endl;
    q.dequeue();
    cout<<"Front elements is "<<q.qfront()<<endl;
}