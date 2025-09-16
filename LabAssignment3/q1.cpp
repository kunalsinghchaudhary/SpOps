#include <iostream>
using namespace std;

#define MAX 5
int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stack[++top] = x;
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return;
    }
    cout << "Popped: " << stack[top--] << endl;
}

void isEmpty() {
    if (top == -1) cout << "Stack is Empty\n";
    else cout << "Stack is not Empty\n";
}

void isFull() {
    if (top == MAX - 1) cout << "Stack is Full\n";
    else cout << "Stack is not Full\n";
}

void display() {
    if (top == -1) {
        cout << "Stack is Empty\n";
        return;
    }
    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--) cout << stack[i] << " ";
    cout << endl;
}

void peek() {
    if (top == -1) {
        cout << "Stack is Empty\n";
        return;
    }
    cout << "Top element: " << stack[top] << endl;
}

int main() {
    int choice, val;
    while (true) {
        cout << "\n1.Push\n2.Pop\n3.isEmpty\n4.isFull\n5.Display\n6.Peek\n7.Exit\n";
        cin >> choice;
        switch (choice) {
            case 1: cin >> val; push(val); break;
            case 2: pop(); break;
            case 3: isEmpty(); break;
            case 4: isFull(); break;
            case 5: display(); break;
            case 6: peek(); break;
            case 7: return 0;
            default: cout << "Invalid choice\n";
        }
    }
}