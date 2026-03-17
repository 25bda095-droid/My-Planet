#include <iostream>
using namespace std;

#define MAX 100   // Maximum size of stack

class Stack {
private:
    int arr[MAX];   // array to store stack elements
    int top;        // index of top element

public:

    // Constructor
    Stack() {
        top = -1;   // stack is initially empty
    }

    // -----------------------------
    // PUSH OPERATION
    // -----------------------------
    void push(int x) {

        // Check for overflow
        if (top == MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }

        top++;           // move top forward
        arr[top] = x;    // insert element

        cout << x << " pushed into stack\n";
    }

    // -----------------------------
    // POP OPERATION
    // -----------------------------
    void pop() {

        // Check for underflow
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }

        cout << arr[top] << " popped from stack\n";
        top--;   // remove element
    }

    // -----------------------------
    // TOP / PEEK OPERATION
    // -----------------------------
    int peek() {

        if (top == -1) {
            cout << "Stack is empty\n";
            return -1;
        }

        return arr[top];
    }

    // -----------------------------
    // CHECK EMPTY
    // -----------------------------
    bool isEmpty() {
        return (top == -1);
    }

    // -----------------------------
    // CHECK SIZE
    // -----------------------------
    int size() {
        return top + 1;
    }

    // -----------------------------
    // DISPLAY STACK
    // -----------------------------
    void display() {

        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack elements (top to bottom): ";

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {

    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    st.display();

    cout << "Top element: " << st.peek() << endl;

    st.pop();

    st.display();

    cout << "Stack size: " << st.size() << endl;

    return 0;
}