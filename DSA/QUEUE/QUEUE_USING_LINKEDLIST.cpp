#include <iostream>
using namespace std;

class Node{
    public:
        Node* next;
        int data;

        Node(int d){
            this->next=NULL;
            this->data=d;
        }
};

void enqueue(Node* &front,Node* &rear,int d){
    Node* temp = new Node(d);
    if(rear==NULL){
        rear=front=temp;
    }
    else{
    rear->next=temp;
    rear=temp;
    }
}

int dequeue(Node* &front,Node* &rear){
    //if its empty
    if(rear==NULL){
        return -1;
    }
    Node* temp=front;
    int ans=temp->data;
    if(rear==front){
        rear=front=NULL;
    }
    else{
    front=temp->next;
    }
    delete temp;
    return ans;
}

int qfront(Node* &front){
    if(front==NULL){
        return -1;
    }
    else{
        return front->data;
    }
}
int qrear(Node* &rear){
    if(rear==NULL) return -1;
    else return rear->data;
}

int main() {
    // Start with a truly empty queue
    Node* front = NULL;
    Node* rear = NULL;

    // Use your functions to add data
    enqueue(front, rear, 10);
    enqueue(front, rear, 20);
    enqueue(front, rear, 30);

    cout << "Front: " << qfront(front) << endl; // 10
    cout << "Rear: " << qrear(rear) << endl;   // 30

    cout << "Dequeued: " << dequeue(front, rear) << endl; // 10
    cout << "New Front: " << qfront(front) << endl;       // 20

    return 0;
}