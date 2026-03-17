#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
};

// Top pointer of stack
Node* top = NULL;


// -----------------------------
// PUSH OPERATION
// -----------------------------
void push(int x)
{
    // Create new node
    Node* newNode = new Node();

    newNode->data = x;
    newNode->next = top;  // new node points to previous top

    top = newNode;        // update top

    cout << x << " pushed into stack\n";
}


// -----------------------------
// POP OPERATION
// -----------------------------
void pop()
{
    if(top == NULL)
    {
        cout << "Stack Underflow\n";
        return;
    }

    Node* temp = top;

    cout << temp->data << " popped from stack\n";

    top = top->next;  // move top pointer

    delete temp;      // free memory
}


// -----------------------------
// PEEK / TOP OPERATION
// -----------------------------
int peek()
{
    if(top == NULL)
    {
        cout << "Stack is empty\n";
        return -1;
    }

    return top->data;
}


// -----------------------------
// CHECK EMPTY
// -----------------------------
bool isEmpty()
{
    return (top == NULL);
}


// -----------------------------
// DISPLAY STACK
// -----------------------------
void display()
{
    if(top == NULL)
    {
        cout << "Stack is empty\n";
        return;
    }

    Node* temp = top;

    cout << "Stack elements (top to bottom): ";

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}


int main()
{
    push(10);
    push(20);
    push(30);

    display();

    cout << "Top element: " << peek() << endl;

    pop();

    display();

    return 0;
}