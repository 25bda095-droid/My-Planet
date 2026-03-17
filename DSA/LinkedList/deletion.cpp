#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a new node
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

// --- INSERTION LOGIC ---

// Adds a node to the very beginning
void insertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

// Adds a node to the very end
void insertAtTail(Node* &head, int d) {
    Node* newNode = new Node(d);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// --- DELETION LOGIC ---

// Case 1: Delete the first node
void deleteAtHead(Node* &head) {
    if (head == NULL) return;

    Node* temp = head;
    head = head->next;
    delete temp; // Free the memory
}

// Case 2: Delete a node at a specific position (0-indexed)
void deleteAtPosition(Node* &head, int position) {
    if (head == NULL) return;

    // If deleting the head
    if (position == 0) {
        deleteAtHead(head);
        return;
    }

    Node* prev = head;
    int count = 0;
    
    // Walk to the node right BEFORE the one we want to delete
    while (prev != NULL && count < position - 1) {
        prev = prev->next;
        count++;
    }

    // Check if position is out of bounds
    if (prev == NULL || prev->next == NULL) {
        cout << "Position out of range!" << endl;
        return;
    }

    Node* nodeToDelete = prev->next;
    prev->next = prev->next->next; // Leapfrog over the target node
    delete nodeToDelete;           // Free memory
}

// --- UTILITY ---

// Print the list from head to tail
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    // Build the list: 10 -> 20 -> 30 -> 40
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);

    cout << "Original List: ";
    printList(head);

    // Delete head (10)
    deleteAtHead(head);
    cout << "After deleting head: ";
    printList(head);

    // Delete at position 1 (which is now 30)
    deleteAtPosition(head, 1);
    cout << "After deleting at position 1: ";
    printList(head);

    return 0;
}