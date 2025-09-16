#include <iostream>
using namespace std;

class StackOneQ {
    int q[100];
    int front, rear;
    int size;

public:
    StackOneQ() {
        front = rear = size = 0;
    }

    void push(int x) {
        q[rear++] = x; 
        size++;

        for (int i = 0; i < size - 1; i++) {
            q[rear++] = q[front++];
        }
    }

    int pop() {
        if (size == 0) {
            cout << "Stack is empty\n";
            return -1;
        }
        size--;
        return q[front++];
    }

    int top() {
        if (size == 0) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q[front];
    }

    bool empty() {
        return (size == 0);
    }
};

int main() {
    StackOneQ st;
    st.push(5);
    st.push(15);
    st.push(25);
    cout << "Top: " << st.top() << endl; 
    cout << "Pop: " << st.pop() << endl; 
    cout << "Pop: " << st.pop() << endl; 
    cout << "Top: " << st.top() << endl;
    return 0;
}
