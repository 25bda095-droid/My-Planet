//linked list 
#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }
};
void printList(Node* head) {
    Node* temp = head; // Start at the beginning
    
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next; // Move to the next node
    }
    cout << "NULL" << endl;
}

int main() {
    // 1. Create individual nodes on the Heap
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);

    // 2. Link them together
    node1->next = node2; // node1 now points to node2
    node2->next = node3; // node2 now points to node3
    // node3->next is already NULL (the end of the list)

    // 3. The "Head"
    Node* head = node1;
    
    printList(head);
}