///////////////////////first in first out/////////////////////
// need two pointers front and rear////////////////////////////
#include <iostream>
// #include <queue>
using namespace std;

// int main(){
//     queue<int> q;
//     q.push(11);
//     q.push(15);
//     q.push(20);

//     cout<<"size of queue is "<<q.size()<<endl;

//     q.pop();
//     q.pop();
//     cout<<"size is "<<q.size()<<endl;

//     if(q.empty()){
//         cout<<"queue is empty"<<endl;
//     }
//     else{
//         cout<<"queue is not empty"<<endl;
//     }
// }








// circular dequeue Doubly ended//////////////////
class Dequeue{
    int* arr;
    int front;
    int rear;
    int size;

    public:
    Dequeue(int n){
        size=n;
        arr=new int[n];
        front=rear=-1;
    }

    bool isempty(){
        if(front==-1){
            return true;
        }
        else{
            return false;
        }
    }

    int push_rear(int d){
        if(isempty()){
            cout<<"is emty so single element is pushed"<<endl;
            front=rear=0;
        }
        else if((front==0 && rear==size-1)||(rear==front-1)){
            cout<<"The queue is full"<<endl;
            return -1;
        }
        else if(front!=0 && rear==size-1){
            rear=0;
        }
        else{
            rear++;
        }
        arr[rear]=d;
        cout<<d<<" is Pushed Successfully"<<endl;
        return 0;
    }

    int push_front(int d){
        if(isempty()){
            front=rear=0;
            cout<<d<<" pushed in front successfully"<<endl;
        }
        else if((front==0 && rear==size-1)||(rear==front-1)){
            cout<<"its already full cant push"<<endl;
            return -1;
        }
        else if(front==0 && rear!=size-1){
            front=size-1;
        }
        else{
            front--;
        }
        arr[front]=d;
        cout<<d<<"is pushed successfully"<<endl;
        }
    };